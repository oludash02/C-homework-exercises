
#include "problem3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const Triangle* getLarger(const Triangle* first, const Triangle* second)
{
	/*
	This function returns a pointer to the larger of two triangles and also returns
	a non_NULL triangle as larger if one of the triangles is a NULL
	*/
  	const Triangle* t;
		
	if(second==NULL & first != NULL) //returns the first triangle if second is NULL
    {
		t = first;
        printf("t1\n");
    }
    else if(first==NULL & second != NULL) //returns the second triangle if first is NULL
    {
        t = second;
        printf("t2\n");
    }
    else if(second==NULL & first==NULL) //returns a NULL if both are NULL
    {
        t = NULL;
        printf("neither\n");
    }
    else //returns a pointer to a structure  if both are not NULL
    {
        float area1, area2;
		
        area1 = fabs((((*first).a.x)*((*first).b.y - (*first).c.y)) + (((*first).b.x)*((*first).c.y - (*first).a.y)) + (((*first).c.x)*((*first).a.y - (*first).b.y)))/2;
        area2 = fabs((((*second).a.x)*((*second).b.y - (*second).c.y)) + (((*second).b.x)*((*second).c.y - (*second).a.y)) + (((*second).c.x)*((*second).a.y - (*second).b.y)))/2;
        printf("Area 1: %.2f Area 2: %.2f\n", area1, area2);

        if(area1 > area2)
        {
            t = first;
            printf("t1\n");
        }

        else
        {
            t = second;
            printf("t2\n");
        }

    }
  	

  	return(t); 
}

