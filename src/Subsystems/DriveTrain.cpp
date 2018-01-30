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
}

double DriveTrain::EncoderDistance() {
	m_EncLeft.SetSamplesToAverage(5);
	m_EncLeft.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * 3.0);
	m_EncLeft.SetMinRate(1.0);
	return m_EncLeft.GetDistance();
};

// Put methods for controlling this subsystem
// here. Call these from Commands.
