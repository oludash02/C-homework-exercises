
#include "problem3.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

 	// Put anything here that you think is appropriate to test your function
	int arr[] = {7, 2, 10, 13, 15, 8, 3, 20}; //test case 1
	int arr2[] = {7, 7, 3, 4, 5, 13, 15, 8, 3, 20}; //test case 2
	int arr3[] = {7, 5, 7, 4, 2, 3, 4, 5, 13, 15, 8, 3, 20}; //test case 3
	int arr4[] = {1, 1, 1, 0, 0, 0, 0, 0}; //no sequences of increasing integers
	int arr5[] = {};	
	int *output;
	size_t n = sizeof(arr) / sizeof(arr[0]); //find length of array

	output = find_sequence(arr, n); // test case for example array
	printf("Points to %i \n\n", *output);

	output = find_sequence(arr2, 0); //test case for n = 0
	if(output == NULL)
		printf("Returns a NULL for n=0 \n\n");

	output = find_sequence(arr2,10); //test case for repeated numbers
	printf("Points to %i \n\n", *output);

	output = find_sequence(arr3, 13); //test case for repeated numbers
	printf("Points to %i \n\n", *output);

	output = find_sequence(arr4, 8); //test case for no sequence of increasing integers
	if(output == NULL)
		printf("Returns a NULL for no sequences of increasing integers\n\n");
	
	output = find_sequence(arr5, 4); //test case for empty arrays
	if(output == NULL)
		printf("Returns a NULL for empty array\n\n");

  	return(0);
}

