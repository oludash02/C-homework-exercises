
#include "problem1.h"
#include <stdio.h>

void linspace(double* array, double min, double max, int n)
{

  	//Function outputs a set of linearly spaced values from min to max inclusive
 	
	int i; //initialize counters for filling and displaying array contents
	double common_diff; //estimates the difference between successive numbers

	if(array == NULL)
	{
		printf("You entered a null pointer\n");
	}
	else
	{
		if(n <= 0)
		{
			printf("n cannot be less than or equal to 0\n");
		}
		else if(n==1)
		{
			array[0] = min;
			printf("%.4f \n", array[0]);
		}
		else if(n > 1)
		{
			if(min==0 && max == 0)
			{
				printf("Max and Min values cannot be zero\n");
			}
			else
			{
				common_diff = ((max - min) / (double)(n-1)); //calculates the common difference between numbers
				array[0] = min; //initial value in array is set to min

				for(i=1; i<n; i++)
				{
					array[i] = array[i-1] + common_diff;
				}

				for(i=0; i<n; i++)
				{
					printf("%.4f ", array[i]);
				}
			}
			
		}
		else
		{
			printf("Invalid inputs \n");
			printf("Check your inputs again \n");
		}
		
		printf("\n");	
			
	}
	
}

