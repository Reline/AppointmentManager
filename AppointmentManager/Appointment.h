#pragma once
 
#include <iostream>
using std::ostream;
using std::istream;

#include "MyDate.h"
#include "MyTime.h"
#include "MyString.h"

class Appointment
{

private:
	MyDate apptDate;
	MyTime apptTime;
	MyString description;

public:
	//CONSTRUCTORS AND DESTRUCTOR
	Appointment();
	Appointment(MyDate apptDate, MyTime apptTime);
	Appointment(MyTime apptTime, MyDate apptDate);
	~Appointment();

	void setApptDate(int apptDay, int apptMonth, int apptYear);
	void setApptTime(int apptMin, int apptHour);
	void setDesc(MyString newDesc);
	int getApptDay();
	int getApptMonth();
	int getApptYear();
	int getApptHour();
	int getApptMin();
	int getDateSerial() const;
	MyString getDesc();
};