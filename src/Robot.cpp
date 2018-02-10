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
	// Show what command your subsystem is running on the SmartDashboard
	//frc::SmartDashboard::PutString("Auto", "Encoders Drive Forward");
	//frc::SmartDashboard::PutString("Auto", "NavX Test");
	/*auto_choice.AddDefault("NavX Test (default)", new NavxTest);
	auto_choice.AddObject("Encoders Drive Forward", new AutoEncodeDrive);
	auto_choice.AddObject("Timed Drive Forward", new AutoTimedDrive);
	frc::SmartDashboard::PutData("Auto Chooser", &auto_choice);*/
	//auto_string.AddDefault("Timed Drive Forward", 0);
	//auto_string.AddObject()
}

void Robot::AutonomousInit() {
	gameData = DriverStation::GetInstance().GetGameSpecificMessage();
	if (gameData[0]== 'L'){
		auto_command.reset(new AutoTimedDrive);
	}
	else if (gameData[0] == 'R'){
		auto_command.reset(new NavxTest);
	}
	else{
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
	std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

/**
 * Log interesting values to the SmartDashboard.
 */
void Robot::Log() {

}

START_ROBOT_CLASS(Robot)
