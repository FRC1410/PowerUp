/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoAccelerateStraight.h"
#include "Robot.h"

AutoAccelerateStraight::AutoAccelerateStraight() {
	Requires(&Robot::cubeclaw);
	Requires(&Robot::drivetrain);
	timer = new frc::Timer();
	record_time = 0;
}

// Called just before this Command runs the first time
void AutoAccelerateStraight::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
	Robot::rotator.ConfigureEncoder();
	Robot::rotator.ResetEncoder();
	stage = 0;
	frc::SmartDashboard::PutString("Running Auto Mode", "Acceleration Working");
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoAccelerateStraight::Execute() {
	//Stage is the current phase of the auto
	//Each stage has different code (e.g. turn, drive forward, operate mechanism)
	//Default is the last phase
	frc::SmartDashboard::PutString("Running Auto Mode", "Acceleration Running");
	frc::SmartDashboard::PutNumber("Timer", timer->Get());
	switch (stage) {
		case 0:
			if (timer->Get() > 1) {
				stage = 1;
				Robot::drivetrain.TankDrive(1.0, 1.0);
				acceleration_distance = Robot::drivetrain.ReturnDrivenInches(3);
			} else {
				Robot::drivetrain.TankDrive((timer->Get()), (timer->Get()));
			}
			break;
		case 1:
			Robot::drivetrain.TankDrive(1.0, 1.0);

			if (Robot::drivetrain.ReturnDrivenInches(3) + acceleration_distance > 90) {
				stage = 2;
				record_time = timer->Get();
			}
			break;
		default:
			if (timer->Get() >= record_time + 1) {
				Robot::drivetrain.TankDrive(0, 0);
				stage = 3;
			}
			else {
				Robot::drivetrain.TankDrive((record_time + 1 - timer->Get()), (record_time + 1 - timer->Get()));
			}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAccelerateStraight::IsFinished() {
	if (stage == 3) {
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoAccelerateStraight::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAccelerateStraight::Interrupted() {

}
