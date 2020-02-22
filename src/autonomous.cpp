#include "main.h"
#include "autonomous.h"

//==================================START FILE==================================
//==============================================================================
// File:		autonomous.cpp
// Author:	Brandon Rice
// Created: 13 July 2019
// Last Modified: 30 October 2019
//
// Description:
// ------------
// From PROS:
// * Runs the user autonomous code. This function will be started in its own task
// * with the default priority and stack size whenever the robot is enabled via
// * the Field Management System or the VEX Competition Switch in the autonomous
// * mode. Alternatively, this function may be called in initialize or opcontrol
// * for non-competition testing purposes.
// *
// * If the robot is disabled or communications is lost, the autonomous task
// * will be stopped. Re-enabling the robot will restart the task, not re-start it
// * from where it left off.
//
//------------------------------------------------------------------------------


// File Setup
// ----------
using namespace okapi;


// Global/Static Objects
// ---------------------
// pros::Task lifttaskauto(lift.auton, (void*)NULL, TASK_PRIORITY_DEFAULT,
//                 TASK_STACK_DEPTH_DEFAULT, "lift auton task");


// okapi::PYROChassis* chassisptr = &chassis;
// double coordinfo[] = {1,2,3};
// asyncDriveStruct ds{
//   chassisptr,
//   coordinfo
// };
//
// pros::Task t_test(drive_to_coordinate_async, (void*)&ds, TASK_PRIORITY_DEFAULT,
//                 TASK_STACK_DEPTH_DEFAULT, "lift auton task");

// Function Defintions
// -------------------

//------------------------------------------------------------------------------
// Function: autonomousSelector(autonID) :
// ---------------------------------------
// Description:
// 		Runs the autonomous routine currently selected with static autonID
//    selectedAutonID.
//
// Parameters:
//```
//		autonID id - the id of the autonomous routine to be run.
//```
// Returns:
//```
//		None
//```
//------------------------------------------------------------------------------
void autonomousSelector(autonNames id)
{
  std::cout << id << std::endl;
  switch (id) {
    case red0:
      lv_obj_set_hidden(Screen::Screen_Plate_R,0);
      auton_red0();
      break;
    case blue0:
      lv_obj_set_hidden(Screen::Screen_Plate_B,0);
      auton_blue0();
      break;
    case red1:
      lv_obj_set_hidden(Screen::Screen_Plate_R,0);
      auton_red1();
      break;
    case blue1:
      lv_obj_set_hidden(Screen::Screen_Plate_B,0);
      auton_blue1();
      break;
    case redSkills0:
      lv_obj_set_hidden(Screen::Screen_Plate_R,0);
      auton_skills0();
      break;
    case blueSkills0:
      lv_obj_set_hidden(Screen::Screen_Plate_B,0);
      auton_skills0();
      break;
    default:
      break;
  }
}


//------------------------------------------------------------------------------
// Function: autonomous() :
// ------------------------
// Description:
// 		The function (task) that will be scheduled after initialize(), and after
// 		competition_initialize() if connected to a competition switch. This
//    function will run until whichever happens first: (1) autonomous() exits,
//    (2) the autonomous period ends, or (3) the controllers are disconnected
//    from the competition switch.
//
// Parameters:
//```
//		None
//```
// Returns:
//```
//		None
//```
//------------------------------------------------------------------------------
void autonomous()
{
  // okapi::PYRO_Arduino::send("AUTONOMOUS");

    // Initialize objects for auton
    // lift.piston_floor.retract();
    // lift.piston_door.retract();

    std::cout << "Auton should be: " << Screen::selectedAuton << std::endl;

    // Run selected auton routine
    autonomousSelector(Screen::selectedAuton);

    // auton_blue0();
    // Remove lift task from scheduler
    // lifttaskauto.suspend();
    // lifttaskauto.remove();

    lv_obj_set_hidden(Screen::Screen_Sponsors,0);
    pros::lcd::print(3, "DONE WITH AUTON");
}


//------------------------------------------------------------------------------
// Function: auton_red0() :
// ------------------------
// Description:
// 		The main code to control the robot using the red0 autonomous routine.
//
// Parameters:
//```
//		None
//```
// Returns:
//```
//		None
//```
//------------------------------------------------------------------------------
void auton_red0()
{

      tray.t_trayteleop.suspend();

      intake.motors.moveVelocity(-180);

      pros::delay(500);


      tray.arm_motors.setBrakeMode(AbstractMotor::brakeMode::hold);
      tray.arm_motors.moveAbsolute(300, 150);

      pros::delay(500);

      tray.tilt.moveAbsolute(700, 180);

      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{5.5_in,0_in,0_deg}}, "FORWARD CUBE LENGTH");
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{3_in,0_in,0_deg}}, "FORWARD CUBE LENGTH 2");
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,0_in,0_deg}}, "0");
      chassis.MotionController.setTarget("0", false);  //Drive forward to initiate
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6_in,0_in,0_deg}}, "0.1");
      chassis.MotionController.waitUntilSettled();

      pros::delay(500);

      tray.tilt.moveAbsolute(0, 180);

      pros::delay(1000);


      chassis.MotionController.removePath("0");
      chassis.MotionController.setTarget("0.1", true);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,0_in,0_deg}}, "2");
      chassis.MotionController.waitUntilSettled();



      tray.arm_motors.moveAbsolute(-40, 180);

      intake.motors.moveVelocity(0);

      pros::delay(500);

      intake.motors.moveVelocity(180);

      chassis.MotionController.removePath("0.1");
      chassis.MotionController.setTarget("2", false);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{30_in,23_in,0_deg}}, "3");
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{5_in,0_in,0_deg}}, "3.5");
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{31_in,20_in,0_deg}}, "3NEW");
      chassis.MotionController.waitUntilSettled();
      tray.arm_motors.tarePosition();


      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();


      chassis.MotionController.removePath("2");
      chassis.MotionController.setTarget("3", true);
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{10_in,0_in,0_deg}}, "4");
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{4_in,0_in,0_deg}}, "4.5");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("3.5", false);
      chassis.MotionController.waitUntilSettled();


      chassis.MotionController.removePath("3");
      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH 2", false);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{17.5_in,-15_in,88_deg}}, "4");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("4", true);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{30_in,0_in,0_deg}}, "5");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("5", false);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{42_in,-14_in,0_deg}}, "6");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("6", false);
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{42_in,16_in,45_deg}}, "7");
      chassis.MotionController.waitUntilSettled();

      chassis.driveController.setMaxVelocity(15);
      chassis.driveController.turnAngle(-43_deg);

      chassis.driveController.setMaxVelocity(200);



      chassis.driveController.driveVector(0.4, 0);
      pros::delay(1800);
      chassis.driveController.stop();
      pros::delay(150);
      chassis.driveController.driveVector(-0.16, 0);
      pros::delay(450);
      chassis.driveController.stop();
      pros::delay(150);

      intake.motors.moveVelocity(0);
      tray.tilt.moveAbsolute(1320, 180);
      pros::delay(700);
      tray.tilt.moveAbsolute(1320, 50);

      pros::delay(2500);
      intake.motors.moveVelocity(-10);

      tray.tilt.moveAbsolute(1370, 30);
      pros::delay(2000);
      tray.tilt.moveAbsolute(1370, 40);
      pros::delay(2000);


      chassis.driveController.driveVector(0.05, 0);
      pros::delay(2500);
      chassis.driveController.stop();
      pros::delay(150);

      intake.motors.setBrakeMode(AbstractMotor::brakeMode::hold);
      tray.tilt.moveAbsolute(0, 200);
      pros::delay(3500);

      tray.arm_motors.moveAbsolute(0, 80);
      pros::delay(400);
      intake.motors.moveVelocity(-40);

      chassis.driveController.driveVector(-0.1, 0);
      pros::delay(350);

      chassis.driveController.driveVector(-0.5, 0.1);//0.1
      pros::delay(1000);

      intake.motors.setBrakeMode(AbstractMotor::brakeMode::coast);
      chassis.driveController.stop();
      intake.motors.moveVelocity(0);
}


void auton_red2()
{
}


//------------------------------------------------------------------------------
// Function: auton_blue0() :
// -------------------------
// Description:
// 		The main code to control the robot using the blue0 autonomous routine.
//
// Parameters:
//```
//		None
//```
// Returns:
//```
//		None
//```
//------------------------------------------------------------------------------
void auton_blue0()
{

      tray.t_trayteleop.suspend();

      intake.motors.moveVelocity(-180);

      pros::delay(500);


      tray.arm_motors.setBrakeMode(AbstractMotor::brakeMode::hold);
      tray.arm_motors.moveAbsolute(300, 150);

      pros::delay(500);

      tray.tilt.moveAbsolute(700, 180);

      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{5.5_in,0_in,0_deg}}, "FORWARD CUBE LENGTH");
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{3_in,0_in,0_deg}}, "FORWARD CUBE LENGTH 2");

      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,0_in,0_deg}}, "0");
      chassis.MotionController.setTarget("0", false);  //Drive forward to initiate
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6_in,0_in,0_deg}}, "0.1");
      chassis.MotionController.waitUntilSettled();

      pros::delay(500);

      tray.tilt.moveAbsolute(0, 180);

      pros::delay(1000);


      chassis.MotionController.removePath("0");
      chassis.MotionController.setTarget("0.1", true);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,0_in,0_deg}}, "2");
      chassis.MotionController.waitUntilSettled();



      tray.arm_motors.moveAbsolute(-40, 180);

      intake.motors.moveVelocity(0);

      pros::delay(500);

      intake.motors.moveVelocity(180);

      chassis.MotionController.removePath("0.1");
      chassis.MotionController.setTarget("2", false);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{30_in,-23_in,0_deg}}, "3");
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{5_in,0_in,0_deg}}, "3.5");
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{31_in,20_in,0_deg}}, "3NEW");
      chassis.MotionController.waitUntilSettled();
      tray.arm_motors.tarePosition();


      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();


      chassis.MotionController.removePath("2");
      chassis.MotionController.setTarget("3", true);
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{10_in,0_in,0_deg}}, "4");
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{4_in,0_in,0_deg}}, "4.5");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("3.5", false);
      chassis.MotionController.waitUntilSettled();


      chassis.MotionController.removePath("3");
      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("FORWARD CUBE LENGTH 2", false);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{17_in,15_in,-85_deg}}, "4");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("4", true);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{30_in,0_in,0_deg}}, "5");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("5", false);
      chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{42_in,12_in,0_deg}}, "6");
      chassis.MotionController.waitUntilSettled();

      chassis.MotionController.setTarget("6", false);
      // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{42_in,16_in,45_deg}}, "7");
      chassis.MotionController.waitUntilSettled();

      chassis.driveController.setMaxVelocity(15);
      chassis.driveController.turnAngle(45_deg);

      chassis.driveController.setMaxVelocity(200);



      chassis.driveController.driveVector(0.4, 0);
      pros::delay(1800);
      chassis.driveController.stop();
      pros::delay(150);
      chassis.driveController.driveVector(-0.16, 0);
      pros::delay(450);
      chassis.driveController.stop();
      pros::delay(150);

      intake.motors.moveVelocity(0);
      tray.tilt.moveAbsolute(1320, 180);
      pros::delay(700);
      tray.tilt.moveAbsolute(1320, 50);

      pros::delay(2500);
      intake.motors.moveVelocity(-10);

      tray.tilt.moveAbsolute(1370, 30);
      pros::delay(2000);
      tray.tilt.moveAbsolute(1370, 40);
      pros::delay(2000);


      chassis.driveController.driveVector(0.04, 0);
      pros::delay(2500);
      chassis.driveController.stop();
      pros::delay(150);

      intake.motors.setBrakeMode(AbstractMotor::brakeMode::hold);
      tray.tilt.moveAbsolute(0, 200);
      pros::delay(3500);

      tray.arm_motors.moveAbsolute(0, 80);
      pros::delay(400);
      intake.motors.moveVelocity(-40);

      chassis.driveController.driveVector(-0.1, 0);
      pros::delay(350);

      chassis.driveController.driveVector(-0.5, -0.1);//0.1
      pros::delay(1000);

      intake.motors.setBrakeMode(AbstractMotor::brakeMode::coast);
      chassis.driveController.stop();
      intake.motors.moveVelocity(0);

      // chassis.MotionController.removePath("FORWARD CUBE LENGTH");
      // chassis.MotionController.removePath("FORWARD CUBE LENGTH 2");
      // chassis.MotionController.removePath("0");
      // chassis.MotionController.removePath("0.1");
      // chassis.MotionController.removePath("FORWARD CUBE LENGTH");
      // chassis.MotionController.removePath("FORWARD CUBE LENGTH");
      // chassis.MotionController.removePath("FORWARD CUBE LENGTH");
      // chassis.MotionController.removePath("FORWARD CUBE LENGTH");
      // chassis.MotionController.removePath("FORWARD CUBE LENGTH");
      // chassis.MotionController.removePath("FORWARD CUBE LENGTH");

}
void auton_blue1()
{
}


//------------------------------------------------------------------------------
// Function: auton_red1() :
// ------------------------
// Description:
// 		The main code to control the robot using the red1 autonomous routine.
//
// Parameters:
//```
//		None
//```
// Returns:
//```
//		None
//```
//------------------------------------------------------------------------------
void auton_red1()
{
}



//------------------------------------------------------------------------------
// Function: auton_skills0() :
// ---------------------------
// Description:
// 		The main code to control the robot using the skills0 autonomous routine.
//
// Parameters:
//```
//		None
//```
// Returns:
//```
//		None
//```
//------------------------------------------------------------------------------
void auton_skills0()
{
  tray.t_trayteleop.suspend();

  intake.motors.moveVelocity(-180);

  pros::delay(500);


  tray.arm_motors.setBrakeMode(AbstractMotor::brakeMode::hold);
  tray.arm_motors.moveAbsolute(300, 150);

  pros::delay(500);

  tray.tilt.moveAbsolute(700, 180);

  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{5.5_in,0_in,0_deg}}, "FORWARD CUBE LENGTH");
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{12_in,0_in,0_deg}}, "0");
  chassis.MotionController.setTarget("0", false);  //Drive forward to initiate
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6_in,0_in,0_deg}}, "0.1");
  chassis.MotionController.waitUntilSettled();

  pros::delay(500);

  tray.tilt.moveAbsolute(0, 180);

  pros::delay(1000);


  chassis.MotionController.removePath("0");
  chassis.MotionController.setTarget("0.1", true);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{13_in,-12_in,-50_deg}}, "2");
  chassis.MotionController.waitUntilSettled();



  tray.arm_motors.moveAbsolute(-40, 180);

  intake.motors.moveVelocity(0);

  pros::delay(500);
  tray.arm_motors.tarePosition();


  intake.motors.moveVelocity(21);
  tray.cube_lock.moveAbsolute(90, 200);


  chassis.MotionController.setTarget("0.1", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("0.1", true);
  chassis.MotionController.waitUntilSettled();


  pros::delay(1500);

  intake.motors.moveVelocity(0);

  intake.motors.moveRelative(-50, 100);


  pros::delay(750);

  tray.tilt.moveAbsolute(400, 180);

  tray.arm_motors.moveAbsolute(650, 150);

  // chassis.MotionController.removePath("0.1");
  chassis.MotionController.setTarget("2", false);
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{2_in,0_in,0_deg}}, "3");
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{31_in,20_in,0_deg}}, "3NEW");
  chassis.MotionController.waitUntilSettled();

  intake.motors.moveRelative(-280, 100);

  // chassis.MotionController.setTarget("3", true);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{36_in,0_in,0_deg}}, "4");
  chassis.MotionController.waitUntilSettled();

  chassis.driveController.setMaxVelocity(10);
  chassis.driveController.turnAngle(-152.5_deg);
  chassis.driveController.setMaxVelocity(200);

  tray.tilt.moveAbsolute(0, 180);
  tray.arm_motors.moveAbsolute(-40, 180);

  pros::delay(750);

  intake.motors.moveVelocity(20);

  chassis.MotionController.setTarget("4", false);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{8_in,0_in,0_deg}}, "5");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("5", true);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{9_in,0_in,0_deg}}, "6");
  chassis.MotionController.waitUntilSettled();

  pros::delay(800);

  intake.motors.moveVelocity(0);

  intake.motors.moveRelative(-50, 100);


  pros::delay(750);


  tray.tilt.moveAbsolute(400, 180);

  tray.arm_motors.moveAbsolute(850, 150);

  pros::delay(1750);

  chassis.MotionController.setTarget("6", false);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{22_in,6_in,0_deg}}, "7");
  chassis.MotionController.waitUntilSettled();



  intake.motors.moveRelative(-580, 180);
  pros::delay(1500);

  tray.tilt.moveAbsolute(0, 180);
  tray.arm_motors.moveAbsolute(-40, 180);

  chassis.MotionController.setTarget("7", true);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6_in,6_in,90_deg}}, "7.5");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("7.5", true);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{4_in,0_in,0_deg}}, "8");
  chassis.MotionController.waitUntilSettled();

  chassis.driveController.setMaxVelocity(10);
  chassis.driveController.turnAngle(18_deg);
  chassis.driveController.setMaxVelocity(200);
//
  tray.cube_lock.moveAbsolute(0, 200);

  intake.motors.moveVelocity(150);

  chassis.MotionController.setTarget("8", false);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{4_in,0_in,0_deg}}, "8");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  intake.motors.moveVelocity(20);

  tray.cube_lock.moveAbsolute(90, 200);


  chassis.MotionController.setTarget("8", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("8", true);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{6_in,0_in,0_deg}}, "8");
  chassis.MotionController.waitUntilSettled();

  chassis.driveController.setMaxVelocity(10);
  chassis.driveController.turnAngle(-45_deg);
  chassis.driveController.setMaxVelocity(200);

  chassis.MotionController.setTarget("8", true);
  chassis.MotionController.waitUntilSettled();


  pros::delay(100);

  intake.motors.moveVelocity(0);

  intake.motors.moveRelative(-50, 100);


  pros::delay(750);


  tray.tilt.moveAbsolute(400, 180);

  tray.arm_motors.moveAbsolute(650, 150);

  pros::delay(1750);

  chassis.MotionController.setTarget("8", false);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{25_in,0_in,0_deg}}, "7");
  chassis.MotionController.waitUntilSettled();



  intake.motors.moveRelative(-380, 100);
  pros::delay(1500);

  tray.tilt.moveAbsolute(0, 180);
  tray.arm_motors.moveAbsolute(-40, 180);

  chassis.MotionController.setTarget("7", true);





  pros::delay(99999999);



  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();


  chassis.MotionController.removePath("2");
  chassis.MotionController.setTarget("3", true);
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{10_in,0_in,0_deg}}, "4");
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{4_in,0_in,0_deg}}, "4.5");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("3.5", false);
  chassis.MotionController.waitUntilSettled();


  chassis.MotionController.removePath("3");
  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("FORWARD CUBE LENGTH", false);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{17.5_in,-15_in,88_deg}}, "4");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("4", true);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{30_in,0_in,0_deg}}, "5");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("5", false);
  chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{44_in,-16_in,0_deg}}, "6");
  chassis.MotionController.waitUntilSettled();

  chassis.MotionController.setTarget("6", false);
  // chassis.MotionController.generatePath({Point{0_in,0_in,0_deg}, Point{42_in,16_in,45_deg}}, "7");
  chassis.MotionController.waitUntilSettled();

  chassis.driveController.setMaxVelocity(15);
  chassis.driveController.turnAngle(-45_deg);

  chassis.driveController.setMaxVelocity(200);



  chassis.driveController.driveVector(0.4, 0);
  pros::delay(1800);
  chassis.driveController.stop();
  pros::delay(150);
  chassis.driveController.driveVector(-0.16, 0);
  pros::delay(450);
  chassis.driveController.stop();
  pros::delay(150);

  intake.motors.moveVelocity(0);
  tray.tilt.moveAbsolute(1320, 180);
  pros::delay(700);
  tray.tilt.moveAbsolute(1320, 50);

  pros::delay(2500);
  intake.motors.moveVelocity(-10);

  tray.tilt.moveAbsolute(1370, 30);
  pros::delay(2000);
  tray.tilt.moveAbsolute(1370, 40);
  pros::delay(2000);


  chassis.driveController.driveVector(0.05, 0);
  pros::delay(2500);
  chassis.driveController.stop();
  pros::delay(150);

  intake.motors.setBrakeMode(AbstractMotor::brakeMode::hold);
  tray.tilt.moveAbsolute(0, 200);
  pros::delay(3500);

  tray.arm_motors.moveAbsolute(0, 80);
  pros::delay(400);
  intake.motors.moveVelocity(-40);

  chassis.driveController.driveVector(-0.1, 0);
  pros::delay(350);

  chassis.driveController.driveVector(-0.5, 0.1);//0.1
  pros::delay(1000);

  intake.motors.setBrakeMode(AbstractMotor::brakeMode::coast);
  chassis.driveController.stop();
  intake.motors.moveVelocity(0);























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


//------------------------------------------------------------------------------
//===================================END FILE===================================
//==============================================================================
