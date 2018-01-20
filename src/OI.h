/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

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
	frc::JoystickButton * ClawSolenoid;
};
