#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

template<typename T>
class Array {
	/*
	*Function declarations for the Array class
	*
	*/
private:
	int m_size; //size of Array
	T *m_piArray; //pointer to integer arrays

public:
	Array(); //default constructor
	~Array();
	Array(int length, T value); //constructor 1
	Array(int length, T* values); //constructor 2

	Array(const Array &arr); //copy constructor

	//overloaded operators for [] and =
	T& operator[](int);

	Array& operator=(const Array &);
	//Array& operator+(const Array &);
	Array operator+(const Array&) const;

	int size(); //returns current size of the Array
	void append(T x); //appends the element x to the end of the array
	void append(Array y); //appends all of the contents of y to the end of the array
	
	template<class Y>
	friend std::ostream& operator<<(std::ostream& os, const Array<Y> &arr);
};


//default constructor
template <typename T>
Array<T>::Array()
{
	//default constructor initializes class variables
	m_size = 0;
	m_piArray = NULL;
}

template <typename T>
Array<T>::~Array()
{
	//destructor helps free memory when it goes out of scope
	delete[] m_piArray;
}

// Initialize an array with an array of values
template <typename T>
Array<T>::Array(int length, T* values) : m_size(length)
{
	if (values == NULL)
	{
		printf("Pointer to a null array\n");
		exit(0);
	}

	else
	{
		m_piArray = new T[length]; //allocate memory to hold values

		if (m_piArray == NULL)
			printf("No memory was allocated\n");

		for (int i = 0; i < length; i++)
		{
			m_piArray[i] = values[i]; //copy values in *values to default array
		}

	}
}


//copy constructor creates a deep copy of the Array
template <typename T>
Array<T>::Array(const Array &arr) : m_size(arr.m_size)
{
	m_piArray = new T[m_size]; //allocate memory for array

	for (int i = 0; i < m_size; i++)
	{
		m_piArray[i] = arr.m_piArray[i]; //perform a deep copy of Array arr
	}

}

/*this creates an array with length length and initialized by value*/
template <typename T>
Array<T>::Array(int length, T value) : m_size(length)
{

	//check if length is valid
	if (length < 0)
	{
		printf("Invalid initialization for size of array");
	}
	else
	{
		if (m_size > 0)
		{
			m_piArray = new T[length]; //added 1 to include the terminating character

			if (m_piArray == NULL) //check if memory was allocated
			{
				printf("No memory was allocated\n");
			}
			else
			{
				for (int i = 0; i < length; i++)
				{
					m_piArray[i] = value; //initialize array
				}
			}
		}

	}
}

/*Operator[] returns elements corresponding to given index in an array*/
template <typename T>
T& Array<T>::operator[](int index)
{
	if (index >= m_size || index < 0)
	{
		printf("Error: invalid index");
		exit(0);
	}
	return m_piArray[index];
}

/*equal operator assigns one array to another array using deep copy*/
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arr)
{
	if (&arr != this) //check if it is not altering same array
	{
		m_size = arr.m_size;
		m_piArray = (T *)malloc(m_size * sizeof(T));//allocate memory for new array

		for (int i = 0; i < m_size; i++)
		{
			m_piArray[i] = arr.m_piArray[i]; //perform a deep copy of arr but doesn't alter arr
		}
	}

	return *this; //reference to current array
}


/*concatenate two arrays*/
template <typename T>
Array<T> Array<T>::operator+(const Array<T>& arr) const
{
	Array temparray; //create temporary array

	int new_sz = m_size + arr.m_size;//find size of new array which is the sum of the sizes of both array
	T *new_ptr = new T[new_sz]; //allocate memory of size equal to new array
	T *ptr = NULL; //initialize a NULL pointer to create new array

	if (new_ptr == NULL)
	{
		printf("no memory was allocated\n");
		exit(0);
	}
	else
	{
		ptr = new_ptr;

		for (int i = 0; i < m_size; i++, ptr++)
		{
			*ptr = m_piArray[i]; //make a deep copy of first array
		}

		for (int i = 0; i < arr.m_size; i++, ptr++)
		{
			*ptr = arr.m_piArray[i]; //make a deep copy of second array
		}

		temparray.m_size = new_sz; //assign size of new array to size of temparray
		temparray.m_piArray = new_ptr;//assign elements of new_ptr to temporary array

		return temparray;
	}

}


/*this returns size of current array*/
template <typename T>
int Array<T>::size()
{
	return m_size;
}

//Append just one integer number
template <typename T>
void Array<T>::append(T x)
{
	int new_size = m_size + 1; //new array size is equal to current size + 1 for the int value appended
	T *new_ptr = new T[new_size]; //allocate memory for new array
	//T *new_ptr = (T *)malloc(new_size * sizeof(int)); //allocate memory for new array
	
	if (new_ptr == NULL)
	{
		printf("no memory was allocated\n");
	}
	else
	{
		for (int i = 0; i < m_size; i++)
		{
			new_ptr[i] = m_piArray[i]; //append original array
		}

		new_ptr[m_size] = x; //append x

		m_size = new_size; //update m_size
		m_piArray = new_ptr; //update m_piArray
	}

}

/*Append entire array to existing array*/
template <typename T>
void Array<T>::append(Array<T> y)
{
	int new_sz = m_size + y.size();//new array size is equal to current size of array + size of array to be appended
	T *new_ptr = new T[new_sz]; //allocate memory for new array
	T *ptr = NULL;

	if (new_ptr == NULL)
	{
		printf("no memory was allocated\n");
	}
	else
	{
		ptr = new_ptr;

		for (int i = 0; i < m_size; i++, ptr++)
		{
			*ptr = m_piArray[i]; //copy contents of old array to array ptr
		}

		for (int i = 0; i < y.size(); i++, ptr++)
		{
			*ptr = y[i]; //copy contents of new array to ptr beginning from the end
		}


		m_size = new_sz;
		m_piArray = new_ptr;

	}
}

//this prints contents of an array
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	os << "[";
	for (int i = 0; i < arr.m_size; i++)
	{
		os << arr.m_piArray[i];
		if (i != arr.m_size - 1)
			os << ",";
	}

	os << "]\n";

	return os;

}



#endif

