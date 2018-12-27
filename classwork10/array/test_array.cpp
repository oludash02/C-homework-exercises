#include "array.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  	Array arr;
  	arr.initialize(10, 5);
	cout << arr;
	arr.cleanup();

  	Array rtoo;
  	rtoo.initialize(0, 0);
  	rtoo = arr;
	rtoo.cleanup();

  	for(int i = 0; i < arr.size(); i++){
    	arr[i] = i * 2;
  	}

  	for(int i = 0; i < arr.size(); i++){
    	printf(" arr[%d] = %d\n", i, arr[i]);
  	}

  	for(int i = 0; i < rtoo.size(); i++){
    	printf("rtoo[%d] = %d\n", i, rtoo[i]);
  	}

	Array append_arr;
	append_arr.initialize(1,1);
	append_arr.append(arr);

	append_arr.append(7);
	cout<<append_arr;
	append_arr.cleanup();

  	return(0);
}

