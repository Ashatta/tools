#include "motor.h"

#include <QtCore/QDebug>

using namespace trikControl;

void Motor::init(int powerMin, int powerMax, QString const& controlFile)
{
	mControlFile.setFileName(controlFile);
	mPowerMax = powerMax;
	mPowerMin = powerMin;
	mPower = 0;
}

void Motor::setPower(int power)
{
	qDebug() << "Executing setPower command with power = " << power;

	if (power == 0) {
		// Quick hack for motors not stopping properly on middle power value
		powerOff();
		return;
	}

	if (!mControlFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Unbuffered | QIODevice::Text)) {
		qDebug() << "Can't open motor control file " << mControlFile.fileName();
		return;
	}

	if (power > 100) {
		power = 100;
	} else if (power < -100) {
		power = -100;
	}

	mPower = power;

	QString command;

	qreal const powerFactor = static_cast<qreal>(mPowerMax - mPowerMin) / 100;
	command.sprintf("%d\n", static_cast<int>(power * powerFactor + mPowerMin));

	qDebug() << "executing: " << command;

	mControlFile.write(command.toLatin1());
	mControlFile.close();
}

int Motor::power() const
{
	return mPower;
}


void Motor::powerOff()
{
	qDebug() << "Executing powerOff command";

	if (!mControlFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Unbuffered | QIODevice::Text)) {
		qDebug() << "Can't open motor control file " << mControlFile.fileName();
		return;
	}

	mControlFile.write("0");
	mControlFile.close();

	mPower = 0;
}