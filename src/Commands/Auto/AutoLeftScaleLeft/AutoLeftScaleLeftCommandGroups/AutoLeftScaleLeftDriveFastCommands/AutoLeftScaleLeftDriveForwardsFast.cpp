/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftDriveForwardsFast.h"
#include "Robot.h"

AutoLeftScaleLeftDriveForwardsFast::AutoLeftScaleLeftDriveForwardsFast() {
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoLeftScaleLeftDriveForwardsFast::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScaleLeftDriveForwardsFast::Execute() {
	Robot::drivetrain.TankDrive(-1, -1);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScaleLeftDriveForwardsFast::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 229){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScaleLeftDriveForwardsFast::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScaleLeftDriveForwardsFast::Interrupted() {

}