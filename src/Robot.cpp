#include "Commands/Auto/AutoTimedDrive.h"
#include "Commands/Auto/AutoEncodeDrive.h"
#include "Commands/Auto/NavxTest.h"
#include "Commands/Auto/AutoDoNothing.h"

#include "Commands/Auto/AutoStraightSwitch/AutoStraightSwitch.h"
#include "Commands/Auto/AutoCenterScoreSwitchRight/AutoCenterScoreSwitchRight.h"
#include "Commands/Auto/AutoLeftScoreSwitchLeft/AutoLeftScoreSwitchLeft.h"
#include "Commands/Auto/AutoRightScoreSwitchRight/AutoRightScoreSwitchRight.h"
#include "Commands/Auto/AutoCrossBaseline/AutoCrossBaseline.h"

#include "Robot.h"

#include <iostream>

#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
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
	Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kReverse);
	Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kReverse);
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
	mode = frc::SmartDashboard::GetNumber("Auto Selection", 5);
	frc::SmartDashboard::PutNumber("Auto Gotten", mode);
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	frc::SmartDashboard::PutString("Game Data", gameData);
	//KEY
	frc::SmartDashboard::PutString("Auto Mode 0", "Drive Forwards");
	frc::SmartDashboard::PutString("Auto Mode 1", "Left Position");
	frc::SmartDashboard::PutString("Auto Mode 2", "Right Position");
	frc::SmartDashboard::PutString("Auto Mode 3", "Straight Switch");
	frc::SmartDashboard::PutString("Auto Mode 4", "Center Position");
	frc::SmartDashboard::PutString("Default", "Do Nothing");
	switch (mode) {
		case 0:
			auto_command.reset(new AutoCrossBaseline);
			frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
			break;
		case 1:
			if (gameData[0] == 'L') {
				auto_command.reset(new AutoLeftScoreSwitchLeft);
				frc::SmartDashboard::PutString("Running Auto Mode", "Switch End Score (left side)");
			} else if (gameData[0] == 'R') {
				auto_command.reset(new AutoCrossBaseline);
				frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards (left side)");
			} else {
				auto_command.reset(new AutoDoNothing);
				frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing (left side)");
			}
			break;
		case 2:
			if (gameData[0] == 'R') {
				auto_command.reset(new AutoRightScoreSwitchRight);
				frc::SmartDashboard::PutString("Running Auto Mode", "Switch End Score (right side)");
			} else if (gameData[0] == 'L') {
				auto_command.reset(new AutoCrossBaseline);
				frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards (right side)");
			} else {
				auto_command.reset(new AutoDoNothing);
				frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing (right side)");
			}
			break;
		case 3:
			auto_command.reset(new AutoStraightSwitch);
			frc::SmartDashboard::PutString("Running Auto Mode", "Straight Switch");
			break;
		case 4:
			auto_command.reset(new AutoCenterScoreSwitchRight);
			frc::SmartDashboard::PutString("Running Auto Mode", "Switch Right (center)");
			break;
		case 5:
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
