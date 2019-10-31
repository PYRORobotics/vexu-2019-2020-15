#ifndef _INTAKE_H_
#define _INTAKE_H_

#include "api.h"
#include "okapi/api.hpp"
#include "controller.h"

namespace okapi
{

  class PYROIntake {
    private:

      static okapi::MotorGroup motors;

    public:
      PYROIntake();
      static void teleop(void*)
      {
        pros::Controller controller_master(pros::E_CONTROLLER_MASTER);
        pros::Controller controller_partner(pros::E_CONTROLLER_PARTNER);
        while(1)
        {
          if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
          {
            motors.moveVelocity(600);
          }
          else if(controller_master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
          {
            motors.moveVelocity(-80);
          }
          else
          {
            motors.moveVelocity(0);
          }
          pros::delay(20);
        }
      }
    };
}

extern okapi::PYROIntake intake;


#endif
