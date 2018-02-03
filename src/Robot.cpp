//#include "Commands/Auto/AutoTimedDrive.h"
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

void Robot::RobotInit() {
	// Show what command your subsystem is running on the SmartDashboard
	//auto_choice.AddObject("Encoders Drive Forward", new AutoEncodeDrive());
	//auto_command.reset(new AutoEncodeDrive());
	/*auto_choice.AddDefault("Encoders Drive Forward (default)", new AutoEncodeDrive());
	auto_choice.AddObject("Timed Drive Forward", new AutoTimedDrive());
	frc::SmartDashboard::PutData("Auto Modes", &auto_choice);*/
}

void Robot::AutonomousInit() {
	//std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", auto_choice.GetName());
	//frc::SmartDashboard::PutString("Selected Auto", autoSelected);
	//auto_command.release();
	//auto_command.reset((Command*)auto_choice.GetSelected());
	/*if (autoSelected == "Timed Drive Forward")
	{
		frc::SmartDashboard::PutString("Auto Selected", "Timed Drive Forward");
		auto_command.reset(new AutoTimedDrive());
	}
	else {
		frc::SmartDashboard::PutString("Auto Selected", "Encoders Drive Forward (default)");
		auto_command.reset(new AutoEncodeDrive());
	}
	auto_command.reset(auto_choice.GetSelected());*/
	auto_command.reset(new AutoEncodeDrive());
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
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (auto_command != nullptr) {
			auto_command->Cancel();
	}
	std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
frc::Scheduler::GetInstance()->Run();
}

/**
 * Log interesting values to the SmartDashboard.
 */
void Robot::Log() {

}

START_ROBOT_CLASS(Robot)
