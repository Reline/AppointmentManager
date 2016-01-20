#include <iostream>
using namespace std;
#include "MyString.h"
#include <cstring>

//Constructor
//
MyString::MyString()
{
	this->_capacity = 16;
	this->_length = 0;

	this->_string = new char[this->_capacity + 1];
	_string[0] = '\0';
}

// parameterized constructors
            // takes a c style string argument
            // initializes capacity to greater of strlen(cString) or 16 chars
            // initializes this MyString to cString
MyString::MyString(const char * aCString)
{
	_length = strlen(aCString);
	_capacity = _length;

	_string = new char[_capacity + 1];
	strcpy(_string, aCString);
}
 
// takes an int argument
// initializes capacity to numChars chars
// initializes this MyString to an empty MyString
MyString::MyString(int numChars)
{
	this->_capacity = numChars;
	this->_length = 0;

	this->_string = new char[this->_capacity + 1];
	_string[0] = '\0';
}
 
// copy constructor
    // initializes this MyString to a deep copy of the original
MyString::MyString(const MyString & original)
{
	this->_capacity = original.CurrentCapacity();
	this->_length = original.Length();

	this->_string = new char[this->_capacity + 1];
	strcpy(_string, original._cstr());
	//strcpy_s(_string, _capacity + 1, original._cstr());
	//_string[_length + 1] = '\0';
}

//Destructor
//deallocate dynamic storage
MyString::~MyString()
{
	delete [] this->_string;
}

//returns a pointer to the underlying c-style string
const char* MyString::_cstr() const
{
	return this->_string;
}

//current capacity
//returns number of characters that this instance can hold
int MyString::CurrentCapacity() const
{
	return this->_capacity;
}

int MyString::Length(void) const
{
	return this->_length;
}

//Takes a c style string argument
// makes this MyString contain the chars of aCString
void MyString::Assign (const char * const aCString)
{
	_length = strlen(aCString);
	_capacity = _length;

	delete [] _string;
	_string = new char[_capacity + 1];
	strcpy(_string, aCString);
	/*int lengthOfACString = strlen(aCString);
	if (_string == aCString)
	{
		return;
	}
	if (lengthOfACString > _capacity)
	{
		_capacity = lengthOfACString;
	}
	_length = lengthOfACString;
	delete [] _string;
	_string = new char[_capacity + 1];
	strcpy(_string, aCString);*/

}

//Assign
//takes a MyString argument
// makes this MyString a copy of a MyString
void MyString::Assign(const MyString & aMyString)
{
	Assign(aMyString._cstr());
	/*int lengthOfMyString = aMyString.Length();

	if (lengthOfMyString > _capacity)
	{
		_capacity = lengthOfMyString + 1;
		delete [] _string;
		_string = new char[_capacity + 1];
	}

	_length = lengthOfMyString;

	strcpy_s(_string, _length, aMyString._cstr());
	_string[_length + 1] = '\0';*/
}

void MyString::Append(const char * aCString)
{
	int requiredCapacity = (_length + strlen(aCString));
	_capacity = requiredCapacity;
	char *tempStr = new char[_length + 1];

	for(int j = 0; j <= _length; j++)
	{
		tempStr[j] = _string[j];
	}

	delete [] _string;
	_string = new char[requiredCapacity + 1];

	int index = 0;
	for(int i=0; i < _length; i++)
	{
		_string[i] = tempStr[i];
		index++;
	}

	delete [] tempStr;

	int k = 0;
	for(index; index <= requiredCapacity; index++)
	{
		_string[index] = aCString[k];
		k++;
	}

	_length = requiredCapacity;
} 

void MyString::Append(const MyString & aMyString)
{
	Append(aMyString._string);
}

// At
            // Takes an int argument
            // Returns a copy of the char at that index
            // throws an exception if index is < 0 or >= _length

char MyString::At(int index) const
{
	if (index < 0 || index >= _length)
	{
		throw "Error: Index out of range.";
	}
	return _string[index];
}

 
      // Clear
            // Makes this MyString empty
            // does not change capacity;
void MyString::Clear()
{
	int tempCapacity = _capacity;
	delete [] _string;
	_string = new char[tempCapacity + 1];
	_capacity = tempCapacity;
	_length = 0;
	_string[0] = '\0';
}

            // Makes this MyString empty
            // changes capacity to newCapacity
            // throws an exception if newCapacity < 0

void MyString::Clear(int newCapacity)
{
	if (newCapacity < 0)
	{
		throw "Error: Index out of range.";
	}

	delete [] _string;
	_capacity = newCapacity;
	_string = new char[_capacity + 1];
	_length = _capacity + 1;
	_string[0] = '\0';
}
 
      // Compare
            // Takes a MyString argument
            // Returns (zero) if the argument contains
//   the same string of chars as this MyString
            // Returns (a positive int) if the argument is
//   alphabetically less than this MyString
            // Returns (a negative int) if the argument is
//   alphabetically greater than this MyString
int MyString::Compare(const MyString & aMyString)
{
	return strcmp(_string, aMyString._string);

	//int argLength = aMyString._length;

	//int comparison;

	//if (_length == argLength)
	//{
	//	for(int i=0; i <= _length; i=i)
	//	{
	//		if (_string[i] == aMyString._string[i]) //the ascii value of the index of _string is equivalent to the ascii value of the index of aMyString...
	//		{
	//			i++;

	//			if (i == _length)
	//			{
	//				comparison = 0;
	//				return comparison;
	//			}
	//		}
	//		else
	//		{
	//			if (_string[i] > aMyString._string[i]) //the index of the first is greater than the second
	//			{
	//				comparison = 1;
	//				return comparison;
	//				//return positive int
	//			}
	//			else if (_string[i] < aMyString._string[i]) //if the index of the first is less than the second
	//			{
	//				comparison = -1;
	//				return comparison;
	//				//return negative int
	//			}
	//		}
	//	}
	//}
	//else
	//{
	//	comparison = 9; // just a throwaway number for debugging
	//	return comparison;
	//	//the length of these two strings is not equivalent
	//}

	//return comparison;
}
 
 
      // Equals
            // Takes a MyString argument
            // Returns (true) if the argument contains
//   the same STRING of chars as this MyString,
//   otherwise it returns (false).
bool MyString::Equals(const MyString & aMyString) const
{
	int lengthOfAMyString = aMyString.Length();

	if (_length == lengthOfAMyString)
	{
		for(int i=0; i <= _length; i++)
		{
			if (_string[i] != aMyString._string[i]) //the ascii value of the index of _string is equivalent to the ascii value of the index of aMyString...
			{
					return false;
			}
		}
	}
	else if(_length > lengthOfAMyString || _length < lengthOfAMyString)
	{
		return false;
	}
	return true;
}



            // Takes a c style string argument
            // Returns (true) if the argument contains
//   the same string of chars as this MyString,
//   otherwise it returns (false).
bool MyString::Equals(const char * const aCString) const
{
	int lengthOfACString = strlen(aCString);
	if (_length == lengthOfACString)
	{
		for(int i=0; i <= _length; i++)
		{
			if(_string[i] != aCString[i])
			{
				return false;
			}
		}
	}
	else if(_length > lengthOfACString || _length < lengthOfACString)
	{
		return false;
	}
	return true;
}



      // Find
            // Takes a myString argument
            // Returns the index (int)
//   where the argument MyString was found
//   in this MyString. If it is not found, then returns -1.
int MyString::Find(const MyString & aMyString) const
{
	for(int i = 0; i <= _length; i++)
	{
		if(aMyString._string[0] == _string[i])
		{
			int foundIndex = i;
			int tempIndex = i;
			for(int k = 0; k <= aMyString._length; k++)
			{
				if(aMyString._string[k] == _string[tempIndex])
				{
					if(k + 1 == aMyString._length)
					{
						return foundIndex;
					}
					tempIndex++;
				}
			}
		}
	}
	return -1;
}
 
      // Insert
            // Takes two arguments
            // An int – the index in this MyString
//   at which to insert the new chars
            // A MyString containing the chars to be inserted
void MyString::Insert(const MyString & aMyString, int index)
{
	int lengthOfAMyString = aMyString.Length();
	int newCapacity = _length + lengthOfAMyString;
	_capacity = newCapacity;

	char *tempStr = new char[_capacity + 1];

	for(int i = 0; i < index; i++)
	{
		tempStr[i] = _string[i];
	}
	tempStr[index] = '\0';

	strcat(tempStr, aMyString._cstr());

	for(int i = 0; i <= _length - index; i++)
	{
		tempStr[index + lengthOfAMyString + i] = _string[index + i];
	}

	_length = _capacity;
	delete [] _string;
	_string = tempStr;
}

// 
//
//      // Replace
//            // Takes three arguments
//            // An int – the index of the char in thisMyString
////   to begin replacing at.
//            // An int – the number of chars to replace
//            // And a MyString containing the replacement string
//            // throws an exception if startIndex >= Length
//            // throws an exception if startIndex + numChars > Length()
//            // throws an exception if aMyString.Length() < numChars
void MyString::Replace(int startIndex, int numChars, const MyString & aMyString)
{
	if(startIndex >= _length)
	{
		throw "Error: Index out of range.";
	}
	else if(startIndex + numChars > _length)
	{
		throw "Error: Index out of range.";
	}
	else if(aMyString._length < numChars)
	{
		throw "Error: Index out of range.";
	}
	else
	{
		int tempIndex = startIndex;
		for(int i = 0; i < numChars; i++)
		{
			_string[tempIndex] = aMyString._cstr()[i];
			tempIndex++;
		}
	}
}
// 
//
//      // Substr
//            // Takes two int arguments,
//            // An int for the starting index,
//            // An int for the number of chars to return.
//            // Returns a MyString with the requested sub-string
////   from the original MyString
//            // throws an exception if startIndex + numChars > Length()
MyString MyString::SubStr(int startIndex, int numChars) const
{
	if(startIndex + numChars > _length)
	{
		throw "Error: Index out of range.";
	}
	MyString tempStr;
	tempStr.Clear(numChars);
	//char *tempStr = new char [numChars + 1];
	int tempIndex = 0;
	for(int i = startIndex; tempIndex < numChars; i++)
	{
		tempStr._string[tempIndex] = _string[i];
		tempIndex++;
	}
	tempStr._string[numChars] = '\0';
	return tempStr;
}
// 
//
//// OPERATORS
// 
//      // = (assignment - takes a MyString or a c style string)
MyString MyString::operator= (const MyString & aMyString)
{
	Assign(aMyString);
	return *this;
}
//

MyString MyString::operator= (const char *  const aCString)
{
	Assign(aCString);
	return *this;
}

//      // +, += (concatenation - takes a MyString or a c style string)
MyString MyString::operator+ (const MyString & aMyString)
{
	// BROKEN
	Append(aMyString);
	return *this;
}

MyString MyString::operator+= (const MyString & aMyString)
{
	// BROKEN
	Append(aMyString);
	return *this;
}

//      // [] (read/write char access by index)
//            // Returns a reference to the char at that index
//            // throws an exception if index is < 0 or >= _length
char & MyString::operator[] (int index) const
{
	if (index < 0 || index >= _length)
	{
		throw "Error: Index is out of range.";
	}
	return _string[index];
	//return *(_string + index);
}
// 
//      // >, <, >=, <=, ==, != (boolean relational test operators)
bool MyString::operator> (const MyString & aMyString)
{
	return (Compare(aMyString) > 0);
}

bool MyString::operator< (const MyString & aMyString)
{
	return (Compare(aMyString) < 0);
}

bool MyString::operator>= (const MyString & aMyString)
{
	return (Compare(aMyString) >= 0);
}

bool MyString::operator<= (const MyString & aMyString)
{
	return (Compare(aMyString) <= 0);
}

bool MyString::operator== (const MyString & aMyString)
{
	return (Compare(aMyString) == 0);
}

bool MyString::operator!= (const MyString & aMyString)
{
	return (Compare(aMyString) != 0);
}

//
//	   // <<, >> stream insertion and extraction
ostream & operator<< (ostream & os, const MyString & aMyString)
{
	os << aMyString._cstr();
	return os;
}

istream & operator>> (istream & is, MyString & aMyString)
{
	char * aCString = new char[256];
	//is >> aCString;
	is.get(aCString, 255);

	aMyString.Clear();
	aMyString.Assign(aCString);
	delete [] aCString;

	return is;
}