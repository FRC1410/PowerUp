#include "Commands/Auto/AutoTimedDrive.h"
#include "Commands/Auto/AutoEncodeDrive.h"
#include "Commands/Auto/NavxTest.h"
#include "Commands/Auto/AutoDoNothing.h"

#include "Commands/Auto/AutoStraightSwitch/AutoStraightSwitch.h"
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
	Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kForward);
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kReverse);
	frc::SmartDashboard::GetNumber("Auto Selection", 0);
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	/*frc::SmartDashboard::PutString("Game Data", gameData);
		if (gameData[0] == 'L'){
			auto_command.reset(new AutoStraightSwitch);
		}else if (gameData[0] == 'R'){
			auto_command.reset(new AutoCrossBaseline);
		}else{
			auto_command.reset(new AutoDoNothing);
		}*/
	auto_command.reset(new AutoStraightSwitch);
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
