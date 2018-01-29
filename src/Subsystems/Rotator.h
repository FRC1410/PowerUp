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
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX rotatorMotor1 {rotator_motor_1_id};
	WPI_TalonSRX rotatorMotor2 {rotator_motor_2_id};
	frc::SpeedControllerGroup rotatorMotors{rotatorMotor1, rotatorMotor2};
};

#endif  // Rotator_H
