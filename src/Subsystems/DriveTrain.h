#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "RobotMap.h"
#include <Encoder.h>
#include <AHRS.h>


class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX m_leftFront{left_front_drive_id};
	WPI_TalonSRX m_leftMiddle{left_middle_drive_id};
	WPI_TalonSRX m_leftRear{left_back_drive_id};
	WPI_TalonSRX m_rightFront{right_front_drive_id};
	WPI_TalonSRX m_rightMiddle{right_middle_drive_id};
	WPI_TalonSRX m_rightRear{right_back_drive_id};

	AHRS * navx = new AHRS(SPI::Port::kMXP);

	frc::SpeedControllerGroup m_left{m_leftFront, m_leftMiddle, m_leftRear};
	frc::SpeedControllerGroup m_right{m_rightFront, m_rightMiddle, m_rightRear};
	frc::DifferentialDrive m_robotDrive{m_left, m_right};

	AnalogInput * PressureInputNormal = new AnalogInput(0);

public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	float ReturnDrivenInches(float radius);
	void ResetEncodersandNavX();
	int SmartDashboardnavX();
	void ConfigureEncoders();
	void GetPressure();
};

#endif  // DriveTrain_H
