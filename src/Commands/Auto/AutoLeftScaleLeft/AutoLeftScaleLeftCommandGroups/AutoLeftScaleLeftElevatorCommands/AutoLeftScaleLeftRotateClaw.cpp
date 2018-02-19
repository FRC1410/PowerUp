/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftRotateClaw.h"
#include "Robot.h"

AutoLeftScaleLeftRotateClaw::AutoLeftScaleLeftRotateClaw() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::rotator);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoLeftScaleLeftRotateClaw::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScaleLeftRotateClaw::Execute() {
	Robot::rotator.RotateClaw(0.6);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScaleLeftRotateClaw::IsFinished() {
	if (timer->Get()>=0.4)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScaleLeftRotateClaw::End() {
	Robot::rotator.RotateClaw(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScaleLeftRotateClaw::Interrupted() {

}
