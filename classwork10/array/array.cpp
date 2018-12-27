#include "array.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdio.h>

//set values for the default constructor
Array::Array()
{
	m_size = 0;
	m_piArray = NULL;
}

void Array::initialize(int size, int val)
{
	if(size < 0)
	{
		printf("Invalid initialization for size of array\n");
	}
	else
	{
		if(m_piArray != NULL) //clean up array if not NULL to initialize it
		{
			cleanup();
		}
		
		if(size > 0)
		{
			m_size = size;

			m_piArray = (int *)malloc(size * sizeof(int)); //allocates memory for array

			if(m_piArray == NULL)
			{
				printf("No memory was allocated\n");
			}
			else
			{
				for (int i=0; i<size; i++)
				{
					m_piArray[i] = val; //initialize array with val
				}
			}
		}		
	}
}

//Operator returns elements corresponding to given index in an array
int &Array::operator[](int index)
{
	if(index>= m_size || index < 0)
	{
		printf("Error: invalid index");
		exit(0);
	}
	return m_piArray[index];
}

Array& Array::operator=(const Array& arr)
{
	if(&arr != this) //check if it is not altering same array
	{
		cleanup();
		m_size = arr.m_size;
		m_piArray = (int *)malloc(m_size * sizeof(int));//allocate memory for new array

		for(int i=0; i<m_size; i++)
		{
			m_piArray[i] = arr.m_piArray[i];
		}
	}

	return *this; //reference to current array
}

//cleanup memory allocated using malloc
void Array::cleanup()
{
	if(m_piArray != NULL)
	{
		free(m_piArray);
		m_piArray = NULL;
		m_size = 0;
	}
}

//return size of current array
int Array::size()
{
	return m_size;
}

//Append just one integer number
void Array::append(int x)
{
	int new_size = m_size+1;
	int *new_ptr = (int *)malloc(new_size * sizeof(int));
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
		cleanup();
		m_size = new_size; //update m_size
		m_piArray = new_ptr; //update m_piArray
		//free(new_ptr);
	}
}

//Append entire array to existing array
void Array::append(Array y)
{
	int new_sz = m_size + y.size();
	int *new_ptr = (int *)malloc(new_sz * sizeof(int));
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

		cleanup(); //free memory
		m_size = new_sz;
		m_piArray = new_ptr;
		//free(new_ptr);
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
