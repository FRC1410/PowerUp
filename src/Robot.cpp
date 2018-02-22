#include "Commands/Auto/AutoTimedDrive.h"
#include "Commands/Auto/AutoEncodeDrive.h"
#include "Commands/Auto/NavxTest.h"
#include "Commands/Auto/AutoDoNothing.h"
#include "Commands/Auto/AutoStraightSwitch.h"
#include "Commands/Auto/AutoCenterScoreSwitchLeft.h"
#include "Commands/Auto/AutoCrossBaseline.h"

#include "Robot.h"

#include <iostream>

#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include "OI.h"
#include "Subsystems/DriveTrain.h"

DriveTrain Robot::drivetrain;
OI Robot::oi;
CubeClaw Robot::cubeclaw;
Elevation Robot::elevation;
Rotator Robot::rotator;
Climber Robot::climber;

void Robot::RobotInit() {
	frc::SmartDashboard::PutString("Auto 0", "Forward Only");
	frc::SmartDashboard::PutString("Auto 1", "Left - score left");
	frc::SmartDashboard::PutNumber("Auto Selection", 0);
}

void Robot::AutonomousInit() {
	//Reverse is for rotating it up (rotating outside frame perimeter)
	Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kReverse);
	//Forward is closed
	Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kReverse);
	//Reverse is closing
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
	mode = frc::SmartDashboard::GetNumber("Auto Selection", 36);
	frc::SmartDashboard::PutNumber("Auto Gotten", mode);
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	frc::SmartDashboard::PutString("Game Data", gameData);
	//KEY
	/* 0 - Drive Forwards
	 * 1 - Left   Starting Position, prioritize switch
	 * 2 - Middle Starting Position, switch
	 * 3 - Right  Starting Position, prioritize switch
	 * 4 - Left   Starting Position, scale only
	 * 5 - Right  Starting Position, scale Only
	 * 6 - Left   Starting Position, no scale
	 * 7 - Right  Starting Position, no scale
	 */
	switch (mode) {
		case 0:
			if (gameData[0] == 'L') {
				auto_command.reset(new AutoCrossBaseline);
				frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
			} else if (gameData[0] == 'R') {
				auto_command.reset(new AutoStraightSwitch);
				frc::SmartDashboard::PutString("Running Auto Mode", "Straight Switch");
			} else {
				auto_command.reset(new AutoDoNothing);
				frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing");
			}
			break;
		case 1:
			auto_command.reset(new AutoCrossBaseline);
			frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
			break;
		case 2:
			auto_command.reset(new AutoStraightSwitch);
			frc::SmartDashboard::PutString("Running Auto Mode", "Straight Switch");
			break;
		default:
			auto_command.reset(new AutoDoNothing);
			frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing");
	}
	if (auto_command.get() != nullptr) {
		auto_command->Start();
	}
}

void Robot::AutonomousPeriodic() {
	if (auto_command.get() != nullptr){
		frc::Scheduler::GetInstance()->Run();
	}
}

void Robot::TeleopInit() {
	if (auto_command != nullptr) {
		auto_command->Cancel();
	}
	drivetrain.ResetEncodersandNavX();
	std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
//	frc::SmartDashboard::PutString("Game Data", gameData);
//	frc::Scheduler::GetInstance()->Run();
}

/**
 * Log interesting values to the SmartDashboard.
 */
void Robot::Log() {

}

START_ROBOT_CLASS(Robot)
