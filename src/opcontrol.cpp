#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Task update_controller_values_task(update_controller_values, NULL);
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);
	Profile BrandonProf("profile-Brandon");

	Active_Profile = BrandonProf;

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		// driveLift(controller_2_values[LY]); //-127->127
		if(Active_Profile.button_map["drive"].second != Not_Assigned)
		{
			right_mtr = (Active_Profile.button_map["drive"].first == &Controller_1)?
			 						controller_1_values[Active_Profile.button_map["drive"].second]:
									controller_2_values[Active_Profile.button_map["drive"].second];
		}



		pros::delay(20);
	}
}
