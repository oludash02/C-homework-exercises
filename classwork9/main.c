
#include "mon.h"

int main(int argc, char* argv[])
{
  // This is the example code that was used to generate sample.mon
  // It could be written much more nicely using create_left and create_right
  	Element z = { .name = "zebra", .left_child = NULL, .right_child = NULL };
  	Element y = { .name = "yak", .left_child = NULL, .right_child = NULL };
  	Element x = { .name = "xylophone", .left_child = NULL, .right_child = NULL };
  	Element b = { .name = "baboon", .left_child = &x, .right_child = &y };
  	Element a = { .name = "aardvark", .left_child = &b, .right_child = &z };

  	FILE* f = fopen("sample.mon", "r");
  	Element* root_ptr = NULL; //initialize to NULL to avoid dangling pointer

  	root_ptr = load_tree(f);
  	//print_tree(root_ptr); //Output only the names to confirm load_tree works correctly
  
  	FILE* f2 = fopen("sample2.mon", "w");
  	write_tree(f2, &a);
	
	free_tree(root_ptr);
  	fclose(f);
  	fclose(f2);
  	f = NULL;
  	f2 = NULL;
	return 0;
}

