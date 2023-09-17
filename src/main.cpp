#include "main.h"
#include "global.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
/*--------------------------------------------------------------------------------------
                  _       
                 (_)      
  _ __ ___   __ _ _ _ __  
 | '_ ` _ \ / _` | | '_ \ 
 | | | | | | (_| | | | | |
 |_| |_| |_|\__,_|_|_| |_|
     
Main setups everything and runs the entire program
--------------------------------------------------------------------------------------*/

// ---------------- INITIALIZE ---------------- //
void initialize() {
	pros::lcd::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
}

//okapi build goes in auto, coz don't need it after auto

void opcontrol() {
	left.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
	right.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);
	tailMtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	double turnSensitivity = 0.3; //How sensitive a turn is, 0 doesn't turn, 1 most sensitive
	double turnImportance = 0; //How much turning slows down the speed of forward, 0 doesn't affect, 1 stops going forward
	
	while(true){
		// ----- Chassis ----- //
		double turn = (double)master.get_analog(ANALOG_LEFT_Y)/(double)127*100; //controller joystick -127 -> 127
		double forw = (double)master.get_analog(ANALOG_RIGHT_X)/(double)127*100;
		double turnVolt = turnSensitivity*(turn*120); //PROS voltage go from -12000 -> 12000 volts
		double forwVolt = forw * 120 * (1 - (std::abs(turnVolt)/12000 * turnImportance)); 
		left.move_voltage(forwVolt + turnVolt);//left
		right.move_voltage(forwVolt - turnVolt);//right

		// ----- Tail ----- //
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
			tailMtr.move_voltage(12000);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			tailMtr.move_voltage(-12000);
		}
		else tailMtr.brake();
	}
}
