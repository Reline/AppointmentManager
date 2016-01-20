#include <iostream>
#include <fstream>
#include "conio.h"
#include "Appointment.h"
#include "MyArrayTemplate.h"
#include "MyDate.h"
#include "MyString.h"
#include "MyTime.h"

Appointment newAppointment()
{
	// SET APPOINTEE
	MyString descr;
	std::cout << "\nDescription: ";
	std::cin.ignore();
	std::cin >> descr;

	Appointment userAppointment = Appointment();

	// SET MYDATE
	int month;
	int day;
	int year;
	std::cout << "Month: ";
	std::cin >> month;
	std::cout << "Day: ";
	std::cin >> day;
	std::cout << "Year: ";
	std::cin >> year;

	if(std::cin)
	{
		userAppointment.setApptDate(day, month, year);
	}

	// SET MYTIME
	int hour;
	std::cout << "Hour: ";
	std::cin >> hour;
	int min;
	std::cout << "Min: ";
	std::cin >> min;

	if(std::cin)
	{
		userAppointment.setApptTime(min, hour);
	}

	userAppointment.setDesc(descr);
	return userAppointment;
}

MyDate newDate()
{
	MyDate userDate = MyDate();
	int month;
	std::cout << "Month: ";
	std::cin >> month;
	int day;
	std::cout << "Day: ";
	std::cin >> day;
	int year;
	std::cout << "Year: ";
	std::cin >> year;

	if(std::cin)
	{
		userDate.SetDate(day, month, year);
	}

	return userDate;
}

MyTime newTime()
{
	MyTime userTime = MyTime();
	int hour;
	std::cout << "Hour: ";
	std::cin >> hour;
	int minute;
	std::cout << "Minute: ";
	std::cin >> minute;

	if(std::cin)
	{
		userTime.SetTime(hour, minute);
	}

	return userTime;
}

void saveAppointments(MyArray<Appointment> &AppointmentManager, std::fstream &appointmentFile)
{
	appointmentFile.open("Appointments.txt", std::ios::app);
	if (appointmentFile.good())
	{
		if (appointmentFile.is_open())
		{
			for (int i = 0; i < AppointmentManager.Size(); i++)
			{
				appointmentFile << AppointmentManager[i].getDesc() << std::endl
					<< AppointmentManager[i].getApptMonth() << "/" << AppointmentManager[i].getApptDay() << "/" << AppointmentManager[i].getApptYear() << std::endl
					<< AppointmentManager[i].getApptHour() << ":" << AppointmentManager[i].getApptMin() << std::endl;
			}
		}
	}
	appointmentFile.close();
}

void loadAppointments(MyArray<Appointment> &AppointmentManager, std::fstream &appointmentFile)
{
	Appointment loadedAppointment;
	MyString loadedDescription = "None";
	MyDate loadedDate;
	MyTime loadedTime;

	appointmentFile.open("Appointments.txt", std::ios::app);
	if (appointmentFile.is_open())
	{
		std::cout << "APPOINTMENT FILE IS OPEN, BEGINNING WHILE LOOP" << std::endl; //DEBUG
		while(!appointmentFile.eof())
		{
			std::cout << appointmentFile.eof() << std::endl;
			appointmentFile >> loadedDescription;
			std::cout << "Stored " << loadedDescription << " as loadedDescription" << std::endl;

			//appointmentFile >> loadedDate;
			//std::cout << "Stored -" << loadedDate << "- as loadedDay" << std::endl;

			loadedAppointment.setDesc(loadedDescription);
			//loadedAppointment.setApptDate(loadedDate.GetDay(), loadedDate.GetMonth(), loadedDate.GetYear());
			//loadedAppointment.setApptTime(loadedTime.GetMinutes(), loadedTime.GetHours());

			AppointmentManager.Add(loadedAppointment);
		}

		std::cout << "Printing all apointments I just got from the file" << std::endl;
		for (int i = 0; i < AppointmentManager.Size(); i++)
		{
			std::cout << AppointmentManager[i].getDesc() << std::endl;
		}
	}
	appointmentFile.close();
}


int main()
{
	// You must create a simple appointment keeper application. 
	// This application will allow users to set appointments (with a given date, time, and description), 
	// delete appointments, change appointments, save appointments to a disk file, and load appointments from a disk file. 
	// The user will also be able to specify a start date and an end date, and list all appointments between those dates.

	MyArray<Appointment> AppointmentManager; // ARRAY OF APPOINTMENTS
	std::fstream appointmentFile;

	//loadAppointments(AppointmentManager, appointmentFile);

	bool runProgram = true;
	char userChar;
	MyString editAppointment;
	MyDate editDate;
	MyTime editTime;
	MyString removeAppointment;
	char editChoice;
	MyDate startDate;
	MyDate endDate;

	std::cout << "---------------------------------" << std::endl;
	std::cout << "-------APPOINTMENT MANAGER-------" << std::endl;
	std::cout << "---------------------------------" << std::endl << std::endl;
	
	do
	{
		std::cout << "1 ) Add an appointment" << std::endl;
		std::cout << "2 ) Edit an appointment" << std::endl;
		std::cout << "3 ) View appointments" << std::endl;
		std::cout << "4 ) Remove an appointment" << std::endl;
		std::cout << "5 ) End program and save appointments" << std::endl;
		//std::cout << "6 ) Clear all SAVED appointments" << std::endl;

		// does this program load the appointments automatically or by user option?

		std::cout << "\nWhat operation would you like to perform?" << std::endl;
		std::cin >> userChar;

		switch(userChar)
		{
			case '1': // add an appointment
				//std::cout << "RUNNING OPTION 1" << std::endl; //DEBUG
				AppointmentManager.Add(newAppointment());
				std::cout << std::endl;
				break;
			case '2': // edit an appointment
				//std::cout << "RUNNING OPTION 2" << std::endl; //DEBUG
				if (AppointmentManager.Size() == 0)
				{
					std::cout << "Sorry, there are no appointments to edit." << std::endl;
				}
				else
				{
					std::cout << "\nWhich appointment would you like to edit? (Enter description)" << std::endl;
					std::cin.ignore();
					std::cin >> editAppointment;
					for (int i = 0; i < AppointmentManager.Size(); i++)
					{
						if (editAppointment == AppointmentManager[i].getDesc())
						{
							std::cout << "\nWhat would you like to edit?" << std::endl << std::endl 
								<< "1 ) Description" << std::endl
								<< "2 ) Date" << std::endl
								<< "3 ) Time" << std::endl;

							std::cin >> editChoice;
							std::cin.ignore();
							switch(editChoice)
							{
								case '1':
									std::cout << "Enter new description: ";
									std::cin >> editAppointment;
									//std::cin.ignore();
									AppointmentManager[i].setDesc(editAppointment);
									break;
								case '2':
									std::cout << "Enter new date" << std::endl;
									editDate = newDate();
									AppointmentManager[i].setApptDate(editDate.GetDay(), editDate.GetMonth(), editDate.GetYear());
									break;
								case '3':
									std::cout << "Enter new time" << std::endl;
									editTime = newTime();
									AppointmentManager[i].setApptTime(editTime.GetMinutes(), editTime.GetHours());
									break;
							}
						}
						else if (i == AppointmentManager.Size())
						{
							std::cout << "Sorry, that appointment description does not exist." << std::endl;
						}
					}
				}
				break;
			case '3': // list all appointments between two dates
				//std::cout << "RUNNING OPTION 3" << std::endl; //DEBUG

				std::cout << "\nEnter the interval to view appointments." << std::endl << std::endl;
				std::cout << "Start date" << std::endl;
				startDate = newDate();
				std::cout << "\nEnd date" << std::endl;
				endDate = newDate();
				for (int n = 0; n < AppointmentManager.Size(); n++)
				{
					if (AppointmentManager[n].getDateSerial() >= startDate.GetDateSerial() && AppointmentManager[n].getDateSerial() <= endDate.GetDateSerial())
					{
						std::cout << "\nDescription: " << AppointmentManager[n].getDesc() << std::endl
							<< "Date: " << AppointmentManager[n].getApptMonth() << "/" 
							<< AppointmentManager[n].getApptDay() << "/" 
							<< AppointmentManager[n].getApptYear() << std::endl
							<< "Time: " << AppointmentManager[n].getApptHour() << ":" 
							<< AppointmentManager[n].getApptMin() << std::endl;
					}
				}
				std::cout << std::endl;

				break;
			case '4': // remove an appointment
				//std::cout << "RUNNING OPTION 4" << std::endl; //DEBUG

				std::cout << "\nWhich appointment would you like to remove? (Enter description)" << std::endl;
				std::cin.ignore();
				std::cin >> removeAppointment;
				for (int i = 0; i <= AppointmentManager.Size(); i++)
				{
					if (removeAppointment == AppointmentManager[i].getDesc())
					{
						AppointmentManager.RemoveAt(i);
					}
					else if (i == AppointmentManager.Size())
					{
						std::cout << "Sorry, that appointment description does not exist." << std::endl;
					}
				}

				break;
			/*case '6':
				appointmentFile.clear();
				break;*/
			case '5': // save to a disk file
				//std::cout << "RUNNING OPTION 6" << std::endl; //DEBUG

				saveAppointments(AppointmentManager, appointmentFile);

				/*myfile.open("name.txt");
				for (int i = 0; i < stringarray.size(); i++)
				{
					myfile.write << stringarray[i];
						myfile.write << "\n;
				}
				myfile.close();*/

				runProgram = false;
				break;
			default: // if the user doesn't enter a correct command...
				throw "up";
		}

	}while(runProgram);


	std::cout << std::endl;
	system("pause");																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																									
	return 0;
}