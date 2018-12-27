
#include "problem3.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{

  	// Put anything here that you think is appropriate to test your function
 	// e.g, double result = calculate(37, '+', 1);
 	//      if(result ...
	double result;
	char operation = '-';
	result = calculate(37, operation, 10);
	printf("result: %.2f", result);

  	return(0);
}

