#include "intake.h"
#include "tray.h"

using namespace okapi;

PYROTray tray;

// Motor PYROTray::intake(M_TRAY_INTAKE);
Motor PYROTray::tilt(M_TRAY_TILT);
Motor PYROTray::cube_lock(M_TRAY_CUBELOCK);
// Motor PYROTray::armL(M_TRAY_ARM_L);
// Motor PYROTray::armR(M_TRAY_ARM_R);
okapi::MotorGroup PYROTray::arm_motors({M_TRAY_ARM_L,-M_TRAY_ARM_R});

PYROTray::PYROTray() : t_trayteleop(trayteleop,(void*)NULL, TASK_PRIORITY_DEFAULT,
                          TASK_STACK_DEPTH_DEFAULT, "task")
{

}
 
