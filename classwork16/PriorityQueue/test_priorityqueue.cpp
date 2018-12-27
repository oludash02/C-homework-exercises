#include "priorityqueue.h"
#include <cstdio>
#include <iostream>
#include <thread>

//push for thread 1
void func_push(PriorityQueue<int>& qt)
{
	for(int i=0;i<=50;i++)
	{
		if( i%5 == 0)
			qt.push(i);		
	}
	
	qt.print_queue();
}

//pop for thread 2
void func_pop(PriorityQueue<int>& pt)
{
	for(int i=0; i<=5; i++)
	{
		pt.pop();
	}

	pt.print_queue();
}


int main(int argc, char* argv[])
{
	/*
	* Tests using the int data type
	*/
	//Test case 1: check the push function
	PriorityQueue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(11);
	q.push(6);
	q.push(5);

	//Check size of the priority queue
	printf("Size: %d\n", q.size());
	std::cout << q.top() << std::endl; //check if top element is correct
	q.print_queue(); //print the heap
	
	q.pop(); //remove max element
	q.pop(); //remove max element
	q.print_queue(); //print heap
	printf("Size: %d\n\n", q.size());
	
	//Test case 2: check assignment operator
	PriorityQueue<int> assign = q;
	assign.push(12);
	assign.push(7);
	assign.print_queue();
	q.print_queue(); //check if a deep copy of q was actually made. elements of q should remain same
	
	while(assign.size() > 0)
	{
		printf("%d ", assign.top()); 
		assign.pop();
	}
	printf("\n\n");
	
	//Test case 3: check push, pop and top of repeated values
	PriorityQueue<int> new_q;
	new_q.push(13);
	new_q.push(11);
	new_q.push(6);
	new_q.push(7);
	new_q.push(7);
	new_q.push(5);
	new_q.push(3);
	new_q.push(5);
	new_q.print_queue();
	
	while(new_q.size() > 0)
	{
		printf("%d ", new_q.top()); 
		new_q.pop();
	}
	printf("\n\n");
	
	//Test case 4: Check copy constructor
	PriorityQueue<int> copy(new_q); //copy new_q which is empty and push new elements to it
	copy.push(8);
	copy.push(9);
	copy.push(3);
	copy.push(10);
	copy.push(2);
	copy.pop(); //pop once
	copy.print_queue();
	
	
	/*
	* Tests using the char data type
	*/
	//Test case 1: check the push function
	PriorityQueue<char> qc;
	qc.push('h');
	qc.push('e');
	qc.push('l');
	qc.push('y');
	qc.push('a');
	qc.push('z');

	//Check size of the priority queue
	printf("Size: %d\n", qc.size());
	std::cout << qc.top() << std::endl; //check if top element is correct
	qc.print_queue(); //print the heap
	
	qc.pop(); //remove max element
	qc.pop(); //remove max element
	qc.print_queue(); //print heap
	printf("Size: %d\n\n", qc.size());
	
	//Test case 2: check assignment operator
	PriorityQueue<char> assign_c = qc;
	assign_c.push('f');
	assign_c.push('t');
	assign_c.print_queue();
	qc.print_queue(); //check if a deep copy of q was actually made. elements of q should remain same
	
	while(assign_c.size() > 0)
	{
		printf("%c ", assign_c.top()); 
		assign_c.pop();
	}
	printf("\n\n");
	
	//Test case 3: check push, pop and top of repeated values
	PriorityQueue<char> new_qc;
	new_qc.push('g');
	new_qc.push('j');
	new_qc.push('v');
	new_qc.push('o');
	new_qc.push('i');
	new_qc.push('j');
	new_qc.push('g');
	new_qc.push('k');
	new_qc.print_queue();
	
	while(new_qc.size() > 0)
	{
		printf("%c ", new_qc.top()); 
		new_qc.pop();
	}
	printf("\n\n");
	
	//Test case 4: Check copy constructor
	PriorityQueue<char> copy_c(new_qc); //copy new_q which is empty and push new elements to it
	copy_c.push('x');
	copy_c.push('c');
	copy_c.push('r');
	copy_c.push('b');
	copy_c.push('m');
	copy_c.pop(); //pop once
	copy_c.print_queue();


	//Simple Test with mutexes

	PriorityQueue<int> mq;
	std::thread t1(func_push, std::ref(mq)); //pass the mq object by referenced required for C++ thread
	
	std::thread t2(func_pop, std::ref(mq)); //trying popping from mq

	t1.join();
	t2.join();

  return(0);
}
