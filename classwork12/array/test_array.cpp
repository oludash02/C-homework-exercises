#include "array.h"
#include <cstdio>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	
	/*
	* Test cases for type int
	*/
	
	/*Test default constuctor to ensure it doesn't generate an error, also try appending*/
	Array<int> arr1;
	arr1.append(7);
	std::cout<<arr1;

	/*Test initialization with an integer value, constructor 1*/
	Array<int> arr2(10,5);
	std::cout<<arr2;

	/*Test intialization with an array of elements, constructor 2*/
	int values1[] ={1,2,3,4,5,6,7,8,9,20,15};
  	Array<int> arr3(9,values1);
	std::cout << arr3;
	
	/*Test copy constructor for single values*/
	Array<int> arr4(10,values1);
	for(int i=0; i<arr4.size(); i++){
		arr4[i] = i*2;
	}
	std::cout<<arr4;

	/*Test copy constructor for array*/
	Array<int> arr5 = arr4;
	std::cout<<arr5;
	
	/*Test to append arrays*/
	Array<int> arr6;
	arr6.append(arr5);
	std::cout << arr6;

	/*Test overload + operator with different arrays*/
	Array<int> arr7 = arr1 + arr3 + arr2 + arr4;
	std::cout<<arr7;
	
	/*Test overload + operator with repeated array*/
	Array<int> arr8 = arr1 + arr2 + arr1 + arr2;
	std::cout << arr8;

	printf("\n");
	
	/*
	* Test cases for type char
	*/
	
	/*Test default constuctor to ensure it doesn't generate an error, also try appending*/
	Array<char> arr9;
	arr9.append('h');
	std::cout<<arr9;

	/*Test initialization with an integer value, constructor 1*/
	Array<char> arr10(10,'o');
	std::cout<<arr10;

	/*Test intialization with an array of elements, constructor 2*/
	char values2[] ={'H','e','l','l','o',' ','w','o','r','l','d'};
  	Array<char> arr11(11,values2);
	std::cout << arr11;
	
	/*Test copy constructor for single values*/
	Array<char> arr_new(8,values2);
	for(int i=0; i<arr_new.size(); i++){
		arr_new[i] = '*';
	}
	std::cout<<arr_new;
	
	/*Test overload + operator with repeated array*/
	Array<char> arr12 = arr9 + arr10 + arr11;
	std::cout << arr12;
	
	/*Test copy constructor for array*/
	Array<char> arr13 = arr11;
	std::cout<<arr13;
	
	/*Test to append arrays*/
	Array<char> arr14;
	arr14.append(arr11);
	arr14.append(' ');
	arr14.append(arr10);
	std::cout << arr14;
	
	printf("\n");
	
	/*
	* Test cases for type string
	*/
	
	/*Test default constuctor to ensure it doesn't generate an error, also try appending*/
	Array<std::string> arr15;
	arr15.append("Hello");
	std::cout<<arr15;

	/*Test initialization with an integer value, constructor 1*/
	Array<std::string> arr16(5,"ee200");
	std::cout<<arr16;

	/*Test intialization with an array of elements, constructor 2*/
	std::string values3[] ={"Hello", " world", " it is Victor", " working", " on", " ee200", " homework 12"};
  	Array<std::string> arr17(5,values3);
	std::cout << arr17;
	
	/*Test overload + operator with repeated array*/
	Array<std::string> arr18 = arr15 + arr16 + arr17;
	std::cout << arr18;
	
	/*Test copy constructor for array*/
	Array<std::string> arr19 = arr18;
	std::cout<<arr19;
	
	/*Test to append arrays*/
	Array<std::string> arr20;
	arr20.append(arr17);
	arr20.append(" ");
	arr20.append(arr16);
	std::cout << arr20;
	//Final test is with valgrind to ensure there are no memory leaks
  	return(0);
}


