#include "main.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	// pros::lcd::initialize();
	// pros::lcd::set_text(1, "Hello PROS User!");
	//
	// pros::lcd::register_btn1_cb(on_center_button);

	pros::delay(200);
//pros::lcd::initialize(); // Uncomment to use PROS's LCD
Screen screen;
pros::delay(100);


chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{13_in,0_in,0_deg}}, "1fSKILLS_Move_Forward");
chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{16_in,0_in,0_deg}}, "1f_Move_Forward");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
