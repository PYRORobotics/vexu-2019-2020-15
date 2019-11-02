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
            tilt.moveVelocity(20);
          }
          else if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
          {
            //tilt.moveAbsolute(0, 50);
            tilt.moveVelocity(-20);
          }
          else
          {
            tilt.moveVelocity(0);
          }

          pros::delay(20);
        }
      }
    };
}

extern okapi::PYROTray tray;


#endif
