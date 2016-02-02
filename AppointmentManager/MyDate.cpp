#include "MyDate.h"

int MyDate::monthLengths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 367 };
int MyDate::leapLengths[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 367 };

// CONSTRUCTORS
MyDate::MyDate() // default: sets date to jan 1, year 1
{
	_days = 0; // _days is how many days it has been since jan1, year1
}

MyDate::MyDate(int day, int month, int year)
{
	if (day < 0 || day > 31 || month > 12 || month < 0 || year < 0 || day > monthLengths[GetMonth()])
		throw "Error: Index out of range.";
	SetDate(day, month, year);
}

MyDate::MyDate(int days) // sets date to 'days' days from jan 1 year 1
{
	if (days < 0)
		throw "Error: Index out of range.";
	_days = days;
}

MyDate::MyDate(MyDate & aMyDate) // copy constructor
{
	_days = aMyDate.GetDateSerial();
}
 
// METHODS
 
bool MyDate::IsLeapYear(MyDate & aMyDate)
{
	int year = aMyDate.GetYear();
	return IsLeapYear(year);
}
bool MyDate::IsLeapYear(int year)
{
	if (year < 1)
		throw "Error: Index out of range.";
	return ((year % 100 != 0) && (year % 4 == 0) || (year % 400 == 0));
}
bool MyDate::IsLeapYear()// returns true if the current instance is a leapyear
{
	int year = GetYear();
	return IsLeapYear(year);
}

// Accessors and mutators for:
// day, month, and year
// returns int day of month
int MyDate::GetDay()
{
	int year;
	int month;
	int days = _days;
	int daysSubtracted;

	for (year = 1; days > 365; year++)
		if (IsLeapYear(year))
			days -= 366;
		else
			days -= 365;		

	days++;
	if (IsLeapYear())
	{
		for (month = 0; days > leapLengths[month]; ++month)
			days -= leapLengths[month];
	}
	else
	{
		for (month = 0; days > monthLengths[month]; ++month)
			days -= monthLengths[month];
	}
	
	return days;
}
// sets day of month (1-31)
void MyDate::SetDay(int newDay)
{
	int monthLengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (newDay > monthLengths[GetMonth()] || newDay < 1)
	{
		throw "Error: Index out of range";
	}

	int dayOfTheMonth = GetDay();
	if (dayOfTheMonth < newDay)
		_days += (newDay - dayOfTheMonth);
	else if (dayOfTheMonth > newDay)
		_days -= (dayOfTheMonth - newDay);
}
     
// returns int month of year ( jan = 1 dec = 12)
int MyDate::GetMonth()
{
	int month;
	int year = 0;
	int days = _days;
	int daysSubtracted;

	int monthLengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int leapLengths[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	do
	{
		year++;

		if (IsLeapYear(year))
			daysSubtracted = 366;
		else
			daysSubtracted = 365;

		days -= daysSubtracted;

	}while(year != GetYear());

	days += daysSubtracted + 1;

	if (IsLeapYear())
	{
		for (month = 1; days > leapLengths[month]; month++)
		{
			days -= leapLengths[month];
		}
	}
	else
	{
		for (month = 1; days > monthLengths[month]; month++)
		{
			days -= monthLengths[month];
		}
	}
	return month;
}
// sets month of year ( jan = 1 dec = 12)
void MyDate::SetMonth(int newMonth)
{
	int monthLengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int currentMonth = GetMonth();

	if (newMonth > 12 || newMonth < 1)
		throw "Error: Index out of range.";

	if (currentMonth < newMonth)
	{
		if (IsLeapYear() && (currentMonth <= 2) && (newMonth >= 3))
			_days++;
		for (currentMonth; currentMonth < newMonth; currentMonth++)
		{
			_days += monthLengths[currentMonth];
		}
	}
	else if (currentMonth > newMonth)
	{
		if (IsLeapYear() && (newMonth == 1) && (currentMonth >= 2))
			_days--;
		for (currentMonth; currentMonth > newMonth; currentMonth--)
		{
			_days -= monthLengths[currentMonth];
		}
	}
}
 
// returns int year
int MyDate::GetYear()
{
	int year = 0;
	int days = 0;
	int daysAdded;
	bool isLeapYear = false;
	bool yearFound = false;

	do
	{
		year++;

		if (IsLeapYear(year))
			daysAdded = 366;
		else
			daysAdded = 365;

		yearFound = (days <= _days && _days < days + daysAdded);

		days += daysAdded;

	}while(!yearFound);

	return year;

}
// sets year
void MyDate::SetYear(int newYear)
{
	if (newYear < 0)
		throw "Error: Index out of range.";
	int currentYear = GetYear();

	if (currentYear > newYear)
	{
		for (int i = currentYear; i > newYear; i--)
		{
			if (!(IsLeapYear(i)))
				_days -= 365;
			else
				_days -= 366;
		}
	}
	else if (currentYear < newYear)
	{
		for (int i = currentYear; i < newYear; i++)
		{
			if (!(IsLeapYear(i)))
				_days += 365;
			else
				_days += 366;
		}
	}
}
 
// writes a cstring representation
//   of the current day of the week to dayBuffer
void MyDate::GetDayName(char * dayBuffer)
{
	char * dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	int dayOfWeek = _days % 7;

	strcpy(dayBuffer, dayNames[dayOfWeek]);

}
// writes a cstring representation
//   of the current month of the year to dayBuffer
void MyDate::GetMonthName(char * monthBuffer)
{
	char * monthNames[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	strcpy(monthBuffer, monthNames[GetMonth()]);
}
 
// returns number of days since jan 1 year 1 for current instance date
int MyDate::GetDateSerial() const
{
	return _days;
}
 
// SetDate (various useful overloads)
    // Days
void MyDate::SetDate(int Days) // Set how many days it has been SINCE Jan 1, Year 1
{
	if (Days < 0)
		throw "Error: Index out of range.";
	_days = Days;
}
    // Day, Month Year
void MyDate::SetDate(int newDay, int newMonth, int newYear)
{
	if (newDay < 1 || newMonth < 1 || newMonth > 12 || newYear < 1)
		throw "Error: Index out of range.";
	SetYear(newYear);
	SetMonth(newMonth);
	SetDay(newDay);
}
    // MyDate
void MyDate::SetDate(const MyDate & aMyDate)
{
	SetDate(aMyDate.GetDateSerial());
}
 
// Now
// a static function that returns a MyDate object
//   initialized to the current date according to the system clock
MyDate MyDate::Now()
{
	MyDate newTime;
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	// set the newTime._ticks to the timeinfo ticks amount
	newTime.SetDate(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	return newTime;
}
 
// Add (various useful functions)
// For adding amounts of time to this MyDate
    // Years
void MyDate::AddYears(int moreYears)
{
	if (moreYears < 0)
		throw "Error: Index out of range.";
	int newYear = moreYears + GetYear();
	SetYear(newYear);
}
    // Months
void MyDate::AddMonths(int moreMonths)
{
	if (moreMonths < 0)
		throw "Error: Index out of range.";
	int newMonth = moreMonths + GetMonth();
	int newYear = GetYear();
	while(newMonth > 12)
	{
		newMonth -= 12;
		newYear++;
	}
	SetMonth(newMonth);
	SetYear(newYear);
}
    // Day
void MyDate::AddDays(long moreDays)
{
	if (moreDays < 0)
		throw "Error: Index out of range.";
	int monthLengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int newDay = moreDays + GetDay();
	int newMonth = GetMonth();
	int newYear = GetYear();

	while (monthLengths[GetMonth()] < newDay)
	{
		if (IsLeapYear())
		{
			monthLengths[2] = 29;
		}
		else
		{
			monthLengths[2] = 28;
		}
		newDay -= monthLengths[GetMonth()];
		newMonth++;
		while(newMonth > 12)
		{
			newMonth -= 12;
			newYear++;
		}
	}


	SetDay(newDay);
	SetMonth(newMonth);
	SetYear(newYear);
}
    // MyDate
void MyDate::AddDate(const MyDate & aMyDate)
{
	// do '=' operator overload function
	MyDate addDate(aMyDate.GetDateSerial());
	AddDays(addDate.GetDay());
	AddMonths(addDate.GetMonth());
	AddYears(addDate.GetYear());

}
 
// Compare
// Takes a MyDate argument
// Returns (zero) if the argument has the same time as this MyDate
// Returns (a positive int)  if the argument is before this MyDate
// Returns (a negative int)  if the argument is after this MyDate
int MyDate::Compare(const MyDate & aMyDate) const
{
	if (aMyDate._days > _days)
		return -1;
	else if (aMyDate._days < _days)
		return 1;
	else
		return 0;
}
 
// Equals
// Takes a MyDate argument
// Returns (true) if the argument has the same time
//   as this MyDate, otherwise it returns (false).
bool MyDate::Equals(const MyDate & aMyDate) const
{
	return (Compare(aMyDate) == 0);
}
 
// Subtract (various useful functions)
    // Years
void MyDate::SubtractYears(int lessYears)
{
	if (lessYears < 0)
		throw "Error: Index out of range.";
	SetYear(GetYear() - lessYears);
}
    // Months
void MyDate::SubtractMonths(int lessMonths)
{
	if (lessMonths < 0)
		throw "Error: Index out of range.";
	int newMonth = GetMonth() - lessMonths;
	int newYear = GetYear();
	while(newMonth < 0)
	{
		newMonth += 12;
		newYear--;
	}
	SetMonth(newMonth);
	SetYear(newYear);
}
    // Days
void MyDate::SubtractDays(long lessDays)
{
	if (lessDays < 0)
		throw "Error: Index out of range.";
	int monthLengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int newDay = GetDay();
	newDay -= lessDays;
	int newMonth = GetMonth();
	int newYear = GetYear();

	while (newDay < 1)
	{
		if (IsLeapYear())
			monthLengths[2] = 29;
		else
			monthLengths[2] = 28;

		newMonth = GetMonth() - 1;

		while (newMonth < 1)
		{
			newMonth += 12;
			newYear--;
		}

		newDay += monthLengths[newMonth];

		newMonth--;

	}
	SetYear(newYear);
	SetMonth(newMonth);
	SetDay(newDay);
}
    // MyDate
void MyDate::SubtractDate(const MyDate & aMyDate)
{
	int serial = aMyDate.GetDateSerial();
	MyDate subtractDate(aMyDate.GetDateSerial());
	int days = subtractDate.GetDay();
	int month = subtractDate.GetMonth();
	int year = subtractDate.GetYear();
	SubtractDays(subtractDate.GetDay());
	SubtractMonths(subtractDate.GetMonth());
	SubtractYears(subtractDate.GetYear());
}
 
// OVERLOADED OPERATORS
 
// = (assignment - takes a MyDate)
MyDate MyDate::operator= (const MyDate & aMyDate)
{
	SetDate(aMyDate.GetDateSerial());
	return *this;
}
 
// +, += (Addition - takes a MyDate)
MyDate MyDate::operator+ (const MyDate & aMyDate) const
{
	MyDate temp(aMyDate.GetDateSerial()+this->GetDateSerial());
	return temp;
}

MyDate MyDate::operator+= (const MyDate & aMyDate)
{
	SetDate(this->GetDateSerial()+aMyDate.GetDateSerial());
	return *this;
}
 
// >, <, >=, <=, ==, != (boolean relational test operators)
bool MyDate::operator> (const MyDate & aMyDate)  const
{
	if (Compare(aMyDate) == 1)
		return true;
	return false;
}
bool MyDate::operator< (const MyDate & aMyDate)  const
{
	if (Compare(aMyDate) == -1)
		return true;
	return false;
}
bool MyDate::operator>= (const MyDate & aMyDate)  const
{
	if (Compare(aMyDate) == -1)
		return false;
	return true;
}
bool MyDate::operator<= (const MyDate & aMyDate)  const
{
	if (Compare(aMyDate) == 1)
		return false;
	return true;
}
bool MyDate::operator== (const MyDate & aMyDate)  const
{
	if (Compare(aMyDate) == 0)
		return true;
	return false;
}
bool MyDate::operator!= (const MyDate & aMyDate)  const
{
	if (Compare(aMyDate) != 0)
		return true;
	return false;
}
 
//// <<, >> stream insertion and extraction
ostream & operator<< (ostream & os, MyDate & aMyDate)
{
	os << aMyDate.GetDateSerial(); //aMyDate.GetMonth() + '/' + aMyDate.GetDay() + '/' + aMyDate.GetYear();
	return os;
}
 
//// date must be one of these formats
////    ???
istream & operator>> (istream & is, MyDate & aMyDate)
{
	const int BUFFER_SIZE = 15;
	char bucket[BUFFER_SIZE];

	do
	{
		is.get(bucket, BUFFER_SIZE);
	}while(strlen(bucket) == (BUFFER_SIZE - 1));

	int i = 0;
	int Years = 0;
	int Months = 0;
	int Days = 0;
	char *userYears = new char [8];
	char *userMonths = new char [2];
	char *userDays = new char [2];

	for (int mth = 0; bucket[i] != '/' && bucket[i] != '\0'; mth++)
	{
		userMonths[mth] = bucket[i];
		i++;
	}
	Months = atoi(userMonths);
	i++;

	for (int dy = 0; bucket[i] != '/' && bucket[i] != '\0'; dy++)
	{
		userDays[dy] = bucket[i];
		i++;
	}
	Days = atoi(userDays);
	i++;

	for (int yr = 0; bucket[i] != '\0'; yr++)
	{
		userYears[yr] = bucket[i];
		i++;
	}
	Years = atoi(userYears);

	aMyDate.SetDate(Days, Months, Years);

	return is;
}

std::string MyDate::displayDate()
{
	char *dayOfWeek = new char[9];
	std::string monthOfYear;
	std::string dayOfMonth;
	std::string year;
	std::string date;
	std::string temp;

	GetDayName(dayOfWeek);
	monthOfYear = std::to_string(GetMonth());
	dayOfMonth = std::to_string(GetDay());
	year = std::to_string(GetYear());

	date.append(dayOfWeek);
	temp = ' ' + monthOfYear + '/' + dayOfMonth + '/' + year;
	date.append(temp);
	return date;
}