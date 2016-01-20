#include "Appointment.h"

//CONSTRUCTORS
Appointment::Appointment()
{
	MyDate apptDate;
	MyTime apptTime;
	MyString description;
}

Appointment::Appointment(MyDate apptDate, MyTime apptTime)
{
	this->apptDate = apptDate;
	this->apptTime = apptTime;
}

Appointment::Appointment(MyTime apptTime, MyDate apptDate)
{
	this->apptDate = apptDate;
	this->apptTime = apptTime;
}

Appointment::~Appointment()
{
	// 
}

void Appointment::setApptDate(int apptDay, int apptMonth, int apptYear)
{
	apptDate.SetDate(apptDay, apptMonth, apptYear);
}

void Appointment::setApptTime(int apptMin, int apptHour)
{
	apptTime.SetTime(apptHour, apptMin);
}

void Appointment::setDesc(MyString newDesc)
{
	this->description = newDesc;
}

int Appointment::getApptDay()
{
	return this->apptDate.GetDay();
}

int Appointment::getApptMonth()
{
	return this->apptDate.GetMonth();
}

int Appointment::getApptYear()
{
	return this->apptDate.GetYear();
}

int Appointment::getApptHour()
{
	return this->apptTime.GetHours();
}

int Appointment::getApptMin()
{
	return this->apptTime.GetMinutes();
}

MyString Appointment::getDesc()
{
	return this->description;
}

int Appointment::getDateSerial() const
{
	return this->apptDate.GetDateSerial();
}