/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoRightScaleRightRotateClimber.h"
#include "Robot.h"

AutoRightScaleRightRotateClimber::AutoRightScaleRightRotateClimber() {
	Requires(&Robot::climber);
}

// Called just before this Command runs the first time
void AutoRightScaleRightRotateClimber::Initialize() {
	Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoRightScaleRightRotateClimber::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightScaleRightRotateClimber::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoRightScaleRightRotateClimber::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightScaleRightRotateClimber::Interrupted() {

}
