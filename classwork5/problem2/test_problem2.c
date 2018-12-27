
#include "problem2.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

 	// Put anything here that you think is appropriate to test your function
	int arrays[] = {13,15,6,14,7,5,9,11,18,4}; //initialize arrays
	int *output;
	int array_length = 10;
	int arrays2[] = {1,1,1,1,0,0};
	int arrays3[] = {};
	int arrays4[] = {-1, -2, -3, -5, -10};


	size_t n = sizeof(arrays) / sizeof(arrays[0]);
	//printf("Actual length of array: %i\n", n);
	//
	output = find_min(arrays, array_length); //for positive elements of an array
	printf("Smallest element: %d\n", *output);

	output = find_min(arrays2, 6); //test case for repeating elements of an array
	printf("Smallest element: %d\n", *output);
	
	output = find_min(arrays4, 5); // test case for negative elements of an array
	printf("Smallest element: %d \n", *output);

	output = find_min(arrays2, 0); //test case for an empty array
	if(output == NULL)
		printf("return value is NULL for empty array\n");

  	return(0);
}

