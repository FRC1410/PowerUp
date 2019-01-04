#include <Commands/TeleOp/TeleOpClawWheelsIn.h>
#include <Commands/TeleOp/TeleOpClawWheelsOut.h>
#include <Commands/TeleOp/TeleOpClawWheelsOff.h>
#include <Commands/TeleOp/TeleOpShootCube.h>
#include "OI.h"

#include <WPILib.h>

#include "Commands/TeleOp/TeleOpClawArms.h"
#include "Commands/TeleOp/TeleOpClimb.h"
#include "Commands/TeleOp/TeleOpClimberRotate.h"

OI::OI() {
	ClawWheelsOut = new frc::JoystickButton(&operator_controller, claw_wheels_out_button);
	ClawWheelsIn = new frc::JoystickButton(&operator_controller, claw_wheels_in_button);
	ClawWheelsShoot = new frc::JoystickButton(&operator_controller, claw_wheels_shoot_button);
	ClawSolenoid = new frc::JoystickButton(&operator_controller, claw_arms_button);
	ClimbingSolenoid = new frc::JoystickButton(&operator_controller, climb_button);
	ClimbingRotatorSolenoid = new frc::JoystickButton(&operator_controller, climber_rotator_button);

	ClawWheelsOut->WhenPressed(new TeleOpClawWheelsOut);
	ClawWheelsOut->WhenReleased(new TeleOpClawWheelsOff);
	ClawWheelsIn->WhenPressed(new TeleOpClawWheelsIn);
	ClawWheelsIn->WhenReleased(new TeleOpClawWheelsOff);
	ClawWheelsShoot->WhenPressed(new TeleOpShootCube);
	ClawWheelsShoot->WhenReleased(new TeleOpClawWheelsOff);
	ClawSolenoid->WhenPressed(new TeleOpClawArms);
	ClimbingSolenoid->WhenPressed(new TeleOpClimb);
	ClimbingRotatorSolenoid->WhenPressed(new TeleOpClimberRotate);
}

frc::Joystick& OI::GetDriveJoystick() {
	return driver_controller;
}

void OI::PassDeadzone(double passedDeadzone) {
	drive_deadzone = passedDeadzone;
}

double OI::InputShape(double userValue, int axis, int controller, double deadzone) {
	if (axis == 1 || axis == 5) {
		if (controller == 0) {
			rawMagnitude = sqrt(pow(driver_controller.GetRawAxis(axis), 2) + pow(driver_controller.GetRawAxis(axis - 1), 2));
		} else {
			rawMagnitude = sqrt(pow(operator_controller.GetRawAxis(axis), 2) + pow(operator_controller.GetRawAxis(axis - 1), 2));
		}
		if (rawMagnitude <= deadzone) {
			return 0;
		} else {
			return ((rawMagnitude - deadzone)/(1 - deadzone)) * (userValue/rawMagnitude);
		}
	} else if (axis == 0 || axis == 4) {
		if (controller == 0) {
			rawMagnitude = sqrt(pow(driver_controller.GetRawAxis(axis), 2) + pow(driver_controller.GetRawAxis(axis + 1), 2));
		} else {
			rawMagnitude = sqrt(pow(operator_controller.GetRawAxis(axis), 2) + pow(operator_controller.GetRawAxis(axis + 1), 2));
		}
		if (rawMagnitude <= deadzone) {
			return 0;
		} else {
			return ((rawMagnitude - deadzone)/(1 - deadzone)) * (userValue/rawMagnitude);
		}
	} else {
		return userValue;
	}
}

double OI::GetDriveAxis(int axis) {
	return InputShape((double)driver_controller.GetRawAxis(axis), axis, 0, drive_deadzone);
}

double OI::GetDriveDirection(double x, double y) {
	if (x >= 0) {
	    return 90 - (atan(y/x))*(180/3.14159);
	} else {
	    return 270 - (atan(y/x))*(180/3.14159);
	}
}

double OI::ApplyExponent(double input, int exponent) {
	switch (exponent) {
		case 2:
			if (input > 0) {
	        	return (input + pow(input, 2))/2;
	    	} else {
	    		return (input - pow(input, 2))/2;
        	}
    		break;
		case 3:
	        if (input > 0) {
	            return (input + pow(input, 2) + pow(input, 3))/3;
	        } else {
	            return (input - pow(input, 2) + pow(input, 3))/3;
	        }
	    	break;
	    case 4:
	    	if (input > 0) {
	    		return (input + pow(input, 2) + pow(input, 3) + pow(input, 4))/4;
	        } else {
	        	return (input - pow(input, 2) + pow(input, 3) - pow(input, 4))/4;
	        }
	    	break;
	    default:
	    	return input;
	}
}

double OI::GetOperatorAxis(int axis) {
	return InputShape((double)operator_controller.GetRawAxis(axis), axis, 1, default_operator_deadzone);
}

double OI::GetOperatorButton(int button) {
	return operator_controller.GetRawButton(button);
}

double OI::GetDriverButton(int button) {
	return driver_controller.GetRawButton(button);
}
