// MyArray.h
 
// insure that this header file is not included more than once
#pragma once
#ifndef MYARRAY_H_
#define MYARRAY_H_
 
template <class elemType>
class MyArray
{
private:
      int _size; // number of elements the current instance is holding
      int _capacity; // number of elements the current instance can hold
      elemType * list; // ptr to the first element in the array
 
// UTILITY FUNCTION(S)
// MakeRoom
      // doubles _capacity and builds a new list
      //   maintains current data
      void MakeRoom();
public:
 
// Ctors
      MyArray(); // default
      MyArray(int capacity); // initialize to capacity
      MyArray( MyArray & original); // copy constructor
// Dtor
      ~MyArray();
 
// METHODS
// Add
      // Takes an argument of the templated type and
      // adds it to the end of the list/array
      void Add(const elemType & elem);
// At
      // Takes an int argument
      // Returns a reference to the element at a specified location in this MyArray
      elemType & At(int index);
// Find
      // Takes an argument of the templated type
      // Returns the int index were this element is found
      // Returns -1 if element is not found
      int Find(const elemType & elem);
// Insert
      // Takes an argument of the templated type and
      // An integer index argument
      // Inserts the element at that index in the list/array
      // moving the element currently at that index and all subsequent
      // elements up one index
      void Insert(const elemType & elem, int index);
// RemoveAt
      // Takes an int argument
      // Removes the element at that index in the list/array
      void RemoveAt(int index);
// SetValue
      // Takes an item to assign and an int index to assign it at
      // Assigns the item to the specified index of this MyArray
      void SetValue(const elemType & elem, int index);
// Size
      // Returns the number of elements in this MyArray
      int Size();

// Capacity
	  // Returns the number of elements this MyArray can hold
	  int Capacity();
 
// OPERATORS
      // = (assignment - takes a MyArray and makes a deep copy)
      MyArray & operator= (const MyArray & aMyArray);
 
      // [] (read/write char access by index)
            // Returns a reference to the element at that index
            // throws an exception if index is < 0 or >= _length
      elemType & operator[] (int index) const;
 
      // ==, != (boolean relational test operators)
      //  compares arrays for element by element equality
      bool operator== (const MyArray & aMyArray) ;
      bool operator!= (const MyArray & aMyArray) ;
};






template <class elemType>
void MyArray<elemType>::MakeRoom()
{
	this->_capacity *= 2;
	this->list = new elemType[this->_capacity];
}

template <class elemType>
MyArray<elemType>::MyArray()
{
	this->_capacity = 16;
	this->_size = 0;
	this->list = new elemType[this->_capacity];
}

template <class elemType>
MyArray<elemType>::MyArray(int capacity)
{
	this->_capacity = capacity;
	this->_size = 0;
	this->list = new elemType[this->_capacity];
}

template <class elemType>
MyArray<elemType>::MyArray(MyArray<elemType> & original)
{
	int sizeOfOriginal = original.Size();

	if (sizeOfOriginal < 16)
	{
		this->_capacity = 16;
	}
	else
	{
		this->_capacity = sizeOfOriginal;
	}

	this->_size = sizeOfOriginal;
	
	if (original.Size() != 0)
	{
		this->list = new elemType[this->_capacity];

		for (int i = 1; i < original.Size(); i++)
		{
			*(list + i) = original[i];
		}
	}
	else
	{
		this->list = new elemType[NULL];
	}
}

template <class elemType>
MyArray<elemType>::~MyArray()
{
	delete [] this->list;
}

template <class elemType>
int MyArray<elemType>::Size()
{
	return this->_size;
}

template <class elemType>
int MyArray<elemType>::Capacity()
{
	return this->_capacity;
}

template <class elemType>
elemType & MyArray<elemType>::operator[](int index) const
{
	if (index < 0 || index >= _capacity)
	{
		throw "Error: Index is out of range.";
	}
	// return *(list + index);
	return list[index];
}

template <class elemType>
void MyArray<elemType>::Add(const elemType & elem)
{
	int newSize = this->_size + 1;
	this->_capacity = newSize;
	this->_size = newSize;

	MyArray<elemType> tempArray(newSize);

	for (int i = 0; i < newSize - 1; i++)
	{
		elemType debug = list[i];
		tempArray[i] = this->list[i];
		elemType debug2 = tempArray[i];
	}

	this->list = new elemType[this->_capacity];

	for (int i = 0; i < newSize - 1; i++)
	{
		this->list[i] = tempArray[i];
	}

	list[newSize - 1] = elem;
}

template <class elemType>
elemType & MyArray<elemType>::At(int index)
{
	if (index >= this->_size || index < 0)
	{
		throw "Error: Index out of range.";
	}
	return this->list[index];
}

template <class elemType>
int MyArray<elemType>::Find(const elemType & elem)
{
	for (int i = 0; i < Size() - 1; i++)
	{
		if (list[i] == elem)
		{
			return i;
		}
	}
	return -1;
}


template <class elemType>
void MyArray<elemType>::SetValue(const elemType & elem, int index)
{
	if (index >= this->_capacity || index < 0)
	{
		throw "Error: Index out of range.";
	}
	this->list[index] = elem;
}

template <class elemType>
void MyArray<elemType>::RemoveAt(int index)
{
	if (index >= this->_capacity || index < 0)
	{
		throw "Error: Index out of range.";
	}

	int newSize = this->_size - 1;
	this->_capacity = newSize;
	this->_size = newSize;
	MyArray<elemType> tempArray(newSize);

	for (int i = 0; i < index; i++)
	{
		tempArray[i] = this->list[i];
	}
	for (int i = index; i < newSize; i++)
	{
		tempArray[i] = this->list[i + 1];
	}

	this->list = new elemType[this->_capacity];

	for (int i = 0; i < newSize; i++)
	{
		this->list[i] = tempArray[i];
	}
}

template <class elemType>
void MyArray<elemType>::Insert(const elemType & elem, int index)
{
	if (index >= this->_capacity || index < 0)
	{
		throw "Error: Index out of range.";
	}

	int newSize = this->_size + 1;
	this->_capacity = newSize;
	this->_size = newSize;
	MyArray<elemType> tempArray(newSize);

	for (int i = 0; i < index; i++)
	{
		tempArray[i] = this->list[i];
	}

	tempArray[index] = elem;

	for (int i = index + 1; i < newSize; i++)
	{
		tempArray[i] = this->list[i - 1];
	}

	this->list = new elemType[this->_capacity];

	for (int i = 0; i < newSize; i++)
	{
		this->list[i] = tempArray[i];
	}

}
template <class elemType>
bool MyArray<elemType>::operator== (const MyArray & aMyArray)
{
	if (Size() == aMyArray._size)
	{
		for (int i = 0; i < Size(); i++)
		{
			if (list[i] != aMyArray[i])
			{
				return false;
			}
		}
		return true;

		/*int i = 0;
		while (this->list[i] == aMyArray[i])
		{
			i++;
			if (i == Size() - 1 && this->list[i] == aMyArray[i])
			{
				return true;
			}
		}*/
	}
	return false;
}

template <class elemType>
bool MyArray<elemType>::operator!= (const MyArray & aMyArray)
{
	if (Size() == aMyArray._size)
	{
		for (int i = 0; i < Size(); i++)
		{
			if (list[i] != aMyArray[i])
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

template <class elemType>
MyArray<elemType> & MyArray<elemType>::operator= (const MyArray<elemType> & aMyArray)
{
	if (aMyArray._size != 0)
	{
		this->list = new elemType[this->_capacity];

		for (int i = 0; i < aMyArray._size; i++)
		{
			*(list + i) = aMyArray[i];
		}
	}
	else
	{
		this->list = new elemType[NULL];
	}
	this->_size = aMyArray._size;
	this->_capacity = aMyArray._capacity;

	return *this;
}

#endif