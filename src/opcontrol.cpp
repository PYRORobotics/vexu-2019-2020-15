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


void opcontrol()
{
	tray.tilt.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Task intaketask(intake.teleop);
	pros::Task traytask(tray.teleop);
	while(1)
	{
		chassis.driveController.arcade((float) master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) / 127,
													 (float) master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) / 127,
													 0.05);

	  // intake.teleop(NULL);
		// tray.teleop(NULL);

		pros::delay(20);
	}
}
