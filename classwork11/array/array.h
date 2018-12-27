#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

class Array{
  	/*
 	*Function declarations for the Array class
 	*
 	*/
	private:
		int m_size; //size of Array
		int *m_piArray; //pointer to integer arrays

	public:
		Array(); //default constructor
		~Array();
		Array(int length, int value); //constructor 1
		Array(int length, int* values); //constructor 2
		
		Array(const Array &arr); //copy constructor
		
		//overloaded operators for [] and =
		int& operator[](int);
		
		Array& operator=(const Array &);
		//Array& operator+(const Array &);
		Array operator+(const Array&) const;
		
		int size(); //returns current size of the Array
		void append(int x); //appends the element x to the end of the array
		void append(Array y); //appends all of the contents of y to the end of the array
		
		friend std::ostream& operator<<(std::ostream& os, const Array& arr);
};


#endif
