
#include "problem1.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

 	 // Put anything here that you think is appropriate to test your function
	int n=10; //initialize number of evenly-spaced values needed
	double min = 0; // minimum value
	double max = 5; // maximum value
	double array[n]; //initialize array
	char min_t = 'c';

	linspace(array, min, max, n); //prints sequence in ascending order
	printf("\n");
	
	linspace(array, max, min, n);//prints sequence in descending order
	printf("\n");
	
	linspace(array, min_t, max, n); //This prints casts the array as a double as declared in the function and starts the sequence with the corresponding ascii value
	printf("\n"); 
	
	linspace(array, 0, 0, 5); //should return a message saying they can't be zeros at same time
	printf("\n");

	linspace(array, 1, 5, 1); //should return 1
	printf("\n");

  	return(0);
}

