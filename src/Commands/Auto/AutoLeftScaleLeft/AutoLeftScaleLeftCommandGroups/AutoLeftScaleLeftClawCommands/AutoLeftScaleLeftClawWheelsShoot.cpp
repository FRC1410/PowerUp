/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftScaleLeftClawWheelsShoot.h"
#include "Robot.h"

AutoLeftScaleLeftClawWheelsShoot::AutoLeftScaleLeftClawWheelsShoot() {
	Requires(&Robot::cubeclaw);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoLeftScaleLeftClawWheelsShoot::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScaleLeftClawWheelsShoot::Execute() {
	Robot::cubeclaw.ClawWheels(1.0, -1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScaleLeftClawWheelsShoot::IsFinished() {
	if (timer->Get() >= 0.7)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScaleLeftClawWheelsShoot::End() {
	Robot::cubeclaw.ClawWheels(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScaleLeftClawWheelsShoot::Interrupted() {

}
