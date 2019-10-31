#include "intake.h"
#include "init.h"

using namespace okapi;

PYROIntake intake;

MotorGroup PYROIntake::motors = {M_INTAKE_L,-M_INTAKE_R};

PYROIntake::PYROIntake()
{

}
