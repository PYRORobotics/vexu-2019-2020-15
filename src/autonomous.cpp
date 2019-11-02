#include "main.h"


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {


  chassis.MotionController.setTarget("1f_Move_Forward", false);  //Drive forward to initiate
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6.5_in,0_in,0_deg}}, "1f_Collect_Cubes_1");
  chassis.MotionController.waitUntilSettled();

  tray.tilt.moveAbsolute(200, 80);

  pros::delay(500);

  intake.motors.moveVelocity(600);

  pros::delay(1000);

  tray.tilt.moveAbsolute(0, 80);

  tray.intake.move_velocity(-600);

  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();
  //chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,3_in,30_deg}}, "1f_Collect_Cubes_2");
  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();
  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{10_in,0_in,0_deg}}, "1f_Collect_Return_Cubes");
  chassis.MotionController.waitUntilSettled();

  pros::delay(2000);

  //chassis.MotionController.setTarget("1f_Collect_Cubes_2", false);  //Drive forward to collect dem' cubes
  //chassis.MotionController.waitUntilSettled();

  //pros::delay(1000);

  tray.intake.move_velocity(0);
  intake.motors.moveVelocity(0);

  // chassis.MotionController.setTarget("1f_Collect_Cubes_2", true);  //Drive forward to collect dem' cubes
  // chassis.MotionController.waitUntilSettled();

  chassis.driveController.turnAngle(60_deg);
  chassis.driveController.turnAngle(60_deg);
  chassis.MotionController.setTarget("1f_Move_Forward", false);  //Drive forward to collect dem' cubes
  // chassis.MotionController.setTarget("1f_Swing_Dat_Ass_Back_Around", true);  //Drive forward to collect dem' cubes
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{4_in,16_in,90_deg}}, "1f_Swing_Dat_Ass_Back_Around_2");
  // chassis.MotionController.waitUntilSettled();
  //
  // chassis.MotionController.setTarget("1f_Swing_Dat_Ass_Back_Around_2", true);  //Drive forward to collect dem' cubes
  // chassis.MotionController.waitUntilSettled();

  pros::delay(2000);

  // pros::delay(1500);
  // intake.motors.moveVelocity(0);
  // tray.intake.move_velocity(0);

}
