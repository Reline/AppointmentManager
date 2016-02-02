#include "MyTime.h"

// CONSTRUCTORS
 
// Default (explicit)
MyTime::MyTime()
{
	_ticks = 0;
}
 
// Copy
MyTime::MyTime(const MyTime & origMyTime)
{
	_ticks = origMyTime._ticks;
}
 
// Parameterized (various useful overloads)
    // Hours, Minutes, Seconds, Miliseconds
MyTime::MyTime(int initHours, int initMins, int initSecs, int initMilisecs)
{
	if (initHours < 0 || initHours > 23 || initMins < 0 || initMins > 59 || initSecs < 0 || initSecs > 59 || initMilisecs < 0 || initMilisecs > 999)
		throw "Error: Index out of range.";

	int hours = initHours * _ticksPerHour;
	int minutes = initMins * _ticksPerMinute;
	int seconds = initSecs * _ticksPerSecond;
	int milliseconds = initMilisecs;
	_ticks = hours + minutes + seconds + milliseconds;
}

    // Hours, Minutes, Seconds
MyTime::MyTime(int initHours, int initMins, int initSecs)
{
	if (initHours < 0 || initHours > 23 || initMins < 0 || initMins > 59 || initSecs < 0 || initSecs > 59)
		throw "Error: Index out of range.";

	int hours = initHours * _ticksPerHour;
	int minutes = initMins * _ticksPerMinute;
	int seconds = initSecs * _ticksPerSecond;
	_ticks = hours + minutes + seconds;
}

    // Hours, Minutes
MyTime::MyTime(int initHours, int initMins)
{
	if (initHours < 0 || initHours > 23 || initMins < 0 || initMins > 59)
		throw "Error: Index out of range.";

	int hours = initHours * _ticksPerHour;
	int minutes = initMins * _ticksPerMinute;
	_ticks = hours + minutes;
}

    // Ticks
MyTime::MyTime(long initTicks)
{
	_ticks = initTicks % _ticksPerDay; // does this need to be done everywhere? what does it exactly do?
}
 
// DESTRUCTOR
MyTime::~MyTime(){}
 
// METHODS
 
// Accessors and mutators for:
// hours, minutes, seconds, ticks
int MyTime::GetHours() const
{
	int tempTicks = _ticks % _ticksPerDay;
	int hours = tempTicks / _ticksPerHour;
	return hours;
}

void MyTime::SetHours(int newHours)
{
	if (newHours < 0 || newHours > 23)
		throw "Error: Index out of range.";

	int hours = GetHours();
	_ticks -= hours * _ticksPerHour;
	_ticks += (newHours * _ticksPerHour);
}
 
int MyTime::GetMinutes() const
{
	int ticksMinusDays = _ticks % _ticksPerDay;
	int ticksMinusHours = ticksMinusDays % _ticksPerHour;
	int minutes = ticksMinusHours / _ticksPerMinute;
	return minutes;
}

void MyTime::SetMinutes(int newMinutes)
{
	if (newMinutes < 0 || newMinutes > 59)
		throw "Error: Index out of range.";

	int minutes = GetMinutes();
	_ticks -= minutes * _ticksPerMinute;
	_ticks += (newMinutes * _ticksPerMinute);
}
 
int MyTime::GetSeconds() const
{
	int ticksMinusDays = _ticks % _ticksPerDay;
	int ticksMinusHours = ticksMinusDays % _ticksPerHour;
	int ticksMinusMinutes = ticksMinusHours % _ticksPerMinute;
	int seconds = ticksMinusMinutes / _ticksPerSecond;
	return seconds;
}

void MyTime::SetSeconds(int newSeconds)
{
	if (newSeconds < 0 || newSeconds > 59)
		throw "Error: Index out of range.";

	int seconds = GetSeconds();
	_ticks -= (seconds * _ticksPerSecond);
	_ticks += (newSeconds * _ticksPerSecond);
}
 
long MyTime::GetTicks() const
{
	int ticksMinusDays = _ticks % _ticksPerDay;
	int ticksMinusHours = ticksMinusDays % _ticksPerHour;
	int ticksMinusMinutes = ticksMinusHours % _ticksPerMinute;
	int milliseconds = ticksMinusMinutes % _ticksPerSecond;
	return milliseconds;
}

void MyTime::SetTicks(int newTicks)
{
	int milliseconds = GetTicks();
	_ticks -= milliseconds;
	_ticks += newTicks;
}
 
 
// SetTime (various useful overloads)
    // Hours, Minutes, Seconds, Miliseconds
void MyTime::SetTime(int newHrs, int newMins, int newSecs, int newMilisecs)
{
	if (newHrs < 0 || newHrs > 23 || newMins < 0 || newMins > 59 || newSecs < 0 || newSecs > 59 || newMilisecs < 0 || newMilisecs > 999)
		throw "Error: Index out of range.";

	int hours = newHrs * _ticksPerHour;
	int minutes = newMins * _ticksPerMinute;
	int seconds = newSecs * _ticksPerSecond;
	int milliseconds = newMilisecs;
	_ticks = hours + minutes + seconds + milliseconds;
}
    // Hours, Minutes, Seconds
void MyTime::SetTime(int newHrs, int newMins, int newSecs)
{
	if (newHrs < 0 || newHrs > 23 || newMins < 0 || newMins > 59 || newSecs < 0 || newSecs > 59)
		throw "Error: Index out of range.";

	int hours = newHrs * _ticksPerHour;
	int minutes = newMins * _ticksPerMinute;
	int seconds = newSecs * _ticksPerSecond;
	_ticks = hours + minutes + seconds;
}
    // Hours, Minutes
void MyTime::SetTime(int newHrs, int newMins)
{
	if (newHrs < 0 || newHrs > 23 || newMins < 0 || newMins > 59)
		throw "Error: Index out of range.";

	int hours = newHrs * _ticksPerHour;
	int minutes = newMins * _ticksPerMinute;
	_ticks = hours + minutes;
}
    // Ticks
void MyTime::SetTime(long newTicks)
{
	_ticks = newTicks;
}
    // MyTime
void MyTime::SetTime(const MyTime & aMyTime)
{
	_ticks = aMyTime._ticks;
}

//GET TIME FUNCTION

long MyTime::GetTime() const
{
	return _ticks;
}
 
// Now
// a static function that returns a MyTime object
//   initialized to the current time according to the system clock
MyTime MyTime::Now()
{
	MyTime newTime;
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	// set the newTime._ticks to the timeinfo ticks amount
	newTime.SetTime(timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
	return newTime;
}
 
// Add (various useful methods)
// For adding amounts of time to this MyTime
    // Hours
void MyTime::AddHours(int moreHours)
{
	_ticks += (moreHours * _ticksPerHour);
}
    // Minutes
void MyTime::AddMinutes(int moreMinutes)
{
	_ticks += (moreMinutes * _ticksPerMinute);
}
    // Seconds
void MyTime::AddSeconds(long moreSeconds)
{
	_ticks += (moreSeconds * _ticksPerSecond);
}
    // Ticks
void MyTime::AddTicks(long moreTicks)
{
	_ticks += moreTicks;
}
    // MyTime
void MyTime::AddTime(const MyTime & aMyTime)
{
	_ticks += aMyTime._ticks;
}
 
// Compare
// Takes a MyTime argument
// Returns (zero) if the argument has the same time as this MyTime
// Returns (a positive int)  if the argument is before this MyTime
// Returns (a negative int)  if the argument is after this MyTime
int MyTime::Compare(const MyTime & aMyTime) const
{
	if (_ticks > aMyTime._ticks)
	{
		return 1;
	}
	else if (_ticks < aMyTime._ticks)
	{
		return -1;
	}
	return 0;
}
 
// Equals
// Takes a MyTime argument
// Returns (true) if the argument has the same time
//   as this MyTime, otherwise it returns (false).
bool MyTime::Equals(const MyTime & aMyTime) const
{
	if (_ticks == aMyTime._ticks)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
// Subtract (various useful methods)
// For subtracting amounts of time to this MyTime    
    // Hours
void MyTime::SubtractHours(int lessHours)
{
	_ticks -= (lessHours * _ticksPerHour);
}
    // Minutes
void MyTime::SubtractMinutes(int lessMinutes)
{
	_ticks -= (lessMinutes * _ticksPerMinute);
}
    // Seconds
void MyTime::SubtractSeconds(long lessSeconds)
{
	_ticks -= (lessSeconds * _ticksPerSecond);
}
    // Ticks
void MyTime::SubtractTicks(long lessTicks)
{
	_ticks -= lessTicks;
}
    // MyTime
void MyTime::SubtractTime(const MyTime & aMyTime)
{
	_ticks -= aMyTime._ticks;
}
 
// OVERLOADED OPERATORS
 
// = (assignment - takes a MyTime)
MyTime MyTime::operator= (const MyTime & aMyTime)
{
	SetTime(aMyTime);
	return *this;
}
 
// +, += (Addition - takes a MyTime)
MyTime MyTime::operator+ (const MyTime & aMyTime) const
{
	MyTime temp;
	temp.SetTime(_ticks);
	temp.AddTime(aMyTime);
	return temp;
}

MyTime MyTime::operator+= (const MyTime & aMyTime)
{
	AddTime(aMyTime);
	return *this;
}
 
 
// >, <, >=, <=, ==, != (boolean relational test operators)
bool MyTime::operator> (const MyTime & aMyTime) const 
{
	if (_ticks > aMyTime._ticks)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyTime::operator< (const MyTime & aMyTime) const 
{
	if (_ticks < aMyTime._ticks)
	{
		return true;
	}
	else
		return false;
}

bool MyTime::operator>= (const MyTime & aMyTime) const 
{
	if (_ticks >= aMyTime._ticks)
	{
		return true;
	}
	return false;
}

bool MyTime::operator<= (const MyTime & aMyTime) const 
{
	if (_ticks <= aMyTime._ticks)
	{
		return true;
	}
	return false;
}

bool MyTime::operator== (const MyTime & aMyTime) const 
{
	if (_ticks == aMyTime._ticks)
	{
		return true;
	}
	return false;
}

bool MyTime::operator!= (const MyTime & aMyTime) const 
{
	if (_ticks != aMyTime._ticks)
	{
		return true;
	}
	return false;
}
 
// <<, >> stream insertion and extraction
ostream & operator<< (ostream & os, const MyTime & aMyTime)
{
	os << aMyTime.GetTicks();
	return os;
}
 
istream & operator>> (istream & is, MyTime & aMyTime)
{
	const int BUFFER_SIZE = 15;
	char bucket[BUFFER_SIZE];
	//char * bucket = new char [];
	//is >> bucket;

	do
	{
		is.get(bucket, BUFFER_SIZE);
	}while(strlen(bucket) == (BUFFER_SIZE - 1));

	int i = 0;
	int Hours = 0;
	int Minutes = 0;
	int Seconds = 0;
	int Milliseconds = 0;
	char *userHours = new char [2];
	char *userMinutes = new char [2];
	char *userSeconds = new char [2];
	char *userMilliseconds = new char [2];

	for (int hr = 0; bucket[i] != ':' && bucket[i] != '\0'; hr++)
	{
		userHours[hr] = bucket[i];
		i++;
	}
	Hours = atoi(userHours);
	i++;

	for (int min = 0; bucket[i] != ':' && bucket[i] != '\0'; min++)
	{
		userMinutes[min] = bucket[i];
		i++;
	}
	Minutes = atoi(userMinutes);
	i++;

	for (int sec = 0; bucket[i] != ':' && bucket[i] != '\0'; sec++)
	{
		userSeconds[sec] = bucket[i];
		i++;
	}
	Seconds = atoi(userSeconds);
	i++;

	for (int mill = 0; bucket[i] != '\0'; mill++)
	{
		userMilliseconds[mill] = bucket[i];
		i++;
	}
	Milliseconds = atoi(userMilliseconds);

	aMyTime._ticks += (Hours * aMyTime._ticksPerHour);
	aMyTime._ticks += (Minutes * aMyTime._ticksPerMinute);
	aMyTime._ticks += (Seconds * aMyTime._ticksPerSecond);
	aMyTime._ticks += Milliseconds;

	if (aMyTime._ticks > aMyTime._ticksPerDay)
	{
		throw "Error: Index out of range.";
	}

	return is;
}

std::string MyTime::displayClock()
{
	std::string hour;
	std::string minute;
	std::string second;
	std::string milliseconds;
	std::string clock;

	hour = std::to_string(GetHours());
	minute = std::to_string(GetMinutes());
	second = std::to_string(GetSeconds());
	milliseconds = std::to_string(GetTicks());

	if (GetHours() < 10)
	{
		hour.insert(0, "0");
	}
	if (GetMinutes() < 10)
	{
		minute.insert(0, "0");
	}
	if (GetSeconds() < 10)
	{
		second.insert(0, "0");
	}
	if (GetTicks() < 10)
	{
		milliseconds.insert(0, "0");
	}

	clock = hour + ":" + minute + ":" + second + ":" + milliseconds;
	return clock;
}