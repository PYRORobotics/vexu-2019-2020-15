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

  const int COLOR = 1;  //0=red  1=blue
  const int CUBE_6 = 0; //0=no   1=yes

  chassis.MotionController.setTarget("1f_Move_Forward", false);  //Drive forward to initiate
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6.5_in,0_in,0_deg}}, "1f_Collect_Cubes_1");
  chassis.MotionController.waitUntilSettled();

  tray.tilt.moveAbsolute(200, 80);

  pros::delay(500);

  intake.motors.moveVelocity(600);

  pros::delay(500);

  tray.tilt.moveAbsolute(0, 80);

  tray.intake.move_velocity(-600);

  pros::delay(2000);

  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();
  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();
  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();
  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  if (CUBE_6 == 0) {
    chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{35_in,0_in,0_deg}}, "1f_Move_To_Score");
  }
  else if (CUBE_6 == 1) {
    chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{33_in,0_in,0_deg}}, "1f_Move_To_Collect_Final_Cube");

    pros::delay(2500);
  }
  chassis.MotionController.waitUntilSettled();
  if (CUBE_6 == 1) {
    //tray.intake.move_velocity(0); //Intake, stop, bruh
    intake.motors.moveVelocity(0); //You too, tray
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube", true);  //Drive forward to collect dem' cubes
    chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12.5_in,0_in,0_deg}}, "1f_Move_To_Collect_Final_Cube_2");
    chassis.MotionController.waitUntilSettled();
    if (COLOR == 0) chassis.driveController.turnAngle(-70_deg); //Swing dat' ass around red
    else if (COLOR == 1) chassis.driveController.turnAngle(70_deg); //Swing dat' ass around blue
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube_2", false); //Drive forward to collect final cube
    chassis.MotionController.waitUntilSettled();

    intake.motors.moveVelocity(600);
    tray.intake.move_velocity(-600);

    chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
    chassis.MotionController.waitUntilSettled();

    chassis.MotionController.setTarget("1f_Collect_Cubes_1", true);  //Drive forward to collect dem' cubes
    chassis.MotionController.waitUntilSettled();
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube_2", true); //Drive forward to collect final cube
    chassis.MotionController.waitUntilSettled();
    if (COLOR == 0) chassis.driveController.turnAngle(70_deg); //Swing dat' ass around red
    else if (COLOR == 1) chassis.driveController.turnAngle(-70_deg); //Swing dat' ass around blue
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube", false);  //Drive forward to collect dem' cubes
    chassis.MotionController.waitUntilSettled();
  }

  pros::delay(2500);

  tray.intake.move_velocity(0); //Intake, stop, bruh

  if (COLOR == 0) chassis.driveController.turnAngle(125_deg); //Swing dat' ass around red
  else if (COLOR == 1) chassis.driveController.turnAngle(-125_deg); //Swing dat' ass around blue
  chassis.MotionController.setTarget("1f_Move_To_Score", false);  //Drive forward to score
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{25_in,0_in,0_deg}}, "1f_Move_Back_From_Score");
  chassis.MotionController.waitUntilSettled();

  intake.motors.moveVelocity(0); //You too, tray
  tray.tilt.moveAbsolute(450, 25);

  pros::delay(4000);

  intake.motors.moveVelocity(-600);
  tray.intake.move_velocity(-600);
  chassis.MotionController.setTarget("1f_Move_Back_From_Score", true);  //Drive backwards after score
  chassis.MotionController.waitUntilSettled();

  intake.motors.moveVelocity(0);
  tray.tilt.moveAbsolute(0, 80);
  tray.intake.move_velocity(0);
}
