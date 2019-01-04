/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoStraightSwitch.h"
#include "Robot.h"

AutoStraightSwitch::AutoStraightSwitch() {
	Requires(&Robot::cubeclaw);
	Requires(&Robot::drivetrain);
	Requires(&Robot::elevation);
	Requires(&Robot::rotator);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoStraightSwitch::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
	Robot::rotator.ConfigureEncoder();
	Robot::rotator.ResetEncoder();
	stage = 0;
}

// Called repeatedly when this Command is scheduled to run
void AutoStraightSwitch::Execute() {

	//Stage is the current phase of the auto
	//Each stage has different code (e.g. turn, drive forward, operate mechanism)
	//Default is the last phase

	switch (stage) {
		case 0:
			Robot::drivetrain.TankDrive(0.5, 0.5);

			if (Robot::drivetrain.ReturnDrivenInches(3) >= 108) {
				Robot::drivetrain.TankDrive(0, 0);
				stage = 1;
				timer->Start();
			}
			break;
		default:
			if (timer->Get() < 1.7) {
				Robot::elevation.ElevationWheel(-1.0);
			} else {
				Robot::elevation.ElevationWheel(0);
			}
			if (Robot::rotator.ReturnRotatorAngle() > -100) {
				Robot::rotator.RotateClaw(-1.0);
			} else {
				Robot::rotator.RotateClaw(0);
			}

			if (Robot::rotator.ReturnRotatorAngle() <= -100 && timer->Get() >= 1.7) {
				stage = 2;
				Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kReverse);
			}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoStraightSwitch::IsFinished() {
	if (stage == 2) {
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoStraightSwitch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoStraightSwitch::Interrupted() {

}
