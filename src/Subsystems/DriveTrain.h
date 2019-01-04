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
	/*TalonSRX * m_leftFront = new TalonSRX(leftfrontDrive);
	TalonSRX * m_leftBack = new TalonSRX(leftbackDrive);
	TalonSRX * m_rightFront = new TalonSRX(rightfrontDrive);
	TalonSRX * m_rightBack = new TalonSRX(rightbackDrive);*/

	WPI_TalonSRX m_leftFront{leftfrontDrive};
	WPI_TalonSRX m_leftBack{leftbackDrive};
	WPI_TalonSRX m_rightFront{rightfrontDrive};
	WPI_TalonSRX m_rightBack{rightbackDrive};

	frc::SpeedControllerGroup m_left{m_leftFront, m_leftBack};
	frc::SpeedControllerGroup m_right{m_rightFront, m_rightBack};
	frc::DifferentialDrive m_robotDrive{m_left, m_right};

	double right_position, right_velocity, right_revolutions, right_inches, right_motor_velocity;

public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	void ConfigureEncoders();
	void ResetEncoders();
	double ReturnDrivenInches(double radius);
	double ReturnVelocity(double radius);
};

#endif  // DriveTrain_H
