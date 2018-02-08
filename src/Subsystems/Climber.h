#pragma once

#ifndef Climber_H
#define Climber_H

#include <DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "RobotMap.h"

class Climber : public frc::Subsystem {
public:
	Climber();
	void InitDefaultCommand() override;
	frc::DoubleSolenoid & ClimbSolenoid();
	frc::DoubleSolenoid & ClimberRotatorSolenoid();
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::DoubleSolenoid climber_solenoid {2, 3};
	frc::DoubleSolenoid climber_rotator {4, 5};
};

#endif
