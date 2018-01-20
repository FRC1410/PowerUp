#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "RobotMap.h"


class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX m_leftFront{leftfrontDrive};
	WPI_TalonSRX m_leftRear{leftrearDrive};
	WPI_TalonSRX m_rightFront{rightfrontDrive};
	WPI_TalonSRX m_rightRear{rightrearDrive};
	frc::SpeedControllerGroup m_left{m_leftFront, m_leftRear};
	frc::SpeedControllerGroup m_right{m_rightFront, m_rightRear};
	frc::DifferentialDrive m_robotDrive{m_left, m_right};


public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
};

#endif  // DriveTrain_H
