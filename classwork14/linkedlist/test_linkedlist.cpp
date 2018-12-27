#include "linkedlist.h"
#include <cstdio>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	/*
	*Test cases for integers
	*/
	int values[] = {51,2,3,71,12,4,5,7,8,9,11,54,14,66,223,567};
	LinkedList<int> list; //Test default constructor
	
	//Test case 1: insert function
	list.insert(8,0);
	list.insert(2,1);
	list.insert(3,2);
	list.insert(7,3);
	list.insert(9,4);
	list.insert(100,5);
	list.insert(50,6);
	list.print_list(); //test print function
	printf("%d \n", list.getItem(3)); //test getItem function
	printf("%d \n\n", list.size()); //test size function
	
	//test remove function
	list.remove(0);
	list.print_list();
	printf("%d \n\n", list.size()); //test size function
	
	//Test  initialization
	LinkedList<int> list2(5,values);
	list2.print_list();
	printf("%d \n\n", list2.size()); //test size function
	printf("\n");
	
	//Test Copy constructor
	LinkedList<int> list3(list2);
	list3.print_list();
	printf("%d \n\n", list3.size()); //test size function
	
	//Test assignment operator
	LinkedList<int> list4 = list;
	list4.insert(123,list4.size());
	list4.print_list();
	printf("%d \n\n", list4.size()); 
	
	/*
	*Test cases for chars
	*/
	char values2[] = {'h','e','l','l','o',' ','w','o','r','l','d'};
	LinkedList<char> list5; //Test default constructor
	
	//Test case 1: insert function
	list5.insert('a',0);
	list5.insert('b',1);
	list5.insert('c',2);
	list5.insert('d',3);
	list5.insert('e',4);
	list5.insert('f',5);
	list5.print_list(); //test print function
	printf("%c \n", list5.getItem(list5.size()-1)); //test getItem function
	printf("%d \n\n", list5.size()); //test size function
	
	//test remove function
	list5.remove(0);
	list5.print_list();
	printf("%d \n\n", list5.size()); //test size function
	
	//Test  initialization
	LinkedList<char> list6(7,values2);
	list6.print_list();
	printf("%c \n", list6.getItem(6)); //test getItem function
	printf("%d \n", list6.size()); //test size function

	printf("\n");
	
	//Test Copy constructor
	LinkedList<char> list7(list6);
	printf("%d \n\n", list7.size()); //test size function
	list7.insert('!', list6.size());
	list7.print_list();
	
	//Test assignment operator
	LinkedList<char> list8 = list7;
	list8.print_list();
	
	
	/*
	*Test cases for strings
	*/
	std::string values3[] = {"Hello","Accelerated","Programming","in","C"," & ", "C++"};
	LinkedList<std::string> list9; //Test default constructor
	
	//Test case 1: insert function
	list9.insert("joe", 0);
	list9.insert("eric",1);
	list9.insert("mike",2);
	list9.insert("victor",3);
	list9.print_list(); //test print function
	printf("%s \n", list9.getItem(3).c_str()); //test getItem function
	printf("%d \n\n", list9.size()); //test size function
	
	//test remove function
	list9.remove(1);
	list9.print_list();
	printf("%d \n\n", list9.size()); //test size function
	
	//Test  initialization
	LinkedList<std::string> list11(3,values3);
	list11.print_list();
	printf("%s \n", list11.getItem(0).c_str()); //test getItem function
	printf("%d \n", list11.size()); //test size function
	
	//Test Copy constructor
	LinkedList<std::string> list12(list9);
	printf("%d \n\n", list12.size()); //test size function
	list12.insert("!", list9.size());
	list12.print_list();
	
	//Test assignment operator
	LinkedList<std::string> list13 = list12;
	list13.print_list();

	return 0;
	
}