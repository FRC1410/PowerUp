/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/TeleOp/TeleOpClawArms.h>
#include "../../Robot.h"

TeleOpClawArms::TeleOpClawArms() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void TeleOpClawArms::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TeleOpClawArms::Execute() {
	if(Robot::oi.GetOperatorButton(claw_arms_button)) {
		if (wasPressed == false) {
			if (toggle == false) {
				frc::SmartDashboard::PutString("Claw Arms", "Reverse");
				Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kReverse);
				toggle = true;
			} else {
				frc::SmartDashboard::PutString("Claw Arms", "Forward");
				Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
				toggle = false;
			}
		}
		wasPressed = true;
	} else {
		wasPressed = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpClawArms::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpClawArms::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpClawArms::Interrupted() {
}
