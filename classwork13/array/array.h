#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <exception>

//OutOfBoundsException handling
class OutOfBoundsException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Index out of bounds";
		}
};

template<typename T>
class Array: public std::exception 
{
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
	void append(const Array& ); //appends all of the contents of y to the end of the array
	
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
Array<T>::Array(int length, T* values)
{
	
	if (values == NULL)
	{
		printf("Pointer to a null array\n");
		return;
	}
	
	try
	{
		m_piArray = new T[length]; //allocate memory to hold values	
		for (int i = 0; i < length; i++)
		{
			m_piArray[i] = values[i]; //copy values in *values to default array
		}
		m_size = length;
	}

	catch(std::bad_alloc& e)
	{
		std::cerr << "bad_alloc caught: " << e.what() << std::endl;
		m_size = 0;
	}
	
}


//copy constructor creates a deep copy of the Array
template <typename T>
Array<T>::Array(const Array &arr)
{
	try
	{
		m_piArray = new T[arr.m_size]; //allocate memory for array
		for (int i = 0; i < arr.m_size; i++)
		{
			m_piArray[i] = arr.m_piArray[i]; //perform a deep copy of Array arr
		}
		m_size = arr.m_size;
	}
	catch(std::bad_alloc& e)
	{
		std::cerr << "bad_alloc caught: " << e.what() << std::endl;
		m_size = 0;
	}

}

/*this creates an array with length length and initialized by value*/
template <typename T>
Array<T>::Array(int length, T value)
{

	//check if length is valid
	if (length < 0)
	{
		printf("Invalid initialization for size of array");
	}
	else
	{
			try
			{
				m_piArray = new T[length]; //added 1 to include the terminating character
				for (int i = 0; i < length; i++)
				{
					m_piArray[i] = value; //initialize array
				}

				m_size = length;

			}
			catch(std::bad_alloc& e)
			{
				std::cerr << "bad_alloc caught: " << e.what() << std::endl;
				m_size = 0;
			}			
	}
}

/*Operator[] returns elements corresponding to given index in an array*/
template <typename T>
T& Array<T>::operator[](int index)
{
	if (index >= m_size || index < 0)
	{
		throw OutOfBoundsException();
	}
	return m_piArray[index];
}

/*equal operator assigns one array to another array using deep copy*/
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arr)
{
	if (&arr != this) //check if it is not altering same array
	{
		printf("Got here\n");
		try
		{
			T *temp = new T[arr.m_size];
			//m_piArray = new T[arr.m_size];
			for (int i = 0; i < arr.m_size; i++)
			{
				temp[i] = arr.m_piArray[i]; //perform a deep copy of arr but doesn't alter arr
			}
			m_size = arr.m_size;
			m_piArray = temp;
			return *this; //return pointer to current array
		}
		
		catch(std::bad_alloc& e)
		{
			std::cerr << "bad_alloc caught: " << e.what() << std::endl;
		}
	}
	
}


/*concatenate two arrays*/
template <typename T>
Array<T> Array<T>::operator+(const Array<T>& arr) const
{
	Array temparray; //create temporary array

	int new_sz = m_size + arr.m_size;//find size of new array which is the sum of the sizes of both array
	T *new_ptr = NULL; 
	try
	{
		new_ptr = new T[new_sz]; //allocate memory of size equal to new array
		T *ptr = NULL; //initialize a NULL pointer to create new array

	
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

	catch(std::bad_alloc& e)
	{
		std::cerr << "bad_alloc caught: " << e.what() << std::endl;
		exit(0);
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
	T *new_ptr = NULL; 

	try
	{
		new_ptr = new T[new_size]; //allocate memory for new array
	
		for (int i = 0; i < m_size; i++)
		{
			new_ptr[i] = m_piArray[i]; //append original array
		}

		new_ptr[m_size] = x; //append x

		m_size = new_size; //update m_size
		m_piArray = new_ptr; //update m_piArray}

	}
	catch(std::bad_alloc& e)
	{
		std::cerr << "bad_alloc caught: " << e.what() << std::endl;		
	}
	
}

/*Append entire array to existing array*/
template <typename T>
void Array<T>::append(const Array<T>& y)
{
	int new_sz = m_size + y.m_size;//new array size is equal to current size of array + size of array to be appended
	T *new_ptr = NULL; 
	
	try
	{
		new_ptr = new T[new_sz]; //allocate memory for new array
		
		for(int i=0; i < m_size; i++)
		{
			new_ptr[i] = m_piArray[i]; //append original array
		}
		for(int i = m_size; i < new_sz; i++)
		{
			new_ptr[i] = y.m_piArray[i-m_size];
		}

		m_size = new_sz;
		m_piArray = new_ptr; 
	}

	catch(std::bad_alloc& e)
	{
		std::cerr << "bad_alloc caught: " << e.what() << std::endl;
		return;
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
