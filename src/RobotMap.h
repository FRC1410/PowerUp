#pragma once

//for encoders left is inverted

//DriveBase motors
const int left_front_drive_id = 1;
const int right_front_drive_id = 2;
const int left_middle_drive_id = 3;//was 3
const int right_middle_drive_id = 4;
const int left_back_drive_id = 5;//was 5
const int right_back_drive_id = 6;

//Elevator motor
const int elevator_motor_id = 7;

//CubeClaw
const int claw_left_wheel_id = 10;
const int claw_right_wheel_id = 12;

//Rotator
const int rotator_motor_id = 8;//was 9

//Controller Axis
const int tankLeftAxis = 1;  //Left  stick y axis (driver)
const int tankRightAxis = 5; //Right stick y axis (driver)
const int tank_x_axis = 0;   //Left  stick x axis (driver)
const int tank_y_axis = 1;   //Left  stick y axis (driver)
const int elevator_axis = 1; //Left  stick y axis (operator)
const int rotator_axis = 5;  //Right stick y axis (operator)

//Operator Controller Buttons
const int claw_arms_button = 1;         //A button     (operator)
const int claw_wheels_shoot_button = 2; //B button     (operator)
const int climb_button = 3;             //X button     (operator)
const int climber_rotator_button = 4;   //Y button     (operator)
const int claw_wheels_out_button = 5;   //Left bumper  (operator)
const int claw_wheels_in_button = 6;    //Right bumper (operator)

const double claw_intake_left = 0.9;
const double claw_intake_right = 1.0;
const double claw_wheels_outtake = 0.5;
const double claw_wheels_shoot = 1.0;

const double rotator_speed = 0.4;

//Driver Controller Buttons
const int deadzone_increase_button = 1;   //A button     (driver)
const int deadzone_decrease_button = 2;   //B button     (driver)
const int invert_driving_button = 3;      //X button     (driver)
const int exponential_driving_button = 5; //Left bumper  (driver)
const int driving_mode_button = 6;        //Right bumper (driver)

const double default_deadzone = 0.1;
