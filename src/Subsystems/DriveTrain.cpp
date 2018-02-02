#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TeleOp/Drive.h"
#include <ctre/Phoenix.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

}


void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
}

void DriveTrain::TankDrive(double left, double right) {
	m_robotDrive.TankDrive(left, right);
}

void DriveTrain::ResetEncoders() {
	m_leftBack.GetSensorCollection().SetQuadraturePosition(0, 10);
	m_rightBack.GetSensorCollection().SetQuadraturePosition(0, 10);
}

float DriveTrain::ReturnDrivenInches(float radius){
	m_leftBack.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);

	m_leftBack.SetSensorPhase(true);

	float pi = 3.14159265;
    float circumference = 2 * pi * radius;
    float ticks_per_revolution = 1024;
    SmartDashboard::PutNumber("CIRCUMFERENCE", circumference);

    float left_encoder = m_leftBack.GetSensorCollection().GetQuadraturePosition();

    SmartDashboard::PutNumber("LEFT ENCODER", left_encoder);

    float encoder_ticks = left_encoder;
    SmartDashboard::PutNumber("Distance in Ticks", encoder_ticks);
    float revolutions = (encoder_ticks / ticks_per_revolution);
    SmartDashboard::PutNumber("REVOLUTIONS", revolutions);

    float distance_covered = circumference * revolutions;
    SmartDashboard::PutNumber("Distance in Inches", distance_covered);
    return distance_covered;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
