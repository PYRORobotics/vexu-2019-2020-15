#include "intake.h"
#include "tray.h"

using namespace okapi;

PYROTray tray;

Motor PYROTray::intake = M_TRAY_INTAKE;
Motor PYROTray::tilt = M_TRAY_TILT;

PYROTray::PYROTray()
{

}