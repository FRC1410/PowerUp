#include "Commands/Auto/AutoTimedDrive.h"
#include "Commands/Auto/AutoEncodeDrive.h"
#include "Commands/Auto/NavxTest.h"
#include "Commands/Auto/AutoDoNothing.h"
#include "Commands/Auto/AutoStraightSwitch.h"
#include "Commands/Auto/AutoCenterScoreSwitchLeft.h"
#include "Commands/Auto/AutoCrossBaseline.h"
#include "Commands/Auto/AutoLeftSwitchLeft.h"

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
	/*frc::SmartDashboard::PutString("Auto 0", "Forward Only");
	frc::SmartDashboard::PutString("Auto 1", "Right - score right");
	frc::SmartDashboard::PutString("Auto 2", "Left - score left");
	frc::SmartDashboard::PutString("Auto 3", "Right - score both");
	frc::SmartDashboard::PutNumber("Auto Selection", 0);*/
	/*auto_string.AddDefault("driveforward", "driveforward");
	auto_string.AddObject("scoreright", "scoreright");
	auto_string.AddObject("scoreleft", "scoreleft");
	frc::SmartDashboard::PutData("Auto Modes", &auto_string);*/
}

void Robot::AutonomousInit() {
	//Reverse is for rotating it up (rotating outside frame perimeter)
	Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kReverse);
	//Forward is closed
	Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kReverse);
	//Reverse is closing
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);

	/*mode = frc::SmartDashboard::GetNumber("Auto Selection", 5);
	frc::SmartDashboard::PutNumber("Auto Gotten", mode);
	*/

	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	frc::SmartDashboard::PutString("Game Data", gameData);
	/*chosen_auto = (char *)frc::SmartDashboard::GetData("Auto Modes");
	frc::SmartDashboard::PutString("Chosen Auto", chosen_auto);
	if (chosen_auto == "driveforward"){
		auto_command.reset(new AutoCrossBaseline);
	} else if (chosen_auto == "scoreright"){
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
	} else if (chosen_auto == "scoreleft"){
		if (gameData[0] == 'L'){
			auto_command.reset(new AutoLeftSwitchLeft);
			frc::SmartDashboard::PutString("Running Auto Mode", "Switch Left");
		} else if (gameData [0] == 'R') {
			auto_command.reset(new AutoCrossBaseline);
			frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
		} else {
			auto_command.reset(new AutoDoNothing);
			frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing");
		}
	} else {
		auto_command.reset(new AutoCrossBaseline);
		frc::SmartDashboard::PutString("Auto working", "NO");
	}*/
	//KEY
	/* 0 - Drive Forwards
	 * 1 - Right - score right
	 * 2 - left - score left
	 * 3 - Right - score both
	 * Default - Do nothings
	 */
	/*switch (mode) {
		case 0:
			auto_command.reset(new AutoCrossBaseline);
			frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
			break;
		case 1:
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
		case 2:
			if (gameData[0] == 'L'){
				auto_command.reset(new AutoLeftSwitchLeft);
				frc::SmartDashboard::PutString("Running Auto Mode", "Switch Left");
			} else if (gameData [0] == 'R') {
				auto_command.reset(new AutoCrossBaseline);
				frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
			} else {
				auto_command.reset(new AutoDoNothing);
				frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing");
			}
			break;
		case 3:
			if (gameData[0] == 'L'){
				auto_command.reset(new AutoCenterScoreSwitchLeft);
				frc::SmartDashboard::PutString("Running Auto Mode", "Right score left");
			} else if (gameData[0] == 'R'){
				auto_command.reset(new AutoStraightSwitch);
				frc::SmartDashboard::PutString("Running Auto Mode", "Straight Switch");
			} else{
				auto_command.reset(new AutoDoNothing);
				frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing");
			}
			break;
		default:
			auto_command.reset(new AutoCrossBaseline);
			frc::SmartDashboard::PutString("Running Auto Mode", "Cross Baseline");
	}*/

	//DRIVE FORWARD
	/*auto_command.reset(new AutoCrossBaseline);
	frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");*/

	//SCORE LEFT
	if (gameData[0] == 'L'){
		auto_command.reset(new AutoLeftSwitchLeft);
		frc::SmartDashboard::PutString("Running Auto Mode", "Switch Left");
	} else if (gameData [0] == 'R') {
		auto_command.reset(new AutoCrossBaseline);
		frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
	} else {
		auto_command.reset(new AutoDoNothing);
		frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing");
	}

	//SCORE RIGHT
	/*if (gameData[0] == 'L') {
		auto_command.reset(new AutoCrossBaseline);
		frc::SmartDashboard::PutString("Running Auto Mode", "Drive Forwards");
	} else if (gameData[0] == 'R') {
		auto_command.reset(new AutoStraightSwitch);
		frc::SmartDashboard::PutString("Running Auto Mode", "Straight Switch");
	} else {
		auto_command.reset(new AutoDoNothing);
		frc::SmartDashboard::PutString("Running Auto Mode", "Do Nothing");
	}*/

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
