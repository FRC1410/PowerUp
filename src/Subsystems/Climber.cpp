#include <Subsystems/Climber.h>
#include "../RobotMap.h"
#include "../Commands/TeleOp/TeleOpClimb.h"

Climber::Climber()
    : frc::Subsystem("Climber") {}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleOpClimb());
}

frc::DoubleSolenoid & Climber::ClimbSolenoid() {
	return climber_solenoid;
}

frc::DoubleSolenoid & Climber::ClimberRotatorSolenoid() {
	return climber_rotator;
}
