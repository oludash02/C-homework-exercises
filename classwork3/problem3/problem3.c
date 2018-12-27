
#include "problem3.h"
#include <stdio.h>
#include <math.h>

double calculate(double x, char operation, double y)
{

  	// Fill in this function

 	// You'll want to replace this with something that returns a meaningful
  	// result.
  	double result;

	switch(operation)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		if(y == 0)
			printf("Divide by zero error\n");
		else
			result = x / y;
		break;
	case '^':
		result = pow(x,y);
		break;
	default:
		printf("**** Invalid inputs/sequence ****\n");
		printf("Sequence: x, operation, y");
	}
  	return(result); 
}

