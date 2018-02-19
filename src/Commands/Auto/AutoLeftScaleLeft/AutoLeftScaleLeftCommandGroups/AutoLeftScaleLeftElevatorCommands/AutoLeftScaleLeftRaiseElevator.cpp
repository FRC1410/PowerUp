/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftRaiseElevator.h"
#include "Robot.h"

AutoLeftScaleLeftRaiseElevator::AutoLeftScaleLeftRaiseElevator() {
	Requires(&Robot::elevation);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoLeftScaleLeftRaiseElevator::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScaleLeftRaiseElevator::Execute() {
	Robot::elevation.ElevationWheel(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScaleLeftRaiseElevator::IsFinished() {
	if (timer->Get() >= 1.7)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScaleLeftRaiseElevator::End() {
	Robot::elevation.ElevationWheel(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScaleLeftRaiseElevator::Interrupted() {

}
