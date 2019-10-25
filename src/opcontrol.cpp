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
	pros::Controller master(pros::E_CONTROLLER_MASTER);
    okapi::ChassisControllerIntegrated driveController = okapi::ChassisControllerFactory::create(
            {7,9}, {18,19}
    );
	okapi::MotorGroup intake({1,-2});
	okapi::Motor ramp(3);
    okapi::Motor tilt(4);
    tilt.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
	while (true) {
        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
            intake.moveVoltage(12000);
        }
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
            intake.moveVoltage(-12000);
        }
        else{
            intake.moveVoltage(0);
        }

        driveController.tank((float) master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) / 127,
                             (float) -master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) / 127,
                             0.05);

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
            ramp.moveVoltage(12000);
        }
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
            ramp.moveVoltage(-12000);
        }
        else{
            ramp.moveVoltage(0);
        }

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
            tilt.moveVelocity(50);
        }
        else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
            tilt.moveVelocity(-50);
        }
        else{
            tilt.moveVelocity(0);
        }

		pros::delay(20);
	}
}
