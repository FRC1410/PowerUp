/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

//DriveBase motors
const int leftfrontDrive = 1;
const int rightfrontDrive = 2;
const int leftmiddleDrive = 3;
const int rightmiddleDrive = 4;
const int leftrearDrive = 5;
const int rightrearDrive = 6;

//CubeClaw motors
const int claw_left_wheel_id = 7;
const int claw_right_wheel_id = 8;

const int tankLeftAxis = 1;
const int tankRightAxis = 5;

//Elevator motor
const int elevatorElevation = 9;
const int elevatorLeftAxis = 1;

//Rotator
const int rotator_motor_id = 10;
const int rotator_axis = 5;
