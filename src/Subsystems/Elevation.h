#ifndef Elevation_H
#define Elevation_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class Elevation : public Subsystem {
public:
	Elevation();
	void InitDefaultCommand();
	void ElevationWheel(double elevation_speed);
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX m_elevator{elevator_motor_id};
};

#endif  // Elevation_H
