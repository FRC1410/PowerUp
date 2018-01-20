#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TeleOp/Drive.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

}


void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
}

void DriveTrain::TankDrive(double left, double right) {
	m_robotDrive.TankDrive(left, right);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
