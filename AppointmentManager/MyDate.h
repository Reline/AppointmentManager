// MyDate.h
 
// insure that this header file is not included more than once
#pragma once
#ifndef _MYDATE_H_
#define _MYDATE_H_
 
#include <iostream>
using std::ostream;
using std::istream;

#include <string>
#include <cstring>
#include <ctime>
 
class MyDate
{
private:
      //  0 _days = Jan 1st year 1 CE
      //  a date is stored as a number of days from jan 1st of the year 1
	int _days;
 
      // UTILITY FUNCTIONS
 
      // you might want to create some utility functions
 
public:
      enum DayOfWeek {Mon=0, Tue=1, Wed=2, Thr=3, Fri=4, Sat=5, Sun=6};
      enum MonthOfYear {Jan=1, Feb=2, Mar=3, Apr=4, May=5, Jun=6,
     Jul=7, Aug=8, Sep=9, Oct=10, Nov=11, Dec=12};

	  static int monthLengths[14]; // = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 367 };
	  static int leapLengths[14]; // = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 367 };
 
      // CONSTRUCTORS
      MyDate(); // default: sets date to jan 1, year 1
      MyDate(int day, int month, int year);
      MyDate(int days); // sets date to 'days' days from jan 1 year 1
      MyDate(MyDate & aMyDate); // copy constructor
 
      // METHODS
 
      static bool IsLeapYear(MyDate & aMyDate);
      static bool IsLeapYear(int year);
      bool IsLeapYear();// returns true if the current instance is a leapyear
 
      // Accessors and mutators for:
      // day, month, and year
      // returns int day of month
      int GetDay() ;
      // sets day of month (1-31)
      void SetDay(int newDay);
     
      // returns int month of year ( jan = 1 dec = 12)
      int GetMonth();
      // sets month of year ( jan = 1 dec = 12)
      void SetMonth(int newMonth);
 
      // returns int year
      int GetYear();
      // sets year
      void SetYear(int newYear);
 
      // writes a cstring representation
//   of the current day of the week to dayBuffer
      void GetDayName(char * dayBuffer);
      // writes a cstring representation
//   of the current month of the year to dayBuffer
      void GetMonthName(char * monthBuffer);
 
      // returns number of days since jan 1 year 1 for current instance date
      int GetDateSerial() const;
 
      // SetDate (various useful overloads)
            // Days
      void SetDate(int Days);
            // Day, Month Year
      void SetDate(int newDay, int newMonth, int newYear);
            // MyDate
      void SetDate(const MyDate & aMyDate);
 
      // Now
      // a static function that returns a MyDate object
//   initialized to the current date according to the system clock
      static MyDate Now();
 
      // Add (various useful functions)
      // For adding amounts of time to this MyDate
            // Years
      void AddYears(int moreYears);
            // Months
      void AddMonths(int moreMonths);
            // Day
      void AddDays(long moreDays);
            // MyDate
      void AddDate(const MyDate & aMyDate);
 
      // Compare
      // Takes a MyDate argument
      // Returns (zero) if the argument has the same time as this MyDate
      // Returns (a positive int)  if the argument is before this MyDate
      // Returns (a negative int)  if the argument is after this MyDate
      int Compare(const MyDate & aMyDate) const;
 
      // Equals
      // Takes a MyDate argument
      // Returns (true) if the argument has the same time
//   as this MyDate, otherwise it returns (false).
      bool Equals(const MyDate & aMyDate) const;
 
      // Subtract (various useful functions)
            // Years
      void SubtractYears(int lessYears);
            // Months
      void SubtractMonths(int lessMonths);
            // Days
      void SubtractDays(long lessDays);
            // MyDate
      void SubtractDate(const MyDate & aMyDate);
 
// OVERLOADED OPERATORS
 
      // = (assignment - takes a MyDate)
      MyDate operator= (const MyDate & aMyDate);
 
      // +, += (Addition - takes a MyDate)
      MyDate operator+ (const MyDate & aMyDate) const;
      MyDate operator+= (const MyDate & aMyDate);
 
      // >, <, >=, <=, ==, != (boolean relational test operators)
      bool operator> (const MyDate & aMyDate)  const;
      bool operator< (const MyDate & aMyDate)  const;
      bool operator>= (const MyDate & aMyDate)  const;
      bool operator<= (const MyDate & aMyDate)  const;
      bool operator== (const MyDate & aMyDate)  const;
      bool operator!= (const MyDate & aMyDate)  const;
 
      // <<, >> stream insertion and extraction
      friend ostream & operator<< (ostream & os, MyDate & aMyDate);
 
      // date must be one of these formats
      //    ???
      friend istream & operator>> (istream & is, MyDate & aMyDate);

	  std::string displayDate();
};
#endif