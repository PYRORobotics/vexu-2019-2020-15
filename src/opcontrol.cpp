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
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	// chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,0_in,0_deg}}, "0");
  // // chassis.MotionController.setTarget("0", false);  //Drive forward to initiate
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6_in,0_in,0_deg}}, "0.1");
  // chassis.MotionController.waitUntilSettled();
	//
  // // chassis.MotionController.setTarget("0.1", true);
  // chassis.MotionController.waitUntilSettled();


	tray.t_trayteleop.suspend();
  intake.motors.moveVelocity(-180);

  tray.arm_motors.setBrakeMode(AbstractMotor::brakeMode::hold);
  tray.arm_motors.moveAbsolute(500, 150);

  pros::delay(1000);

  tray.tilt.moveAbsolute(700, 180);

  pros::delay(1200);

  tray.tilt.moveAbsolute(0, 180);

  pros::delay(300);

  tray.arm_motors.moveAbsolute(0, 180);

  intake.motors.moveVelocity(0);

  pros::delay(1000);
	tray.t_trayteleop.resume();

	pros::Task intaketask(intake.teleop);
	// pros::Task traytask(tray.trayteleop);

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
