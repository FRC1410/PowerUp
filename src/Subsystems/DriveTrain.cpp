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

int DriveTrain::SmartDashboardnavX() {
	SmartDashboard::PutNumber("navX angle",navx->GetAngle());
	return navx->GetAngle();
}

void DriveTrain::ConfigureEncoders() {
	m_leftMiddle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);
	m_rightMiddle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);

//	m_leftMiddle.SetStatusFramePeriod(ctre::phoenix::motorcontrol::StatusFrameEnhanced::Status_2_Feedback0, 1, 10);
//	m_rightMiddle.SetStatusFramePeriod(ctre::phoenix::motorcontrol::StatusFrameEnhanced::Status_2_Feedback0, 1, 10);

}

float DriveTrain::ReturnDrivenInches(float radius) {
	float pi = 3.14159265;
    float circumference = 2 * pi * radius;
    float ticks_per_revolution = 256;//was 1024 //was 360
    SmartDashboard::PutNumber("CIRCUMFERENCE", circumference);

    float left_quad_position = -m_leftMiddle.GetSensorCollection().GetQuadraturePosition();
    float right_quad_position = m_rightMiddle.GetSensorCollection().GetQuadraturePosition();
    SmartDashboard::PutNumber("LEFT QUAD POSITION", left_quad_position);
    SmartDashboard::PutNumber("RIGHT QUAD POSITION", right_quad_position);

    float left_cycles = left_quad_position / 4;
    float right_cycles = right_quad_position / 4;
    SmartDashboard::PutNumber("LEFT CYCLES", left_cycles);
    SmartDashboard::PutNumber("RIGHT CYCLES", right_cycles);

/*    float left_quad_velocity = m_leftMiddle.GetSensorCollection().GetQuadratureVelocity();
    float right_quad_velocity = m_rightMiddle.GetSensorCollection().GetQuadratureVelocity();
    SmartDashboard::PutNumber("LEFT QUAD VELOCITY", left_quad_velocity);
    SmartDashboard::PutNumber("RIGHT QUAD VELOCITY", right_quad_velocity);

    float left_pulse_width_position = m_leftMiddle.GetSensorCollection().GetPulseWidthPosition();
    float right_pulse_width_position = m_rightMiddle.GetSensorCollection().GetPulseWidthPosition();
    SmartDashboard::PutNumber("LEFT PULSE WIDTH POSITION", left_pulse_width_position);
    SmartDashboard::PutNumber("RIGHT PULSE WIDTH POSITION", right_pulse_width_position);

    float left_pulse_width_velocity = m_leftMiddle.GetSensorCollection().GetPulseWidthVelocity();
    float right_pulse_width_velocity = m_rightMiddle.GetSensorCollection().GetPulseWidthVelocity();
    SmartDashboard::PutNumber("LEFT PULSE WIDTH VELOCITY", left_pulse_width_velocity);
    SmartDashboard::PutNumber("RIGHT PULSE WIDTH VELOCITY", right_pulse_width_velocity);*/

    float average_cycles = (left_cycles + right_cycles) / 2;
    SmartDashboard::PutNumber("AVG CYCLES", average_cycles);
    float revolutions = (average_cycles / ticks_per_revolution);

    float left_revolutions = left_cycles / ticks_per_revolution;
    SmartDashboard::PutNumber("LEFT REVOLUTIONS", left_revolutions);
    float left_distance_covered = circumference * left_revolutions;
    SmartDashboard::PutNumber("LEFT INCHES COVERED", left_distance_covered);

    float right_revolutions = (right_cycles / ticks_per_revolution);
    SmartDashboard::PutNumber("RIGHT REVOLUTIONS", right_revolutions);
    float right_distance_covered = circumference * right_revolutions;
    SmartDashboard::PutNumber("RIGHT INCHES COVERED", right_distance_covered);

    float distance_covered = circumference * revolutions;
    SmartDashboard::PutNumber("AVG INCHES COVERED", distance_covered);
    return right_distance_covered;
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
