/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftDriveForwardsSlow.h"
#include "Robot.h"

AutoLeftScaleLeftDriveForwardsSlow::AutoLeftScaleLeftDriveForwardsSlow() {
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoLeftScaleLeftDriveForwardsSlow::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScaleLeftDriveForwardsSlow::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScaleLeftDriveForwardsSlow::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 30){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScaleLeftDriveForwardsSlow::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScaleLeftDriveForwardsSlow::Interrupted() {

}
