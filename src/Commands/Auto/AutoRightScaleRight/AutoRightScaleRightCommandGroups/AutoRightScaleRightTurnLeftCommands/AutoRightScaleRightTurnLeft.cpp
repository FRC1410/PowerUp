/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoRightScaleRightTurnLeft.h"
#include "Robot.h"

AutoRightScaleRightTurnLeft::AutoRightScaleRightTurnLeft() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoRightScaleRightTurnLeft::Initialize() {
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoRightScaleRightTurnLeft::Execute() {
	Robot::drivetrain.SmartDashboardnavX();
	Robot::drivetrain.TankDrive(0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightScaleRightTurnLeft::IsFinished() {
	if (Robot::drivetrain.SmartDashboardnavX() <= -90) {
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoRightScaleRightTurnLeft::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightScaleRightTurnLeft::Interrupted() {

}