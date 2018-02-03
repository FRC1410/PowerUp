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

void DriveTrain::ResetEncoder() {
	m_EncLeft.Reset();
	m_EncRight.Reset();
}

double DriveTrain::EncoderDistance() {
	m_EncLeft.SetSamplesToAverage(5);
	m_EncLeft.SetDistancePerPulse(1.0 / 360.0 /** 2.0 * 3.1415 * 3.0*/);
	m_EncLeft.SetMinRate(1.0);

	m_EncRight.SetSamplesToAverage(5);
	m_EncRight.SetDistancePerPulse(1.0 / 360.0 /** 2.0 * 3.1415 * 3.0*/);
	m_EncRight.SetMinRate(1.0);

	//encoder code from wpi
	/*sampleEncoder->SetMaxPeriod(.1);
	sampleEncoder->SetMinRate(10);
	sampleEncoder->SetDistancePerPulse(5);
	sampleEncoder->SetReverseDirection(true);
	sampleEncoder->SetSamplesToAverage(7);*/

	//will need to divide by 2 later
	return m_EncLeft.GetDistance() + m_EncRight.GetDistance();
};

float DriveTrain::ReturnDrivenInches(float radius){
	m_leftMiddle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);
	m_rightMiddle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::QuadEncoder, 0, 0);

	float pi = 3.14159265;
    float circumference = 2 * pi * radius;
    float ticks_per_revolution = 1024;
    SmartDashboard::PutNumber("CIRCUMFERENCE", circumference);

    float left_encoder = m_leftMiddle.GetSensorCollection().GetQuadraturePosition();
    float right_encoder = m_rightMiddle.GetSensorCollection().GetQuadraturePosition();

    SmartDashboard::PutNumber("LEFT ENCODER", left_encoder);
    SmartDashboard::PutNumber("RIGHT ENCODER", right_encoder);

    float average_encoders = (left_encoder + right_encoder) / 2;
    SmartDashboard::PutNumber("Distance in Ticks", average_encoders);
    float revolutions = (average_encoders / ticks_per_revolution);
    SmartDashboard::PutNumber("REVOLUTIONS", revolutions);

    float distance_covered = circumference * revolutions;
    SmartDashboard::PutNumber("Distance in Inches", distance_covered);
    return distance_covered;
	//temp
	return radius;
}

void DriveTrain::ResetEncoders() {
	m_leftMiddle.GetSensorCollection().SetQuadraturePosition(0, 10);
	m_rightMiddle.GetSensorCollection().SetQuadraturePosition(0, 10);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
