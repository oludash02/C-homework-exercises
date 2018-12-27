#include "array.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <memory>

// Global flag that sets whether or not `new` will fail
bool memoryAllocFail = false; // Succeed by default

// Custom implementation of new
void* operator new(std::size_t size)
{
    std::cout << "New allocation of size " << size << std::endl;
    if (memoryAllocFail)
    {
       throw std::bad_alloc();
    }

    return ::malloc(size);
}

void operator delete(void* block)
{
    std::cout << "Freed allocation" << std::endl;
    ::free(block);
}

int main(int argc, char* argv[])
{
	
	/*
	* Test cases: Bad Malloc for all functions
	*/
	 
	/*Test default constuctor to ensure it doesn't generate an error, also try appending*/
	memoryAllocFail = false;
	Array<int> arr1;
	arr1.append(7);
	std::cout<<arr1;

	/*Test initialization with an integer value, constructor 1*/
	memoryAllocFail = false;
	Array<int> arr2(10,5);
	std::cout<<arr2;

	/*Test intialization with an array of elements, constructor 2*/
	memoryAllocFail = false;
	int values1[] ={1,2,3,4,5,6,7,8,9,20,15};
  	Array<int> arr3(9,values1);
	std::cout << arr3;
	
	try
	{
		std::cout << arr3[18];
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	/*Test copy constructor for single values*/
	memoryAllocFail = false;
	Array<int> arr4(10,values1);
	for(int i=0; i<arr4.size(); i++){
		try
		{
			arr4[i] = i*2;
		}
		catch(std::exception& e)
		{
			std::cout<<e.what() <<std::endl;
		}
		
	}
	std::cout<<arr4;

	/*Test copy constructor for array*/
	memoryAllocFail = false;
	Array<int> arr5 = arr4;
	std::cout<<arr5;
	
	/*Test to append arrays*/
	memoryAllocFail = true;
	Array<int> arr6;
	arr6.append(arr5);
	std::cout << arr6;

	/*Test overload + operator with different arrays*/
	memoryAllocFail = true;
	Array<int> arr7 = arr1 + arr3 + arr2 + arr4;
	std::cout<<arr7;
	
	/*Test overload + operator with repeated array*/
	memoryAllocFail = true;
	Array<int> arr8 = arr1 + arr2 + arr1 + arr2;
	//std::cout << arr8;
	
	//Final test is with valgrind to ensure there are no memory leaks
  	return(0);
}



