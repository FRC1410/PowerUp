#pragma once

#ifndef CubeClaw_H
#define CubeClaw_H


#include <DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "RobotMap.h"

class CubeClaw : public frc::Subsystem {
public:
	CubeClaw();
	void InitDefaultCommand() override;
	frc::DoubleSolenoid & GetSolenoid();
	void ClawWheels(float left_speed, float right_speed);
private:
	WPI_TalonSRX left_claw_wheel{claw_left_wheel_id};
	WPI_TalonSRX right_claw_wheel{claw_right_wheel_id};
	frc::DoubleSolenoid claw_solenoid {0, 1};
};

#endif
