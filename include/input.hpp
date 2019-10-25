#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include "api.h"
#include <string>
#include <map>

enum controller_input
{
  LX,
  LY,
  RX,
  RY,
  A,
  B,
  X,
  Y,
  U,
  D,
  L,
  R,
  L1,
  L2,
  R1,
  R2,
  Not_Assigned
};

extern pros::Controller Controller_1;
extern pros::Controller Controller_2;
extern std::string action_list[];
extern std::map<controller_input, int> controller_1_values;
extern std::map<controller_input, int> controller_2_values;

extern void update_controller_values(void *);
extern void update_sensor_values(void *);

class Profile
{
  private:
    std::string profile_file_name;
  public:
    std::string drive_type;
    std::map<std::string, std::pair<pros::Controller*, controller_input> >button_map;
    void set_layout(std::string profile_file_name);
    Profile(std::string profile_file_name = "Default");
};

extern Profile Active_Profile;


#endif
