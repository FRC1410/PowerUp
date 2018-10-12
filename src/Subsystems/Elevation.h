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
	bool LimitSwitch();
private:
	WPI_TalonSRX m_elevator{elevator_motor_id};
	DigitalInput * LeftButton = new DigitalInput(0);
	DigitalInput * RightButton = new DigitalInput(0);
};

#endif  // Elevation_H
