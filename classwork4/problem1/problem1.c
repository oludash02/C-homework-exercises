#include <stdio.h>
#include <math.h>

double calculate(double x, char operation, double y)
{
	/*
	This function performs addition, subtraction, division, multiplication
	and power for a two input numbers and one of the operation listed above
	*/

	double result;

	switch(operation)
	{
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '/':
			if(y==0)
				printf("Division by zero\n");
			else
				result = x / y;
			break;
		case '*':
			result = x * y;
			break;
		case '^':
			result = pow(x,y);
			break;
		default:
			printf("**** Invalid inputs/ sequence ****\n");
			printf("Input format: x, operation, y \n");
			break;
	}

	return (result);
}


int main(int argc, char* argv[])
{

  // Your code goes here
  // Feel free to add other functions to this file, but don't add
  // other files since the autograder won't know about them.
 	double result,  integer1, integer2;
	char operation;

	printf("Input: integer1 operator integer2: ");

	scanf("%lf %c %lf", &integer1, &operation, &integer2);

	result = calculate(integer1, operation, integer2);
	printf("Result = %.13lf\n", result);
 	return(0);
}

