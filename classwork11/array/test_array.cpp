#include "array.h"
#include <cstdio>
#include <iostream>
//using namespace std;

int main(int argc, char* argv[])
{
	/*Test default constuctor to ensure it doesn't generate an error, also try appending*/
	Array arr1;
	arr1.append(7);
	std::cout<<arr1;

	/*Test initialization with an integer value, constructor 1*/
	Array arr2(10,5);
	std::cout<<arr2;

	/*Test intialization with an array of elements, constructor 2*/
	int values1[] ={1,2,3,4,5,6,7,8,9,20,15};
  	Array arr3(9,values1);
	std::cout << arr3;
	
	/*Test copy constructor for single values*/
	Array arr4(10,values1);
	for(int i=0; i<arr4.size(); i++){
		arr4[i] = i*2;
	}
	std::cout<<arr4;

	/*Test copy constructor for array*/
	Array arr5 = arr4;
	std::cout<<arr5;
	
	/*Test to append arrays*/
	Array arr6;
	arr6.append(arr5);
	std::cout << arr6;

	/*Test overload + operator with different arrays*/
	Array arr7 = arr1 + arr3 + arr2 + arr4;
	std::cout<<arr7;
	
	/*Test overload + operator with repeated array*/
	Array arr8 = arr1 + arr2 + arr1 + arr2;
	std::cout << arr8;

	/*Test NULL array*/
	int* values2 = NULL;
	Array arr9(9, values2);
	std::cout<<arr9;

	//Final test is with valgrind to ensure there are no memory leaks
	
  	return(0);
}

