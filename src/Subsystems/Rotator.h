#ifndef Rotator_H
#define Rotator_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class Rotator : public Subsystem {
public:
	Rotator();
	void InitDefaultCommand();
	void RotateClaw(double rotate_speed);
	void ConfigureEncoder();
	void ResetEncoder();
	double ReturnRotatorAngle();
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX rotatorMotor {rotator_motor_id};
};

#endif  // Rotator_H
