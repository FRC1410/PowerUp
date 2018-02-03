#include "Commands/Auto/AutoTimedDrive.h"
#include "Commands/Auto/AutoEncodeDrive.h"

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
	//auto_choice.AddDefault("Timed Drive Forward (default)", new AutoTimedDrive());
	//auto_choice.AddObject("Encoders Drive Forward", new AutoEncodeDrive());
	//auto_choice.AddObject("Encoders Drive Forward", new AutoEncodeDrive());
	//auto_choice.AddDefault("Timed Drive Forward", new AutoTimedDrive());
	std::cin >> choose;
	//frc::SmartDashboard::PutData("Choose Auto:", 0);
	//frc::SmartDashboard::PutData("Auto Modes", &auto_choice);
}

void Robot::AutonomousInit() {
	//auto_command.reset(auto_choice.GetSelected());
	//frc::SmartDashboard::PutData("rigged", frc::SmartDashboard::GetData("Choose Auto:"));
	//std::string autoSelected = frc::SmartDashboard::GetString("Auto Modes", "Default");
	if (choose == 0) {
		auto_command.reset(new AutoTimedDrive());
	} else {
		auto_command.reset(new AutoEncodeDrive());
	}

	if (auto_command.get() != nullptr) {
		auto_command->Start();
	}
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	/*if (auto_command != nullptr) {
			auto_command->Cancel();
			}*/
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
