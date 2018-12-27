
#include "problem3.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

  // Put anything here that you think is appropriate to test your function
  // You can define triangles here, since the struct is declared in the header
  	const Triangle *t;
	Triangle first;
	Triangle second;
	//const Triangle *h;
	const Triangle *h = NULL; // Test case 1, uncomment and comment out former declaration to use
	//const Triangle *g = NULL;
	const Triangle *g; //Test case 2, uncomment this and comment out former declaration to use

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

	//h = &second; //Test case 3 comment this out if h is null
	g = &second; // Test case 4, uncomment this to use
	t = getLarger(h,g);

  	return(0);
}

