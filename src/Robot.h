#pragma once

#include "WPILib.h"

#include <OI.h>
#include <Subsystems/DriveTrain.h>
#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

class Robot : public IterativeRobot {
public:
	static DriveTrain drivetrain;
	static OI oi;

private:

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;

	void Log();

	std::unique_ptr<frc::Command> auto_command;
	frc::SendableChooser<frc::Command*> auto_choice;
};
