/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MeasureEncoders.h"
#include "Robot.h"

MeasureEncoders::MeasureEncoders() {
	Requires(&Robot::drivetrain);
	timer = new frc::Timer();
	estimated_distance = 0;
}

// Called just before this Command runs the first time
void MeasureEncoders::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void MeasureEncoders::Execute() {
	Robot::drivetrain.ReturnDrivenInches(3);
	estimated_distance+=(Robot::drivetrain.ReturnVelocity(3) / 50);
	//Robot runs at 50Hz

	SmartDashboard::PutNumber("Velocity Position Estimation", estimated_distance);
}

// Make this return true when this Command no longer needs to run execute()
bool MeasureEncoders::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MeasureEncoders::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MeasureEncoders::Interrupted() {

}
