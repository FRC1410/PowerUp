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

bool Elevation::LimitSwitch(){
	frc::SmartDashboard::PutNumber("Left Limit Switch", LeftButton->Get());
	frc::SmartDashboard::PutNumber("Right Limit Switch", RightButton->Get());
	if (LeftButton->Get() == false || RightButton->Get() == false) {
		return false;
	} else {
		return true;
	}
}
