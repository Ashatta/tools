#include "userAction/complexUserAction/complexUserActionGenerator.h"

#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>

ComplexUserActionGenerator::ComplexUserActionGenerator(const BaseUserActionList &baseUserActionList
		, ComplexUserActionList const &complexUserActionList, const ComplexUserActionList &scenarios)
{
	if (mComplexActionsDir.current().cdUp()) {
		if (mComplexActionsDir.cd("userAction/complexUserAction/XMLcomplexUserActions")) {
			int const count = mComplexActionsDir.count();
			mComplexActionsCount = count;
		}
		else {
			mComplexActionsCount = 0;
		}
	}
	else {
		mComplexActionsCount = 0;
	}

	if (mScenariosDir.current().cdUp()) {
		if (mScenariosDir.cd("userAction/userScenario")) {
			int const count = mScenariosDir.count();
			mScenariosCount = count;
		}
		else {
			mScenariosCount = 0;
		}
	}
	else {
		mScenariosCount = 0;
	}
	mBaseUserActions << baseUserActionList;
	mComplexUserActions << complexUserActionList;
	mScenarios << scenarios;
}


ComplexUserActionGenerator::~ComplexUserActionGenerator()
{

}

void ComplexUserActionGenerator::generateComplexAction(const QString &name, const QList<RuleElement *> &userActions)
{
	mComplexActionsCount++;
	mProperties.clear();
	mCustomProperties.clear();
	mUserActions.clear();

	QString const documentName = "complexUserAction" + QString::number(mComplexActionsCount);
	QDomDocument document(documentName);
	QDomElement complexUserAction = document.createElement("mainComplexUserAction");
	complexUserAction.setAttribute("name", name);
	document.appendChild(complexUserAction);

	for (RuleElement *userAction: userActions) {
		addComplexAction(userAction, document, complexUserAction);
	}

	QString const dir = mComplexActionsDir.absolutePath();
	if (!QDir(dir).exists()) {
		QDir(dir).mkpath(dir);
	}

	QFile file(dir + "/" + documentName + ".xml");
	if (file.open(QFile::WriteOnly | QFile::Truncate)) {
		QTextStream stream(&file);
		document.save(stream, 1);
	}
	file.close();
	QMessageBox::information(nullptr, QString::fromUtf8("Сохранение")
							 , QString::fromUtf8("Составное действие успешно сохранено."),
							 QMessageBox::Ok);
	ComplexUserAction *newComplexUserAction = new ComplexUserAction(name, mUserActions);
	mComplexUserActions << newComplexUserAction;
	emit newComplexActionCreated(newComplexUserAction);
}

void ComplexUserActionGenerator::generateScenario(const QString &name, const QList<RuleElement *> &userActions, QMap<QString, ActionStatus> const &actionStatus)
{
	mScenariosCount++;
	mProperties.clear();
	mCustomProperties.clear();
	mUserActions.clear();
	mActionStatus.clear();

	QString const documentName = "userScenario" + QString::number(mScenariosCount);
	QDomDocument document(documentName);
	QDomElement scenario = document.createElement("scenario");
	scenario.setAttribute("name", name);
	document.appendChild(scenario);

	for (RuleElement *userAction: userActions) {
		addComplexAction(userAction, document, scenario);
	}
	QDomElement actionStatusElement = document.createElement("actionStatus");
	QMap<QString, ActionStatus>::const_iterator i = actionStatus.constBegin();
	while (i != actionStatus.constEnd()) {
		QDomElement baseActionStatus = document.createElement("baseActionStatus");
		baseActionStatus.setAttribute("name", i.key());
		QString value;
		if (i.value() == ActionStatus::good) {
			value = "good";
		}
		else if (i.value() == ActionStatus::neutral) {
			value = "neutral";
		}
		else if (i.value() == ActionStatus::bad) {
			value = "bad";
		}
		baseActionStatus.setAttribute("value", value);
		actionStatusElement.appendChild(baseActionStatus);
		++i;
	}
	scenario.appendChild(actionStatusElement);

	QString const dir = mScenariosDir.absolutePath();
	if (!QDir(dir).exists()) {
		QDir(dir).mkpath(dir);
	}

	QFile file(dir + "/" + documentName + ".xml");
	if (file.open(QFile::WriteOnly | QFile::Truncate)) {
		QTextStream stream(&file);
		document.save(stream, 1);
	}
	file.close();
	QMessageBox::information(nullptr, QString::fromUtf8("Сохранение")
							 , QString::fromUtf8("Сценарий успешно сохранен."),
							 QMessageBox::Ok);
	ComplexUserAction *newScenario = new ComplexUserAction(name, mUserActions);
	newScenario->setUserActionsStatus(actionStatus);
	mScenarios << newScenario;
	emit newScenarioCreated(newScenario);
}

QDomElement ComplexUserActionGenerator::userActionElement(RuleElement *userAction, QDomDocument &document, QList<UserAction *> &userActionList)
{
	if (userAction->isRedTapeInstruction()) {
		return redTapeInstructionElement(userAction->content(), document, userActionList);
	}
	if (userAction->isBaseAction()) {
		return baseUserActionElement(userAction, document, userActionList);
	}

	QDomElement complexUserActionElement = document.createElement("complexUserAction");
	QList<UserAction *> complexUserActionList;
	QString const name = userAction->content();
	complexUserActionElement.setAttribute("name", name);
	complexUserActionElement.setAttribute("repeatCount", (userAction->repeatCount() == 1) ? "1" : "2");
	complexUserActionElement.setAttribute("isKeyAction", userAction->isKeyAction() ? "true" : "false");
	for (RuleElement *userActionFromList: userAction->list()) {
		complexUserActionElement.appendChild(userActionElement(userActionFromList, document, complexUserActionList));
	}
	ComplexUserAction *complexUserAction = new ComplexUserAction(name, complexUserActionList);
	complexUserAction->setRepeatCount(userAction->repeatCount());
	complexUserAction->setIsKeyAction(userAction->isKeyAction());
	userActionList.append(complexUserAction);
	return complexUserActionElement;
}

QDomElement ComplexUserActionGenerator::baseUserActionElement(RuleElement *userAction, QDomDocument &document, QList<UserAction *> &userActionList)
{
	QDomElement baseUserActionElement = document.createElement("baseUserAction");
	QStringList const userActionNameAndProperties = userAction->content().split(" — ", QString::SkipEmptyParts);
		if (userActionNameAndProperties.length() != 2) {
			return QDomElement();
		}
		QString const userActionName = userActionNameAndProperties.at(0);
		baseUserActionElement.setAttribute("name", userActionName);

		QDomElement repeatCount = document.createElement("RepeatCount");
		QDomText repeatCountValue = document.createTextNode((userAction->repeatCount() == 1) ? "1" : "2");
		repeatCount.appendChild(repeatCountValue);
		baseUserActionElement.appendChild(repeatCount);

		QDomElement isKeyAction = document.createElement("IsKeyAction");
		QDomText isKeyActionValue = document.createTextNode((userAction->isKeyAction()) ? "true" : "false");
		isKeyAction.appendChild(isKeyActionValue);
		baseUserActionElement.appendChild(isKeyAction);

		QDomElement duration = document.createElement("Duration");
		QDomElement from = document.createElement("From");
		QDomText fromValue = document.createTextNode(QString::number(userAction->duration()->from()));
		from.appendChild(fromValue);
		duration.appendChild(from);
		QDomElement to = document.createElement("To");
		QDomText toValue = document.createTextNode(QString::number(userAction->duration()->to()));
		to.appendChild(toValue);
		duration.appendChild(to);
		baseUserActionElement.appendChild(duration);

		BaseUserAction *baseUserActionFromList = mBaseUserActions.baseUserActionByName(userActionName);
		if (baseUserActionFromList != nullptr) {

			BaseUserAction *baseUserAction = new BaseUserAction(baseUserActionFromList->userActionName(), baseUserActionFromList->actionProperties());

			baseUserAction->setRepeatCount(userAction->repeatCount());
			baseUserAction->setIsKeyAction(userAction->isKeyAction());
			baseUserAction->setDuration(userAction->duration()->from(), userAction->duration()->to());

			QString const userActionProperties = userActionNameAndProperties.at(1);
			QMap<QString, QString> properties = userActionPropertiesMap(userActionProperties);

			QMap<QString, QString>::const_iterator i = properties.constBegin();
			while (i != properties.constEnd()) {
				QString const propertyName = i.key();
				QString const propertyValue = i.value();
				if (propertyValue == QString::fromUtf8("<параметр>")) {
					QDomElement property = document.createElement("flexibleProperty");
					property.setAttribute("name", propertyName);
					property.setAttribute("value", "?");

					QStringList const propertyValues = mBaseUserActions.propertyValuesByName(userActionName, propertyName);
					mProperties.insert(propertyName, propertyValues);

					baseUserActionElement.appendChild(property);
				}
				else {
					QDomElement customProperty = document.createElement("customProperty");
					customProperty.setAttribute("name", propertyName);
					customProperty.setAttribute("value", propertyValue);

					mCustomProperties.insert(propertyName, propertyValue);
					baseUserAction->setUserActionProperty(propertyName, propertyValue);

					baseUserActionElement.appendChild(customProperty);
				}
				++i;
			}
			userActionList.append(baseUserAction);
		}
		else {
			qDebug() << "base action was't unique or has't found at all.";
		}
		return baseUserActionElement;
}

QDomElement ComplexUserActionGenerator::redTapeInstructionElement(const QString &instructionName, QDomDocument &document, QList<UserAction *> &userActionList)
{
	QDomElement redTapeInstructionElement = document.createElement("redTapeInstruction");
	redTapeInstructionElement.setAttribute("name", instructionName);
	UserAction *redTapeInstruction = new UserAction(instructionName);
	userActionList.append(redTapeInstruction);
	return redTapeInstructionElement;
}

void ComplexUserActionGenerator::addComplexAction(RuleElement *userAction, QDomDocument &document, QDomElement &complexUserActionElement)
{
	complexUserActionElement.appendChild(userActionElement(userAction, document, mUserActions));
}

QMap<QString, QString> ComplexUserActionGenerator::userActionPropertiesMap(const QString &userActionProperties)
{
	QStringList const properties = userActionProperties.split("|", QString::SkipEmptyParts);
	QMap<QString, QString> userActionPropertiesMap;
	for (const QString property: properties) {
		QStringList const propertyNameValue = property.split(": ", QString::SkipEmptyParts);
		if (propertyNameValue.length() != 2) {
			continue;
		}
		QString const propertyName = propertyNameValue.at(0);
		QString const propertyValue = propertyNameValue.at(1);
		userActionPropertiesMap.insert(propertyName, propertyValue);
	}
	return userActionPropertiesMap;
}
