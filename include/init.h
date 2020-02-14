#ifndef INIT_H
#define INIT_H

#include "api.h"
#include "okapi/api.hpp"

#define M_CHASSIS_LF 6
#define M_CHASSIS_LR 7
#define M_CHASSIS_RF 9
#define M_CHASSIS_RR 10
#define M_INTAKE_L 1
#define M_INTAKE_R 2
#define M_TRAY_INTAKE 4
#define M_TRAY_TILT 3
#define M_TRAY_ARM_L 5
#define M_TRAY_ARM_R 15
#define M_TRAY_CUBELOCK 4



using namespace okapi;

extern void init_chassis();

#endif
