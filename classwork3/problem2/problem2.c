
#include "problem2.h"
#include <stdio.h>

int find_power(int n)
{

  	// Fill in this function

  	// You'll want to replace this with something that returns a meaningful
  	// result.
  	int lastnum = 1; //initialize the last number of power of 2
	while(lastnum <= n)
	{
		lastnum = lastnum*2;
	}
	if(lastnum > n)
		lastnum = lastnum/2;

  	return(lastnum); 
}

