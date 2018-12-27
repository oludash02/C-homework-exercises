
#include "problem1.h"
#include <stdio.h>
#include <stdbool.h>

int print_factors(int n)
{
	int return_val=0;
	int i,j;
	if(n <=1)
	{
		return (return_val-1); //returns -1 for invalid inputs
	}
	else
	{
	    bool testPrime = false; //variable hold to check if number is prime or not

	    //check if n is divisible by 2
        printf("Prime factors of %i: \n", n);

        while(n%2 == 0)
        {
            printf("%i ", 2);
            n = n/2;
        }

        for(i=3; i<=n; ++i)
        {

            while(n%i == 0)
            {
                testPrime = true;
                printf("%i ", i);
                n = n/i; //update value of n
            }

        }

        if(testPrime == false)
            printf("%i ", n);

		return return_val;
	}

}