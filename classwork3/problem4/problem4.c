
#include "problem4.h"
#include <stdio.h>
#include <math.h>


Triangle getLarger(Triangle first, Triangle second)
{
  	Triangle t;

  	// Fill in this function

  	// You'll want to replace this with something that returns a meaningful
  	// result.
  	float area1, area2;
	
	area1 = fabs(((first.a.x)*(first.b.y - first.c.y)) + ((first.b.x)*(first.c.y - first.a.y)) + ((first.c.x)*(first.a.y - first.b.y)))/2; //fabs computes the absolute value of a floating point number
	area2 = fabs(((second.a.x)*(second.b.y - second.c.y)) + ((second.b.x)*(second.c.y - second.a.y)) + ((second.c.x)*(second.a.y - second.b.y)))/2;
	printf("Area 1: %.2f Area 2: %.2f\n", area1, area2);	
	if(area1 > area2)
		t = first;
	else
		t = second;
	
  	return(t); 
}

