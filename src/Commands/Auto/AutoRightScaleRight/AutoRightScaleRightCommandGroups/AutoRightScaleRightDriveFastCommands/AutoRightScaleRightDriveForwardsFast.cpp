/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoRightScaleRightDriveForwardsFast.h"
#include "Robot.h"

AutoRightScaleRightDriveForwardsFast::AutoRightScaleRightDriveForwardsFast() {
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoRightScaleRightDriveForwardsFast::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoRightScaleRightDriveForwardsFast::Execute() {
	Robot::drivetrain.TankDrive(-1, -1);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightScaleRightDriveForwardsFast::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 229){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoRightScaleRightDriveForwardsFast::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightScaleRightDriveForwardsFast::Interrupted() {

}
