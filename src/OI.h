#pragma once

#include <Buttons/JoystickButton.h>
#include <Joystick.h>
#include "RobotMap.h"

class OI {
public:
	OI();
	double InputShape(double userValue, int axis, int controller);
	frc::Joystick& GetDriveJoystick();
	void PassDeadzone(double passedDeadzone);
	double GetDriveAxis(int axis);
	double GetDriveDirection(double x, double y);
	double ApplyExponent(double input, int exponent);
	double GetOperatorAxis(int axis);
	double GetOperatorButton(int button);
	double GetDriverButton(int button);

private:
	double deadzone = default_deadzone;
	double rawMagnitude = 0;
	frc::Joystick driver_controller{0};
	frc::Joystick operator_controller{1};
	frc::JoystickButton * ClawWheelsOut;
	frc::JoystickButton * ClawWheelsIn;
	frc::JoystickButton * ClawWheelsShoot;
	frc::JoystickButton * ClawSolenoid;
	frc::JoystickButton * ClimbingSolenoid;
	frc::JoystickButton * ClimbingRotatorSolenoid;
};
