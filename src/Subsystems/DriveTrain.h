#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "RobotMap.h"
#include <Encoder.h>


class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX m_leftFront{leftfrontDrive};
	WPI_TalonSRX m_leftBack{leftbackDrive};
	WPI_TalonSRX m_rightFront{rightfrontDrive};
	WPI_TalonSRX m_rightBack{rightbackDrive};

	frc::Encoder m_EncLeft{0, 1, false, Encoder::k4X};
	frc::Encoder m_EncRight{2, 3, false, Encoder::k4X};

	frc::SpeedControllerGroup m_left{m_leftFront, m_leftBack};
	frc::SpeedControllerGroup m_right{m_rightFront, m_rightBack};
	frc::DifferentialDrive m_robotDrive{m_left, m_right};


public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	float ReturnDrivenInches(float radius);
	void ResetEncoders();
};

#endif  // DriveTrain_H
