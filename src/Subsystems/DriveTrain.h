#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "RobotMap.h"
#include <AHRS.h>

class DriveTrain : public Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	double ReturnDrivenInches(float radius);
	void ResetEncodersandNavX();
	double SmartDashboardnavX();
	void ConfigureEncoders();
	void GetPressure();
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX m_leftFront{left_front_drive_id};
	WPI_TalonSRX m_leftMiddle{left_middle_drive_id};
	WPI_TalonSRX m_leftRear{left_back_drive_id};
	WPI_TalonSRX m_rightFront{right_front_drive_id};
	WPI_TalonSRX m_rightMiddle{right_middle_drive_id};
	WPI_TalonSRX m_rightRear{right_back_drive_id};

	float left_distance_covered;

	AHRS * navx = new AHRS(SPI::Port::kMXP);
	AnalogInput * PressureInput = new AnalogInput(3);

	frc::SpeedControllerGroup m_left{m_leftFront, m_leftMiddle, m_leftRear};
	frc::SpeedControllerGroup m_right{m_rightFront, m_rightMiddle, m_rightRear};
	frc::DifferentialDrive m_robotDrive{m_left, m_right};
};

#endif  // DriveTrain_H
