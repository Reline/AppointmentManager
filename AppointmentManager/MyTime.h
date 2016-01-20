// MyTime.h
 
// insure that this header file is not included more than once
#pragma once
#ifndef _MYTIME_H_
#define _MYTIME_H_
#include <string>
#include <iostream>
#include <ctime>
using std::ostream;
using std::istream;
 
class MyTime
{
private:
      // 1 _ticks = 1/100 of a second
      // 0 _ticks = 00:00:00.00 i.e. 12:00am
      // a time is stored as a number of ticks since midnight
      // for example 1234567 ticks would be 3:25:45.67am
      long _ticks;
 
      // the following static fields might come in handy
      // 8,643,999 _ticks = 23:59:59.99 i.e. 11:59:59.99pm
      static const long _lastTickOfTheDay = 8639999;
      // 4,320,000 _ticks = 12:00:00.00 i.e 12pm i.e. noon
      static const long _noon = 4320000;
      // _ticks per second;
      static const long _ticksPerSecond  = 100;
      // _ticks per minute;
      static const long _ticksPerMinute = 6000;
      // _ticks per hour;
      static const long _ticksPerHour = 360000;
      // _ticks per day
      static const long _ticksPerDay = 8640000;
 
public:
// CONSTRUCTORS
 
      // Default (explicit)
      MyTime();
 
      // Copy
      MyTime(const MyTime & origMyTime);
 
      // Parameterized (various useful overloads)
            // Hours, Minutes, Seconds, Miliseconds
      MyTime(int initHrs, int initMins, int initSecs, int initMilisecs);
            // Hours, Minutes, Seconds
      MyTime(int initHours, int initMinutes, int initSeconds);
            // Hours, Minutes
      MyTime(int initHours, int initMinutes);
            // Ticks
      MyTime(long initTicks);
 
 
// DESTRUCTOR
      ~MyTime();
 
// METHODS
 
      // Accessors and mutators for:
      // hours, minutes, seconds, ticks
      int GetHours() const;
      void SetHours(int newHours);
 
      int GetMinutes() const;
      void SetMinutes(int newMinutes);
 
      int GetSeconds() const;
      void SetSeconds(int newSeconds);
 
      long GetTicks() const;
      void SetTicks(int newTicks);
 
 
      // SetTime (various useful overloads)
            // Hours, Minutes, Seconds, Miliseconds
      void SetTime(int newHrs, int newMins, int newSecs, int newMilisecs);
            // Hours, Minutes, Seconds
      void SetTime(int newHours, int newMinutes, int newSeconds);
            // Hours, Minutes
      void SetTime(int newHours, int newMinutes);
            // Ticks
      void SetTime(long newTicks);
            // MyTime
      void SetTime(const MyTime & aMyTime);

	  // PERSONAL GET TIME FUNCTION
	  // returns number of milliseconds
	  long GetTime() const;
 
      // Now
      // a static function that returns a MyTime object
//   initialized to the current time according to the system clock
      static MyTime Now();
 
      // Add (various useful methods)
      // For adding amounts of time to this MyTime
            // Hours
      void AddHours(int moreHours);
            // Minutes
      void AddMinutes(int moreMinutes);
            // Seconds
      void AddSeconds(long moreSeconds);
            // Ticks
      void AddTicks(long moreTicks);
            // MyTime
      void AddTime(const MyTime & aMyTime);
 
      // Compare
      // Takes a MyTime argument
      // Returns (zero) if the argument has the same time as this MyTime
      // Returns (a positive int)  if the argument is before this MyTime
      // Returns (a negative int)  if the argument is after this MyTime
      int Compare(const MyTime & aMyTime) const;
 
      // Equals
      // Takes a MyTime argument
      // Returns (true) if the argument has the same time
//   as this MyTime, otherwise it returns (false).
      bool Equals(const MyTime & aMyTime) const;
 
      // Subtract (various useful methods)
      // For subtracting amounts of time to this MyTime    
            // Hours
      void SubtractHours(int lessHours);
            // Minutes
      void SubtractMinutes(int lessMinutes);
            // Seconds
      void SubtractSeconds(long lessSeconds);
            // Ticks
      void SubtractTicks(long lessTicks);
            // MyTime
      void MyTime::SubtractTime(const MyTime & aMyTime);
 
// OVERLOADED OPERATORS
 
      // = (assignment - takes a MyTime)
      MyTime operator= (const MyTime & aMyTime);
 
      // +, += (Addition - takes a MyTime)
      MyTime operator+ (const MyTime & aMyTime) const;
      MyTime operator+= (const MyTime & aMyTime);
 
 
      // >, <, >=, <=, ==, != (boolean relational test operators)
      bool operator> (const MyTime & aMyTime) const ;
      bool operator< (const MyTime & aMyTime) const ;
      bool operator>= (const MyTime & aMyTime) const ;
      bool operator<= (const MyTime & aMyTime) const ;
      bool operator== (const MyTime & aMyTime) const ;
      bool operator!= (const MyTime & aMyTime) const ;
 
      // <<, >> stream insertion and extraction
      friend ostream & operator<< (ostream & os, const MyTime & aMyTime);
 
      friend istream & operator>> (istream & is, MyTime & aMyTime);

	  std::string displayClock();
};
#endif

