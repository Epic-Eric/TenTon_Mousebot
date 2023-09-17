#include "main.h"
#include "pros/rotation.hpp"
/*--------------------------------------------------------------------------------------
        _       _           _ 
       | |     | |         | |
   __ _| | ___ | |__   __ _| |
  / _` | |/ _ \| '_ \ / _` | |
 | (_| | | (_) | |_) | (_| | |
  \__, |_|\___/|_.__/ \__,_|_|
   __/ |                      
  |___/                       
Initializes all devices in this program:
• Motors
• Controller
• Inertial Sensor
• Rotation Sensor
--------------------------------------------------------------------------------------*/

// ---------------- ALLIANCE ---------------- //
std::string alliance = "Red";


// ---------------- MOTORS ---------------- //
// port - Motor Name
// 1    - Left Motor
// 9    - Right Motor
// 2    - Arm Motor
// 20    - Claw Motor
// 10    - Tail Motor

pros::Motor leftMtr(1, pros::E_MOTOR_GEAR_BLUE);
pros::Motor rightMtr(2, pros::E_MOTOR_GEAR_BLUE);
pros::Motor leftMtr1(9, pros::E_MOTOR_GEAR_RED);
pros::Motor rightMtr1(10, pros::E_MOTOR_GEAR_BLUE);
pros::Motor tailMtr(4, pros::E_MOTOR_GEAR_RED);
pros::MotorGroup left ({leftMtr, leftMtr1});
pros::MotorGroup right ({rightMtr,rightMtr1});


// ---------------- CONTROLLER ---------------- //
pros::Controller master(pros::E_CONTROLLER_MASTER);


// ---------------- SENSORS ---------------- //
pros::Rotation rot (99);
