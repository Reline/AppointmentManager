// MyString.h
 
// MyString is a custom string class implementation.
 
// insure that this header file is not included more than once
#pragma once
#ifndef MYSTRING_H_
#define MYSTRING_H_
 
#include <iostream>
using std::ostream;
using std::istream;
 
class MyString
{
private:
      int _capacity; // current number of chars allocated
      int _length; // current length of string
      char * _string; // ptr to allocated chars
 
public:
// CONSTRUCTORS
      // default constructor
            // initializes _capacity to 16 chars
            // initializes this MyString to an empty MyString
      MyString();
 
      // parameterized constructors
            // takes a c style string argument
            // initializes capacity to greater of strlen(cString) or 16 chars
            // initializes this MyString to cString
      MyString(const char * aCString);
 
            // takes an int argument
            // initializes capacity to numChars chars
            // initializes this MyString to an empty MyString
      MyString(int numChars);
 
      // copy constructor
            // initializes this MyString to a deep copy of the original
      MyString(const MyString & original);
 
// DESTRUCTOR
            // dealocate dynamic storage
      ~MyString();
 
// METHODS
      // Append
            // Takes a MyString argument
            // Appends chars to the end of this MyString
      void Append(const MyString & aMyString);
            // Takes  a c style string argument
            // Appends chars to the end of this MyString
      void Append(const char * aCString);
 

      // Assign
            // Takes a MyString argument
            // makes this MyString a copy of aMyString
      void Assign(const MyString & aMyString);
            // Takes  a c style string argument
            // makes this MyString contain the chars of aCString
      void Assign(const char * const aCString);
 

      // At
            // Takes an int argument
            // Returns a copy of the char at that index
            // throws an exception if index is < 0 or >= _length
      char At(int index) const;
 

      // Clear
            // Makes this MyString empty
            // does not change capacity;
      void Clear();
            // Makes this MyString empty
            // changes capacity to newCapacity
            // throws an exception if newCapacity < 0
      void Clear(int newCapacity);
 

      // Compare
            // Takes a MyString argument
            // Returns (zero) if the argument contains
//   the same string of chars as this MyString
            // Returns (a positive int) if the argument is
//   alphabetically less than this MyString
            // Returns (a negative int) if the argument is
//   alphabetically greater than this MyString
      int Compare(const MyString & aMyString);
 

      // CurrentCapacity
            // Returns number of characters that this instance can hold
            // without reallocating
      int CurrentCapacity() const;
 

      // Equals
            // Takes a MyString argument
            // Returns (true) if the argument contains
//   the same string of chars as this MyString,
//   otherwise it returns (false).
      bool Equals(const MyString & aMyString) const;
            // Takes a c style string argument
            // Returns (true) if the argument contains
//   the same string of chars as this MyString,
//   otherwise it returns (false).
      bool Equals(const char * const aCString) const;
 

      // Find
            // Takes a myString argument
            // Returns the index (int)
//   where the argument MyString was found
//   in this MyString. If it is not found, then returns -1.
      int Find(const MyString & aMyString) const;
 

      // Insert
            // Takes two arguments
            // An int – the index in this MyString
//   at which to insert the new chars
            // A MyString containing the chars to be inserted
      void Insert(const MyString & aMyString, int index);
 

      // Length
            // Returns the number (int) of chars in this MyString
      int Length(void) const;
 

      // Replace
            // Takes three arguments
            // An int – the index of the char in thisMyString
//   to begin replacing at.
            // An int – the number of chars to replace
            // And a MyString containg the replacement string
            // throws an exception if startIndex >= Length
            // throws an exception if startIndex + numChars > Length()
            // throws an exception if aMyString.Length() < numChars
      void Replace(int startIndex, int numChars, const MyString & aMyString);
 

      // Substr
            // Takes two int arguments,
            // An int for the starting index,
            // An int for the number of chars to return.
            // Returns a MyString with the requested sub-string
//   from the original MyString
            // throws an exception if startIndex + numChars > Length()
      MyString SubStr(int startIndex, int numChars) const;
 

// OPERATORS
 
      // = (assignment - takes a MyString or a c style string)
      MyString operator= (const MyString & aMyString);
      MyString operator= (const char *  const aCString);
 
      // +, += (concatenation - takes a MyString or a c style string)
      MyString operator+ (const MyString & aMyString);
      MyString operator+= (const MyString & aMyString);
 
      // [] (read/write char access by index)
            // Returns a reference to the char at that index
            // throws an exception if index is < 0 or >= _length
      char & operator[] (int index) const;
 
      // >, <, >=, <=, ==, != (boolean relational test operators)
      bool operator> (const MyString & aMyString) ;
      bool operator< (const MyString & aMyString) ;
      bool operator>= (const MyString & aMyString) ;
      bool operator<= (const MyString & aMyString) ;
      bool operator== (const MyString & aMyString) ;
      bool operator!= (const MyString & aMyString) ;
 
      // returns a pointer to the underlying c-style string
      const char* _cstr() const;
 
      // <<, >> stream insertion and extraction
      friend ostream & operator<< (ostream & os, const MyString & aMyString);
 
      friend istream & operator>> (istream & is, MyString & aMyString);

	  int atoi (MyString & aMyString);
	  int atoi (const char * const aCString);
};
#endif