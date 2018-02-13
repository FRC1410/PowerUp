#pragma once

#include <Buttons/JoystickButton.h>
#include <Joystick.h>


class OI {
public:
	OI();
	float InputShape(float userValue);
	frc::Joystick& GetDriveJoystick();
	double GetDriveAxis(int axis);
	double GetOperatorAxis(int axis);
	double GetOperatorButton(int button);

private:
	frc::Joystick driver_controller{0};
	frc::Joystick operator_controller{1};
	frc::JoystickButton * ClawWheelsOut;
	frc::JoystickButton * ClawWheelsIn;
	frc::JoystickButton * ClawWheelsShoot;
	frc::JoystickButton * ClawSolenoid;
	frc::JoystickButton * ClimbingSolenoid;
	frc::JoystickButton * ClimbingRotatorSolenoid;
};
