#pragma once

//for encoders left is inverted

//DriveBase motors
const int left_front_drive_id = 1;
const int right_front_drive_id = 2;
const int left_middle_drive_id = 5;//was 3
const int right_middle_drive_id = 4;
const int left_back_drive_id = 3;//was 5
const int right_back_drive_id = 6;

//Elevator motor
const int elevator_motor_id = 7;

//CubeClaw
const int claw_left_wheel_id = 10;
const int claw_right_wheel_id = 12;

//Rotator
const int rotator_motor_id = 9;//was 8

//Controller Axis
const int tankLeftAxis = 1;
const int tankRightAxis = 5;
const int elevator_axis = 1;
const int rotator_axis = 5;

//Operator Controller Buttons
const int claw_arms_button = 1;
const int claw_wheels_shoot_button = 2;
const int claw_wheels_out_button = 5;
const int claw_wheels_in_button = 6;
const int climb_button = 3;
const int climber_rotator_button = 4;


const float claw_wheels_outtake = 0.5;
const float claw_wheels_intake = 1.0;
const float claw_wheels_shoot = 1.0;
