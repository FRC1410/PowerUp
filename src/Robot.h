#pragma once

#include "WPILib.h"

#include <OI.h>
#include <Subsystems/DriveTrain.h>
#include <Subsystems/CubeClaw.h>
#include <Subsystems/Elevation.h>
#include <Subsystems/Rotator.h>
#include <Subsystems/Climber.h>
#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>

class Robot : public IterativeRobot {
public:
	static DriveTrain drivetrain;
	static OI oi;
	static CubeClaw cubeclaw;
	static Elevation elevation;
	static Rotator rotator;
	static Climber climber;

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
	std::string gameData;
};
