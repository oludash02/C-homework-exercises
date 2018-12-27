
#include "problem5.h"
#include <stdlib.h>
#include <stdio.h>

void print_random(int n, int max)
{

 	 // Fill in this function
 	int i;
	int val;

	for(i=0; i<n; ++i)
	{
		val = rand() % (max+1); //Added 1 so we have 0 - max not 0 - (max-1)
		printf("%i \n", val);
	}

}

