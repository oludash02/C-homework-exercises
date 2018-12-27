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

		//overloaded operators for [] and =
		int &operator[](int);
		Array& operator=(const Array &);

		void initialize(int size, int val);//sets uo the Array with storage for 'size' elements initialized to val
		void cleanup(); // frees all malloced memory
		int size(); //returns current size of the Array
		void append(int x); //appends the element x to the end of the array
		void append(Array y); //appends all of the contents of y to the end of the array
		void print() const; //prints contents of an array
		friend std::ostream& operator<<(std::ostream& os, const Array& arr);
};


#endif
