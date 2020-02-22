#ifndef _TRAY_H_
#define _TRAY_H_

#include "api.h"
#include "okapi/api.hpp"
#include "controller.h"
#include "init.h"
#include "intake.h"

namespace okapi
{

  class PYROTray {
    private:

      //static Motor intake;
      //static Motor tilt;

    public:
      // static Motor intake;
      static Motor tilt;
      // static Motor armL;
      // static Motor armR;
      static okapi::MotorGroup arm_motors;
      static Motor cube_lock;

      PYROTray();

      static void init()
      {
        // arm.setBrakeMode(AbstractMotor::brakeMode::hold);
        // arm.moveRelative(500, 180);
        // PYROIntake::motors.moveVelocity(-600);
        // tilt.moveAbsolute(3650, 180);
        // pros::delay(5000);
        // tilt.moveAbsolute(0, 200);
        // arm.moveRelative(0, 180);
        // PYROIntake::motors.moveVelocity(0);
      }

      static void trayteleop(void*)
      {
        pros::Controller controller_master(pros::E_CONTROLLER_MASTER);
        pros::Controller controller_partner(pros::E_CONTROLLER_PARTNER);
        bool up = false;
        while(1)
        {
          if((pros::competition::get_status() & COMPETITION_DISABLED) == false)
          {
            // if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
            // {
            //   PYROIntake::motors.moveVelocity(-600);
            // }
            // else if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
            // {
            //   PYROIntake::motors.moveVelocity(600);
            // }
            // else
            // {
            //   PYROIntake::motors.moveVelocity(0);
            // }

            if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
            {
              //tilt.moveAbsolute(30, 50);
              //tilt.moveVelocity(20);

              // int speed = 0.0011375 * tilt.getPosition() * tilt.getPosition()-0.91* tilt.getPosition()+200;
              // tilt.moveVelocity(80);
              tilt.moveAbsolute(1330, 180);
              pros::delay(1000);
              tilt.moveAbsolute(1330, 70);
              // tilt.moveVelocity(100);
              //
              // std::cout << tilt.getPosition() << std::endl;
            }
            else if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
            {
              //tilt.moveAbsolute(0, 50);
              //tilt.moveVelocity(-20);

              //old functionality
              // int speed = 0.0005 * tilt.getPosition() * tilt.getPosition()-0.4* tilt.getPosition()+100;
              // tilt.moveVelocity(-170);

              //new functionality: return to home
              // tilt.moveVelocity(0);
              tilt.moveAbsolute(0, 200);

              // tilt.moveVelocity(-100);
              //
              // std::cout << tilt.getPosition() << std::endl;


            }
            else
            {
              pros::delay(50);
              if(!(fabs(tilt.getActualVelocity()) > 0.5))
                tilt.moveVelocity(0);
            }

            if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_X) && !up)
            {
              tilt.move_absolute(100, 100);
              up = true;
            }
            else if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_X) && up)
            {
              tilt.move_absolute(0.5, 100);
              up = false;
            }

            if(ADIButton('A').isPressed())
            {
              arm_motors.tarePosition();
              arm_motors.setCurrentLimit(500);
            }
            else
            {
              arm_motors.setCurrentLimit(2500);
            }

            if(abs(controller_master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)) > 5)
            {
              if(controller_master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) > 0)
              {
                arm_motors.setCurrentLimit(2500);
              }
              else if(arm_motors.getTargetVelocity() < 0 && arm_motors.getPosition() < 30)
              {
                arm_motors.setCurrentLimit(100);
              }
              arm_motors.moveVelocity(controller_master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
            }
            else
            {
              arm_motors.moveVelocity(0);
            }


            if(arm_motors.getPosition() > 10)
            {
              cube_lock.setBrakeMode(AbstractMotor::brakeMode::brake);
              double angle = 90;
              // if(angle > 90) angle = 90;
              cube_lock.moveAbsolute(angle, 200);
            }
            else
            {
              cube_lock.setBrakeMode(AbstractMotor::brakeMode::brake);
              cube_lock.moveAbsolute(0, 100);
            }
          }

          pros::delay(20);
        }
      }
      pros::Task t_trayteleop;
    };
}

extern okapi::PYROTray tray;


#endif
