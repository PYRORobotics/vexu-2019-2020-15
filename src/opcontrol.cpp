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
