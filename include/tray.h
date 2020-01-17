#ifndef _TRAY_H_
#define _TRAY_H_

#include "api.h"
#include "okapi/api.hpp"
#include "controller.h"
#include "init.h"

namespace okapi
{

  class PYROTray {
    private:

      //static Motor intake;
      //static Motor tilt;

    public:
      static Motor intake;
      static Motor tilt;
      PYROTray();
      static void teleop(void*)
      {
        pros::Controller controller_master(pros::E_CONTROLLER_MASTER);
        pros::Controller controller_partner(pros::E_CONTROLLER_PARTNER);
        bool up = false;
        while(1)
        {
          if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
          {
            intake.moveVelocity(-600);
          }
          else if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
          {
            intake.moveVelocity(600);
          }
          else
          {
            intake.moveVelocity(0);
          }

          if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
          {
            //tilt.moveAbsolute(30, 50);
            //tilt.moveVelocity(20);

            int speed = 0.0011375 * tilt.getPosition() * tilt.getPosition()-0.91* tilt.getPosition()+200;
            tilt.moveVelocity(speed);
          }
          else if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
          {
            //tilt.moveAbsolute(0, 50);
            //tilt.moveVelocity(-20);

            //old functionality
            // int speed = 0.0005 * tilt.getPosition() * tilt.getPosition()-0.4* tilt.getPosition()+100;
            // tilt.moveVelocity(-170);

            //new functionality: return to home
            tilt.moveVelocity(0);
            tilt.moveAbsolute(0, 80);

          }
          else
          {
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


          pros::delay(20);
        }
      }
    };
}

extern okapi::PYROTray tray;


#endif
