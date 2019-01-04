#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TeleOp/Drive.h"
#include <ctre/Phoenix.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	right_position = 0;
	right_velocity = 0;
	right_revolutions = 0;
	right_inches = 0;
	right_motor_velocity = 0;
}


void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
}

void DriveTrain::TankDrive(double left, double right) {
	m_robotDrive.TankDrive(left, right);
}

void DriveTrain::ConfigureEncoders() {
	m_rightBack.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 0);
}

void DriveTrain::ResetEncoders() {
	m_rightBack.GetSensorCollection().SetQuadraturePosition(0, 0);
}

double DriveTrain::ReturnDrivenInches(double radius) {
	right_position = m_rightBack.GetSensorCollection().GetQuadraturePosition();
	SmartDashboard::PutNumber("Right encoder position", right_position);

	right_revolutions = right_position / 4096;
	right_inches = right_revolutions * 2 * 3.14159 * radius;
	SmartDashboard::PutNumber("Right encoder revolutions", right_revolutions);
	SmartDashboard::PutNumber("Right encoder inches", right_inches);
	return right_inches;
}

double DriveTrain::ReturnVelocity(double radius) {
	right_velocity = m_rightBack.GetSensorCollection().GetQuadratureVelocity();
	SmartDashboard::PutNumber("Right encoder velocity", right_velocity);

	right_motor_velocity = right_velocity * 2 * 3.14159 * radius / 4096 * 10;
	SmartDashboard::PutNumber("Right motor velocity", right_motor_velocity);
	return right_motor_velocity;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
