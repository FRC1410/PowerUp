#include "Elevation.h"
#include "../RobotMap.h"
#include "../Commands/TeleOp/TeleOpElevation.h"

Elevation::Elevation() : Subsystem("Elevation") {

}

void Elevation::InitDefaultCommand() {
	SetDefaultCommand(new TeleOpElevation())
;	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Elevation::ElevationWheel(double elevation_speed) {
	m_elevator.Set(elevation_speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
