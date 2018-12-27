#include "array.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>

//default constructor
Array::Array()
{
//default constructor initializes class variables
	m_size = 0;
	m_piArray = NULL;
}


Array::~Array()
{
//destructor helps free memory when it goes out of scope
	delete[] m_piArray;
}

// Initialize an array with an array of values
Array::Array(int length, int* values): m_size(length)
{
	if(values == NULL)
	{
		printf("Pointer to a null array\n");
		exit(0);
	}
	
	else
	{
		m_piArray = new int[length]; //allocate memory to hold values

		if(m_piArray == NULL)
			printf("No memory was allocated\n");
			
		for(int i=0; i<length; i++)
		{
			m_piArray[i] = values[i]; //copy values in *values to default array
		}
		
	}
}


//copy constructor creates a deep copy of the Array
Array::Array(const Array &arr): m_size(arr.m_size)
{
	m_piArray = new int[m_size]; //allocate memory for array
	
	for(int i=0; i<m_size; i++)
	{
		m_piArray[i] = arr.m_piArray[i]; //perform a deep copy of Array arr
	}
	
}

/*this creates an array with length length and initialized by value*/
Array::Array(int length, int value): m_size(length)
{

	//check if length is valid
	if(length < 0)
	{
		printf("Invalid initialization for size of array");
	}
	else
	{
		if(m_size > 0)
		{
			m_piArray = new int[length]; //added 1 to include the terminating character

			if(m_piArray == NULL) //check if memory was allocated
			{
				printf("No memory was allocated\n");
			}
			else
			{
				for(int i=0; i<length; i++)
				{
					m_piArray[i] = value; //initialize array
				}
			}	
		}
		
	}
}

/*Operator[] returns elements corresponding to given index in an array*/
int& Array::operator[](int index)
{
	if(index>= m_size || index < 0)
	{
		printf("Error: invalid index");
		exit(0);
	}
	return m_piArray[index];
}

/*equal operator assigns one array to another array using deep copy*/
Array& Array::operator=(const Array& arr)
{
	if(&arr != this) //check if it is not altering same array
	{
		m_size = arr.m_size;
		m_piArray = (int *)malloc(m_size * sizeof(int));//allocate memory for new array

		for(int i=0; i<m_size; i++)
		{
			m_piArray[i] = arr.m_piArray[i]; //perform a deep copy of arr but doesn't alter arr
		}
	}

	return *this; //reference to current array
}


/*concatenate two arrays*/
Array Array::operator+(const Array& arr) const
{
	Array temparray; //create temporary array
	
	int new_sz = m_size + arr.m_size;//find size of new array which is the sum of the sizes of both array
	int *new_ptr = new int[new_sz]; //allocate memory of size equal to new array
	int *ptr = NULL; //initialize a NULL pointer to create new array
	
	if(new_ptr == NULL)
	{
		printf("no memory was allocated\n");
		exit(0);
	}
	else
	{
		ptr = new_ptr;

		for(int i=0; i<m_size; i++, ptr++)	
		{
			*ptr = m_piArray[i]; //make a deep copy of first array
		}
		
		for(int i=0; i<arr.m_size; i++, ptr++)
		{
			*ptr = arr.m_piArray[i]; //make a deep copy of second array
		}

		temparray.m_size = new_sz; //assign size of new array to size of temparray
		temparray.m_piArray = new_ptr;//assign elements of new_ptr to temporary array
		
		return temparray;
	}

}


/*this returns size of current array*/
int Array::size()
{
	return m_size;
}

//Append just one integer number
void Array::append(int x)
{
	int new_size = m_size+1; //new array size is equal to current size + 1 for the int value appended
	int *new_ptr = (int *)malloc(new_size * sizeof(int)); //allocate memory for new array

	if(new_ptr == NULL)
	{
		printf("no memory was allocated\n");
	}
	else
	{
		for(int i=0; i<m_size; i++)
		{
			new_ptr[i] = m_piArray[i]; //append original array
		}

		new_ptr[m_size] = x; //append x
		
		m_size = new_size; //update m_size
		m_piArray = new_ptr; //update m_piArray
	}
	
}

/*Append entire array to existing array*/
void Array::append(Array y)
{
	int new_sz = m_size + y.size();//new array size is equal to current size of array + size of array to be appended
	int *new_ptr = (int *)malloc(new_sz * sizeof(int)); //allocate memory for new array
	int *ptr = NULL;
	
	if(new_ptr == NULL)
	{
		printf("no memory was allocated\n");
	}
	else
	{
		ptr = new_ptr;
		
		for(int i=0; i<m_size; i++, ptr++)
		{
			*ptr = m_piArray[i]; //copy contents of old array to array ptr
		}

		for(int i=0; i<y.size(); i++, ptr++)
		{
			*ptr = y[i]; //copy contents of new array to ptr beginning from the end
		}

	
		m_size = new_sz;
		m_piArray = new_ptr;
		
	}
}

//this prints contents of an array
std::ostream& operator<<(std::ostream& os, const Array& arr)
{
	os << "[";
	for(int i=0; i<arr.m_size; i++)
	{
		os << arr.m_piArray[i];
		if(i != arr.m_size-1)
			os << ",";
	}

	os << "]\n";
	
	return os;

}
