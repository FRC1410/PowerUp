#include "Rotator.h"
#include "../RobotMap.h"
#include "../Commands/TeleOp/TeleOpRotation.h"

Rotator::Rotator() : Subsystem("Rotator") {

}

void Rotator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleOpRotation());
}

void Rotator::RotateClaw(double rotate_speed){
	rotatorMotors.Set(rotate_speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
