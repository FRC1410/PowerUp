#include "Rotator.h"
#include "../RobotMap.h"
#include "../Commands/TeleOp/TeleOpRotation.h"
#include <ctre/Phoenix.h>

Rotator::Rotator() : Subsystem("Rotator") {

}

void Rotator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleOpRotation());
}

void Rotator::RotateClaw(double rotate_speed){
	rotatorMotor.Set(rotator_speed * rotate_speed);
}

void Rotator::ConfigureEncoder() {
	rotatorMotor.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);
}

void Rotator::ResetEncoder() {
	rotatorMotor.GetSensorCollection().SetQuadraturePosition(0, 0);
}

double Rotator::ReturnRotatorAngle() {
	double ticks_per_rotator_revolution = 4096;

	double rotator_quad_position = rotatorMotor.GetSensorCollection().GetQuadraturePosition();
	SmartDashboard::PutNumber("ROTATOR QUAD POSITION", rotator_quad_position);

    double rotator_revolutions = (rotator_quad_position / ticks_per_rotator_revolution);
    SmartDashboard::PutNumber("ROTATOR REVOLUTIONS", rotator_revolutions);

    double rotator_angle = (rotator_revolutions * 360);
    SmartDashboard::PutNumber("ROTATOR ANGLE", rotator_angle);

    return rotator_angle;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
