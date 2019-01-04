#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TeleOp/Drive.h"
#include <ctre/Phoenix.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	left_distance_covered = 0;
}


void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new Drive());
}

void DriveTrain::TankDrive(double left, double right) {
	//for some reason our motors are inverted
	m_robotDrive.TankDrive(-left, -right);
}
double DriveTrain::SmartDashboardnavX() {
	SmartDashboard::PutNumber("navX angle",navx->GetAngle());
	return navx->GetAngle();
}

void DriveTrain::ConfigureEncoders() {
	m_leftMiddle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);
	m_rightMiddle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);
}

double DriveTrain::ReturnDrivenInches(float radius) {

	float pi = 3.14159265;
    float circumference = 2 * pi * radius;
    float ticks_per_revolution = 256;

    float left_quad_position = m_leftMiddle.GetSensorCollection().GetQuadraturePosition();
    float right_quad_position = m_rightMiddle.GetSensorCollection().GetQuadraturePosition();

    float left_cycles = left_quad_position / 4;
    float right_cycles = right_quad_position / 4;

    float left_quad_velocity = m_leftMiddle.GetSensorCollection().GetQuadratureVelocity();
    float right_quad_velocity = m_rightMiddle.GetSensorCollection().GetQuadratureVelocity();
    SmartDashboard::PutNumber("Left side velocity", circumference * (left_quad_velocity / ticks_per_revolution) / 4);
    SmartDashboard::PutNumber("Right side velocity", circumference * (right_quad_velocity / ticks_per_revolution) / 4);

    float left_pulse_width_position = m_leftMiddle.GetSensorCollection().GetPulseWidthPosition();
    float right_pulse_width_position = m_rightMiddle.GetSensorCollection().GetPulseWidthPosition();
    SmartDashboard::PutNumber("LEFT PULSE WIDTH POSITION", left_pulse_width_position);
    SmartDashboard::PutNumber("RIGHT PULSE WIDTH POSITION", right_pulse_width_position);

    float left_pulse_width_velocity = m_leftMiddle.GetSensorCollection().GetPulseWidthVelocity();
    float right_pulse_width_velocity = m_rightMiddle.GetSensorCollection().GetPulseWidthVelocity();
    SmartDashboard::PutNumber("LEFT PULSE WIDTH VELOCITY", left_pulse_width_velocity);
    SmartDashboard::PutNumber("RIGHT PULSE WIDTH VELOCITY", right_pulse_width_velocity);

    float average_cycles = (left_cycles + right_cycles) / 2;
    float revolutions = (average_cycles / ticks_per_revolution);

    float left_revolutions = left_cycles / ticks_per_revolution;
    SmartDashboard::PutNumber("Left Revolutions", left_revolutions);
    SmartDashboard::PutNumber("Calculated left velocity", (circumference * left_revolutions - left_distance_covered)/50);
    left_distance_covered = circumference * left_revolutions;
    SmartDashboard::PutNumber("Left inches covered", left_distance_covered);

    float right_revolutions = (right_cycles / ticks_per_revolution);
    SmartDashboard::PutNumber("Right revolutions", right_revolutions);
    float right_distance_covered = circumference * right_revolutions;
    SmartDashboard::PutNumber("Right inches covered", right_distance_covered);

    float distance_covered = circumference * revolutions;
    SmartDashboard::PutNumber("Average inches covered", distance_covered);
    return -left_distance_covered;
}

void DriveTrain::ResetEncodersandNavX() {
	m_leftMiddle.GetSensorCollection().SetQuadraturePosition(0, 0);
	m_rightMiddle.GetSensorCollection().SetQuadraturePosition(0, 0);
	navx->Reset();
}

void DriveTrain::GetPressure() {
	frc::SmartDashboard::PutNumber("Pressure", 250 * (PressureInput->GetVoltage()/5) - 25);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
