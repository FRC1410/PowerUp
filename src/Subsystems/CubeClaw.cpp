#include <Subsystems/CubeClaw.h>
#include "../RobotMap.h"
#include "../Commands/TeleOp/TeleOpClawArms.h"

CubeClaw::CubeClaw()
    : frc::Subsystem("CubeClaw") {}

void CubeClaw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleOpClawArms());
}

frc::DoubleSolenoid & CubeClaw::GetSolenoid() {
	return claw_solenoid;
}

void CubeClaw::ClawWheels(float left_speed, float right_speed){
	left_claw_wheel.Set(left_speed);
	right_claw_wheel.Set(right_speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
