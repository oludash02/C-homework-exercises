
#include "problem2.h"
#include <stdio.h>

int* find_min(int* array, int n)
{

	int *result; //initialize pointer
	int i;

	if(array == NULL)
	{
		printf("You entered a null pointer\n");
		result = NULL;
	}
	else
	{
		int smallest_number = array[0]; //set minimum value as the first number in the array
		int smallest_index = 0; //set index of minimum number to 0 (first number in array)
	
		if(n < 0)
		{
			printf("n cannot be less than 0\n");
		}
		else if(n == 0)
		{
			result = NULL; //returns NULL if n is 0
		}
		else if(n > 0)
		{
			for (i=1; i<n; i++)
			{
				if(array[i] < smallest_number)
				{
					smallest_index = i; //update the index of smallest element
					smallest_number = array[i]; //update value of smallest number
				}
			}
			result = (array + smallest_index);
		}
		else
		{
			printf("check inputs again \n");
		}
	
	}
	
	return result;
	
}

