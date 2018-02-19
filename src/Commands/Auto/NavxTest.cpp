#include "NavxTest.h"
#include "../../Robot.h"

NavxTest::NavxTest() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void NavxTest::Initialize() {
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void NavxTest::Execute() {
	Robot::drivetrain.SmartDashboardnavX();
	Robot::drivetrain.TankDrive(0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool NavxTest::IsFinished() {
	if (Robot::drivetrain.SmartDashboardnavX()<=-90) {
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void NavxTest::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NavxTest::Interrupted() {

}