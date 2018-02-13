#include "Commands/Auto/AutoTimedDrive.h"
#include "Commands/Auto/AutoEncodeDrive.h"
#include "Commands/Auto/NavxTest.h"
#include "Commands/Auto/AutoDoNothing.h"

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
	//frc::SmartDashboard::PutString("Auto", "Encoders Drive Forward");
	frc::SmartDashboard::PutString("Auto L", "NavX Test");
	frc::SmartDashboard::PutString("Auto R", "Auto Encode Drive");
	frc::SmartDashboard::PutString("Auto other", "Auto Do Nothing");
}

void Robot::AutonomousInit() {
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	frc::SmartDashboard::PutString("Game Data", gameData);

	if (gameData[0] == 'L'){
		auto_command.reset(new NavxTest);
	}else if (gameData[0] == 'R'){
		auto_command.reset(new AutoEncodeDrive);
	}else{
		auto_command.reset(new AutoDoNothing);
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
