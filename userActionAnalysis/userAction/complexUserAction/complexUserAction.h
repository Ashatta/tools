#pragma once

#include <QtCore/QMap>
#include <QtCore/QStringList>

#include "userAction/baseUserAction/baseUserAction.h"

class ComplexUserAction : public UserAction
{

public:
	ComplexUserAction(QString const &name, QList<UserAction *> userActions);
	~ComplexUserAction();
	QList<UserAction *> userActions();

private:
	QList<UserAction *> mUserActions;
};