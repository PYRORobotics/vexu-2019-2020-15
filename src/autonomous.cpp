#include "main.h"

void skillsAuto()
{
  tray.t_trayteleop.suspend();

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,0_in,0_deg}}, "0");
  chassis.MotionController.setTarget("0", false);  //Drive forward to initiate
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6_in,0_in,0_deg}}, "0.1");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("0.1", true);
  chassis.MotionController.waitUntilSettled();


  intake.motors.moveVelocity(-180);

  tray.arm_motors.setBrakeMode(AbstractMotor::brakeMode::hold);
  tray.arm_motors.moveAbsolute(500, 150);

  pros::delay(1000);

  tray.tilt.moveAbsolute(800, 180);

  pros::delay(1500);

  tray.tilt.moveAbsolute(0, 180);

  pros::delay(1000);

  tray.arm_motors.moveAbsolute(0, 180);

  intake.motors.moveVelocity(0);

  pros::delay(1500);



  tray.arm_motors.moveAbsolute(700, 150);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{17_in,-11_in,-40_deg}}, "1");
  chassis.MotionController.setTarget("1", false);  //Drive forward to initiate
  chassis.MotionController.waitUntilSettled();
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{17_in,0_in,0_deg}}, "2");
  intake.motors.moveRelative(-200, 100);
  chassis.MotionController.generatePath({Point{0_in,0_in,45_deg}, Point{12_in,27_in,90_deg}}, "3");
  chassis.MotionController.setTarget("2", true);  //Drive forward to initiate
  chassis.MotionController.waitUntilSettled();

  chassis.driveController.turnAngle(-90 * TURN_MULTIPLIER);
  chassis.MotionController.waitUntilSettled();

  tray.arm_motors.moveAbsolute(40, 180);
  intake.motors.moveVelocity(200);


  chassis.MotionController.setTarget("3", false);  //Drive forward to initiate
  chassis.MotionController.waitUntilSettled();

  intake.motors.moveVelocity(0);

  intake.motors.moveRelative(-200, 100);
  pros::delay(1000);
  tray.arm_motors.moveAbsolute(800, 150);
  pros::delay(2000);
  intake.motors.moveRelative(-200, 150);



  while(1)
  {
    std::cout << tray.arm_motors.getEncoder() << std::endl;;
    pros::delay(20);
  }


  pros::delay(999999999);


  chassis.MotionController.setTarget("1f_Move_Forward", false);  //Drive forward to initiate
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6.5_in,0_in,0_deg}}, "1f_Collect_Cubes_1");
  chassis.MotionController.waitUntilSettled();

  tray.tilt.moveAbsolute(200, 80);

  pros::delay(500);

  intake.motors.moveVelocity(600);

  pros::delay(500);

  tray.tilt.moveAbsolute(0, 80);

  //tray.intake.move_velocity(-600);

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{18_in,0_in,0_deg}}, "2r_Collect_Tower_Cube");

  pros::delay(2000);


  for(int i = 0; i < 3; i++)
  {
    chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
    chassis.MotionController.waitUntilSettled();
    pros::delay(500);
  }

  pros::delay(500);

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{18_in,4_in,0_deg}}, "3f");

  chassis.MotionController.setTarget("2r_Collect_Tower_Cube", 1);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();
  chassis.MotionController.setTarget("3f", 0);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{16.25_in,0_in,0_deg}}, "4r");

  chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("4r", 1);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();

  //tray.intake.move_velocity(0);

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12.5_in,0_in,0_deg}}, "5r");

  chassis.driveController.turnAngle(-87_deg);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("5r", 1);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();

  //tray.intake.move_velocity(-600);

  tray.tilt.moveAbsolute(250, 600);
  pros::delay(200);
  tray.tilt.moveAbsolute(0, 100);

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{20_in,0_in,0_deg}}, "6f");

  chassis.driveController.turnAngle(15_deg);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("6f", 0);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("1f_Collect_Cubes_1", 1);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();

  //tray.intake.move_velocity(0);

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{25.5_in,0_in,0_deg}}, "7f");

  chassis.driveController.turnAngle(-128_deg);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("7f", 0);  //Drive forward to collect dem' cubes
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{13_in,0_in,0_deg}}, "8r");

  intake.motors.moveVelocity(0); //You too, tray
  tray.tilt.moveAbsolute(460, 25);

  pros::delay(4000);
  tray.tilt.moveVelocity(0);
  intake.motors.moveVelocity(-600);
  //tray.intake.move_velocity(-600);
  chassis.MotionController.setTarget("8r", 1);  //Drive backwards after score
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{55_in,0_in,0_deg}}, "9f");
  // chassis.MotionController.waitUntilSettled();
  //
  // chassis.driveController.turnAngle(-135_deg);
  // chassis.MotionController.waitUntilSettled();
  //
  // chassis.driveController.driveVector(-0.5, 0);
  // pros::delay(1500);
  // chassis.driveController.driveVector(0, 0);
  //
  //
  // intake.motors.moveVelocity(600);
  // tray.tilt.moveAbsolute(0, 80);
  // //tray.intake.move_velocity(-600);
  //
  // chassis.MotionController.setTarget("9f", 0);  //Drive backwards after score
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{19_in,5.5_in,0_deg}}, "10s");
  // chassis.MotionController.waitUntilSettled();
  //
  // chassis.MotionController.setTarget("10s", 0);  //Drive backwards after score
  // chassis.MotionController.waitUntilSettled();
  //
  // for(int i = 0; i < 4; i++)
  // {
  //   chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
  //   chassis.MotionController.waitUntilSettled();
  //   pros::delay(500);
  // }
  //
  //
  //
  intake.motors.moveVelocity(0);
  tray.tilt.moveAbsolute(0, 80);
  //tray.intake.move_velocity(0);

}

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

  skillsAuto();

  pros::delay(999999999);

  const int COLOR = 0;  //0=red  1=blue
  const int CUBE_6 = 0; //0=no   1=yes

  chassis.MotionController.setTarget("1fSKILLS_Move_Forward", false);  //Drive forward to initiate
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{5.75_in,0_in,0_deg}}, "1f_Collect_Cubes_1");
  chassis.MotionController.waitUntilSettled();

  tray.tilt.moveAbsolute(200, 80);

  pros::delay(500);

  intake.motors.moveVelocity(600);

  pros::delay(500);

  tray.tilt.moveAbsolute(0, 80);

  //tray.intake.move_velocity(-600);

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

    pros::delay(2000);
  }
  chassis.MotionController.waitUntilSettled();
  if (CUBE_6 == 1) {
    //tray.intake.move_velocity(0); //Intake, stop, bruh
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube", true);  //Drive forward to collect dem' cubes
    chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12.5_in,0_in,0_deg}}, "1f_Move_To_Collect_Final_Cube_2");
    chassis.MotionController.waitUntilSettled();
    if (COLOR == 0) chassis.driveController.turnAngle(-70_deg); //Swing dat' ass around red
    else if (COLOR == 1) chassis.driveController.turnAngle(70_deg); //Swing dat' ass around blue
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube_2", false); //Drive forward to collect final cube
    chassis.MotionController.waitUntilSettled();

    intake.motors.moveVelocity(600);
    //tray.intake.move_velocity(-600);

    chassis.MotionController.setTarget("1f_Collect_Cubes_1", false);  //Drive forward to collect dem' cubes
    chassis.MotionController.waitUntilSettled();

    chassis.MotionController.setTarget("1f_Collect_Cubes_1", true);  //Drive forward to collect dem' cubes
    chassis.MotionController.waitUntilSettled();
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube_2", true); //Drive forward to collect final cube
    chassis.MotionController.waitUntilSettled();
    if (COLOR == 0) chassis.driveController.turnAngle(70_deg); //Swing dat' ass around red
    else if (COLOR == 1) chassis.driveController.turnAngle(-70_deg); //Swing dat' ass around blue
    chassis.MotionController.setTarget("1f_Move_To_Collect_Final_Cube", false);  //Drive forward to collect dem' cubes
    chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{30_in,0_in,0_deg}}, "1f_Move_To_Score");
    chassis.MotionController.waitUntilSettled();
  }

  pros::delay(2000);

  //tray.intake.move_velocity(0); //Intake, stop, bruh

  if (COLOR == 0) chassis.driveController.turnAngle(125_deg); //Swing dat' ass around red
  else if (COLOR == 1) chassis.driveController.turnAngle(-125_deg); //Swing dat' ass around blue
  chassis.MotionController.setTarget("1f_Move_To_Score", false);  //Drive forward to score
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{25_in,0_in,0_deg}}, "1f_Move_Back_From_Score");
  chassis.MotionController.waitUntilSettled();

  intake.motors.moveVelocity(0); //You too, tray
  tray.tilt.moveAbsolute(460, 25);

  pros::delay(4000);
  tray.tilt.moveVelocity(0);
  intake.motors.moveVelocity(-600);
  //tray.intake.move_velocity(-600);
  chassis.MotionController.setTarget("1f_Move_Back_From_Score", true);  //Drive backwards after score
  chassis.MotionController.waitUntilSettled();

  intake.motors.moveVelocity(0);
  tray.tilt.moveAbsolute(0, 80);
  //tray.intake.move_velocity(0);
}
