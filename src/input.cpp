#include <fstream>
#include <iostream>
#include "input.hpp"

pros::Controller Controller_1(pros::E_CONTROLLER_MASTER);
pros::Controller Controller_2(pros::E_CONTROLLER_MASTER);
Profile Active_Profile;

std::string action_list[]
{
  "a", // Action 1
  "b" // Action 2
};

std::map<controller_input, int> controller_1_values;
std::map<controller_input, int> controller_2_values;



void update_controller_values(void *)
{
  // Controller 1
  // Analog Joysticks
  controller_1_values[LX] = Controller_1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
  controller_1_values[LY] = Controller_1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  controller_1_values[RX] = Controller_1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
  controller_1_values[RY] = Controller_1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

  // Digital Buttons
  controller_1_values[A] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  controller_1_values[B] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_B);
  controller_1_values[X] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_X);
  controller_1_values[Y] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
  controller_1_values[U] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  controller_1_values[D] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  controller_1_values[L] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
  controller_1_values[R] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
  controller_1_values[L1] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  controller_1_values[L2] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  controller_1_values[R1] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
  controller_1_values[R2] = Controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

  // Controller 2
  // Analog Joysticks
  controller_2_values[LX] = Controller_2.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
  controller_2_values[LY] = Controller_2.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  controller_2_values[RX] = Controller_2.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
  controller_2_values[RY] = Controller_2.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

  // Digital Buttons
  controller_2_values[A] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  controller_2_values[B] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_B);
  controller_2_values[X] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_X);
  controller_2_values[Y] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
  controller_2_values[U] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  controller_2_values[D] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  controller_2_values[L] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
  controller_2_values[R] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
  controller_2_values[L1] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  controller_2_values[L2] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  controller_2_values[R1] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
  controller_2_values[R2] = Controller_2.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
}

void update_sensor_values(void *)
{

}

void Profile::set_layout(std::string profile_file_name)
{
  std::string line;
  std::ifstream profile_file( "profile-" + profile_file_name + ".csv" );
  std::string controller_num;
  std::string action;
  std::string value;
  std::pair<pros::Controller*, controller_input> ci;

  if (profile_file)  // same as: if (profile_file.good())
  {
    while (getline(profile_file, controller_num, ','))
    {
      //cout << "ID: " << ID << " " ;

      getline(profile_file, action, ',');

      getline(profile_file, value);
      //cout << "Sexo: " <<  genero<< " "  ;

      if(!value.empty())
      {
        if(controller_num.compare("Controller 1") == 0)
        {
          if(value.compare("LX") == 0)      ci = std::make_pair(&Controller_1,LX);
          else if(value.compare("LY") == 0) ci = std::make_pair(&Controller_1,LY);
          else if(value.compare("RX") == 0) ci = std::make_pair(&Controller_1,RX);
          else if(value.compare("RY") == 0) ci = std::make_pair(&Controller_1,RY);
          else if(value.compare("A") == 0)  ci = std::make_pair(&Controller_1,A);
          else if(value.compare("B") == 0)  ci = std::make_pair(&Controller_1,B);
          else if(value.compare("X") == 0)  ci = std::make_pair(&Controller_1,X);
          else if(value.compare("Y") == 0)  ci = std::make_pair(&Controller_1,Y);
          else if(value.compare("U") == 0)  ci = std::make_pair(&Controller_1,U);
          else if(value.compare("D") == 0)  ci = std::make_pair(&Controller_1,D);
          else if(value.compare("L") == 0)  ci = std::make_pair(&Controller_1,L);
          else if(value.compare("R") == 0)  ci = std::make_pair(&Controller_1,R);
          else if(value.compare("L1") == 0) ci = std::make_pair(&Controller_1,L1);
          else if(value.compare("L2") == 0) ci = std::make_pair(&Controller_1,L2);
          else if(value.compare("R1") == 0) ci = std::make_pair(&Controller_1,R1);
          else if(value.compare("R2") == 0) ci = std::make_pair(&Controller_1,R2);

          for(int i = 0; i < sizeof(action_list)/sizeof(*action_list); i++)
          {
            if(action.compare(action_list[i]) == 0)
            {
              button_map[action_list[i]] = ci;
            }
          }
        }
        else if(controller_num.compare("Controller 2") == 0)
        {
          if(value.compare("LX") == 0)      ci = std::make_pair(&Controller_2,LX);
          else if(value.compare("LY") == 0) ci = std::make_pair(&Controller_2,LY);
          else if(value.compare("RX") == 0) ci = std::make_pair(&Controller_2,RX);
          else if(value.compare("RY") == 0) ci = std::make_pair(&Controller_2,RY);
          else if(value.compare("A") == 0)  ci = std::make_pair(&Controller_2,A);
          else if(value.compare("B") == 0)  ci = std::make_pair(&Controller_2,B);
          else if(value.compare("X") == 0)  ci = std::make_pair(&Controller_2,X);
          else if(value.compare("Y") == 0)  ci = std::make_pair(&Controller_2,Y);
          else if(value.compare("U") == 0)  ci = std::make_pair(&Controller_2,U);
          else if(value.compare("D") == 0)  ci = std::make_pair(&Controller_2,D);
          else if(value.compare("L") == 0)  ci = std::make_pair(&Controller_2,L);
          else if(value.compare("R") == 0)  ci = std::make_pair(&Controller_2,R);
          else if(value.compare("L1") == 0) ci = std::make_pair(&Controller_2,L1);
          else if(value.compare("L2") == 0) ci = std::make_pair(&Controller_2,L2);
          else if(value.compare("R1") == 0) ci = std::make_pair(&Controller_2,R1);
          else if(value.compare("R2") == 0) ci = std::make_pair(&Controller_2,R2);

          for(int i = 0; i < sizeof(action_list)/sizeof(*action_list); i++)
          {
            if(action.compare(action_list[i]) == 0)
            {
              button_map[action_list[i]] = ci;
            }
          }
        }

        for(int i = 0; i < sizeof(action_list)/sizeof(*action_list); i++)
        {
          if(!button_map.count(action_list[i])) // Action not assigned to btn map
          {
            button_map[action_list[i]] = std::make_pair(&Controller_1,Not_Assigned);
          }
        }
      }
    }
    profile_file.close();
  }
}

Profile::Profile(std::string profile_file_name)
{
  this->profile_file_name = profile_file_name;
  set_layout(this->profile_file_name);
}
