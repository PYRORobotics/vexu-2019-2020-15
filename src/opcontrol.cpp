#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	okapi::AverageFilter<250> avgFilterReset;

	while(1) // GUI Command
	{
		// std::cout << avgFilterReset.getOutput() << std::endl;
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X) && master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) && master.get_digital(pros::E_CONTROLLER_DIGITAL_A) && master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
			avgFilterReset.filter(1);
		else
		{
			for(int i = 0; i < 500; i++)
				avgFilterReset.filter(0);
		}

		if(avgFilterReset.getOutput() == 1)
		{
			// PYRO_Arduino::reset();
			for(int i = 0; i < 500; i++)
				avgFilterReset.filter(0);
		}


		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT))
		{
			lv_obj_set_hidden(Screen::Screen_Title_PYRO,1);
			lv_obj_set_hidden(Screen::Screen_Title_Btn_Continue,1);

			lv_obj_set_hidden(Screen::Screen_Competition_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Driver_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Auton_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Info_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Mode_Help_Label,0);


			lv_label_set_text(Screen::Screen_Mode_Title, "      Competition Mode");
			lv_obj_set_hidden(Screen::Screen_Mode_Title,0);
			lv_obj_set_hidden(Screen::Screen_Mode_BG,0);
			lv_obj_set_hidden(Screen::Screen_Field_Ready_Label,0);
			lv_obj_set_hidden(Screen::Screen_Red_Auton_Btns,0);
			lv_obj_set_hidden(Screen::Screen_Blue_Auton_Btns,0);
			lv_obj_set_hidden(Screen::Screen_Mode_REDBLUE_Label,0);
			lv_obj_set_hidden(Screen::Screen_Mode_Desc_Label,0);
			lv_obj_set_hidden(Screen::Screen_Auton_Start_Btn_Label,1);
			lv_obj_set_hidden(Screen::Screen_Driver_Start_Btn_Label,1);
			Screen::DriverEnabled = true;
			Screen::AutonEnabled = false;
			Screen::currentMode = Screen::Competition;

	    std::string str = "    Red " + std::string("1") + " Selected!";

	    lv_label_set_text(Screen::Screen_Mode_Desc_Label, str.c_str());
	    lv_label_set_text(Screen::Screen_Field_Ready_Label, "\n        Ready - Good Luck!");

      Screen::selectedAuton = red0;
		}
		else if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP))
		{
			lv_obj_set_hidden(Screen::Screen_Title_PYRO,1);
			lv_obj_set_hidden(Screen::Screen_Title_Btn_Continue,1);

			lv_obj_set_hidden(Screen::Screen_Competition_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Driver_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Auton_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Info_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Mode_Help_Label,0);


			lv_label_set_text(Screen::Screen_Mode_Title, "      Competition Mode");
			lv_obj_set_hidden(Screen::Screen_Mode_Title,0);
			lv_obj_set_hidden(Screen::Screen_Mode_BG,0);
			lv_obj_set_hidden(Screen::Screen_Field_Ready_Label,0);
			lv_obj_set_hidden(Screen::Screen_Red_Auton_Btns,0);
			lv_obj_set_hidden(Screen::Screen_Blue_Auton_Btns,0);
			lv_obj_set_hidden(Screen::Screen_Mode_REDBLUE_Label,0);
			lv_obj_set_hidden(Screen::Screen_Mode_Desc_Label,0);
			lv_obj_set_hidden(Screen::Screen_Auton_Start_Btn_Label,1);
			lv_obj_set_hidden(Screen::Screen_Driver_Start_Btn_Label,1);
			Screen::DriverEnabled = true;
			Screen::AutonEnabled = false;
			Screen::currentMode = Screen::Competition;

	    std::string str = "    Skills " + std::string("1") + " Selected!";

	    lv_label_set_text(Screen::Screen_Mode_Desc_Label, str.c_str());
	    lv_label_set_text(Screen::Screen_Field_Ready_Label, "\n        Ready - Good Luck!");

      Screen::selectedAuton = redSkills0;
		}
		else if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT))
		{
			lv_obj_set_hidden(Screen::Screen_Title_PYRO,1);
			lv_obj_set_hidden(Screen::Screen_Title_Btn_Continue,1);

			lv_obj_set_hidden(Screen::Screen_Competition_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Driver_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Auton_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Info_Btn_Main,0);
			lv_obj_set_hidden(Screen::Screen_Mode_Help_Label,0);

			
			lv_label_set_text(Screen::Screen_Mode_Title, "      Competition Mode");
			lv_obj_set_hidden(Screen::Screen_Mode_Title,0);
			lv_obj_set_hidden(Screen::Screen_Mode_BG,0);
			lv_obj_set_hidden(Screen::Screen_Field_Ready_Label,0);
			lv_obj_set_hidden(Screen::Screen_Red_Auton_Btns,0);
			lv_obj_set_hidden(Screen::Screen_Blue_Auton_Btns,0);
			lv_obj_set_hidden(Screen::Screen_Mode_REDBLUE_Label,0);
			lv_obj_set_hidden(Screen::Screen_Mode_Desc_Label,0);
			lv_obj_set_hidden(Screen::Screen_Auton_Start_Btn_Label,1);
			lv_obj_set_hidden(Screen::Screen_Driver_Start_Btn_Label,1);
			Screen::DriverEnabled = true;
			Screen::AutonEnabled = false;
			Screen::currentMode = Screen::Competition;

	    std::string str = "    Blue " + std::string("1") + " Selected!";

	    lv_label_set_text(Screen::Screen_Mode_Desc_Label, str.c_str());
	    lv_label_set_text(Screen::Screen_Field_Ready_Label, "\n        Ready - Good Luck!");

      Screen::selectedAuton = blue0;
		}




		if(Screen::DriverEnabled || !pros::competition::is_disabled())
		{
			// okapi::PYRO_Arduino::send("TELEOP");
			tray.t_trayteleop.resume();

			int startTime = pros::millis();

			if(Screen::Screen_Sponsors != NULL)
			lv_obj_set_hidden(Screen::Screen_Sponsors,1);


			bool arcade = false;
			bool voltageControl = false;

			// okapi::ADIEncoder LEFT('A', 'B', true);
			// okapi::ADIEncoder RIGHT('C', 'D');

			pros::Task intaketask(intake.teleop);
			// pros::Task traytask(tray.trayteleop);

			while (Screen::DriverEnabled || !pros::competition::is_disabled()) // Teleop
			{
				//printf("%f %f\n", LEFT.get(), RIGHT.get());
				chassis.driveController.arcade((float) master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) / 127,
															 (float) master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) / 127,
															 0.05);



			  // intake.teleop(NULL);
				// tray.teleop(NULL);



				if(pros::millis() > 60000 + startTime && pros::millis() < 60100 + startTime)
					// okapi::PYRO_Arduino::send("HURRYUP");

				if(pros::millis() > 74000 + startTime)
				// okapi::PYRO_Arduino::send("END");

				if(pros::millis() > 74850 + startTime)
				{
					lv_obj_set_hidden(Screen::Screen_Innovate,0);
				}

				pros::delay(20);
			}

		}
		else if(Screen::AutonEnabled)
		{
			if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
				autonomous();
		}

	pros::delay(20);
	}
}
