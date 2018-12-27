
#include "problem4.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

  	// Put anything here that you think is appropriate to test your function
  	// You can define triangles here, since the struct is declared in the header
 	Triangle t;
	
	Triangle first;
	Triangle second;
	
	first.a.x = 1;
	first.a.y = 2;
	first.b.x = 2;
	first.b.y = 5;
	first.c.x = 4;
	first.c.y = 2;

	second.a.x = 1;
	second.a.y = 2;
	second.b.x = 4;
	second.b.y = 6;
	second.c.x = 6;
	second.c.y = 2;

	t = getLarger(first, second);

	if((t.a.x == first.a.x) & (t.a.y == first.a.y) & (t.b.x == first.b.x) & (t.b.y == first.b.y) & (t.c.x == first.c.x) & (t.c.y == first.c.y))
	{
		printf("First triangle has a larger area\n");
	}
	else
	{
		printf("Second triangle has a larger area\n");
	}

  	return(0);
}

