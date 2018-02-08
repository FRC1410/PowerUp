#pragma once

//DriveBase motors
const int left_front_drive_id = 1;
const int right_front_drive_id = 2;
const int left_middle_drive_id = 3;
const int right_middle_drive_id = 4;
const int left_back_drive_id = 5;
const int right_back_drive_id = 6;

//Elevator motor
const int elevator_motor_id = 7;

//CubeClaw
const int claw_left_wheel_id = 10;
const int claw_right_wheel_id = 12;

//Rotator
const int rotator_motor_id = 8;

//Controller Axis
const int tankLeftAxis = 1;  //Left  stick y axis (driver)
const int tankRightAxis = 5; //Right stick y axis (driver)
const int tank_x_axis = 0;   //Left  stick x axis (driver)
const int tank_y_axis = 1;   //Left  stick y axis (driver)
const int elevator_axis = 1; //Left  stick y axis (operator)
const int rotator_axis = 5;  //Right stick y axis (operator)

//Operator Controller Buttons
const int claw_arms_button = 1;       //A button (operator)
const int climb_button = 3;           //X button (operator)
const int climber_rotator_button = 4; //Y button (operator)
const int claw_wheels_out_button = 5; //Left bumper (operator)
const int claw_wheels_in_button = 6;  //Right bumper (operator)

const float claw_wheels_outtake = 0.3;
const float claw_wheels_intake = 0.5;

//Driver Controller Buttons
const int exponential_driving_button = 5; //Left bumper (driver)
const int driving_mode_button = 6;        //Right bumper (driver)
