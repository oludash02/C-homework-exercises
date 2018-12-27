#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
#include <cstdio>
#include <vector>
#include <pthread.h>
#include <cstdlib>
#include <thread>
#include <mutex>


template<typename T>
class PriorityQueue{
	
	private:
		std::vector<T> data;
		std::mutex mx;

	public:
		PriorityQueue(); //default constructor
		~PriorityQueue(); //destructor
		PriorityQueue(const PriorityQueue &); //copy constructor
		PriorityQueue& operator=(const PriorityQueue &); //assignment operator
		int size() const; //returns current number of elements in PQ
		T top() const; //returns the first item in PQ
		void push(T x); //add element x to PQ
		void pop(); //remove top item in PQ
		
		//helper functions...for root starting at index 0 of an array
		//swap function, input arguments are passed by reference
		void swap(T& xr, T& yr)
		{
			T temp = xr;
			xr = yr;
			yr = temp;
		}
		
		int parent(int index) {
			return ((index-1)/2); //return index of parent
		}
		int leftChild(int index){
			return (2 * (index + 1) - 1); //return index of left child of parent at index
		}
		
		int rightChild(int index){ 
			return (2 * (index) + 2); //return index of right child of parent at index
		}
		
		//bubble up the heap
		void bubble_up(int idx)
		{
			int prt_idx = parent(idx); //get parent index
			
			if(data[prt_idx] < data[idx]) //check if value at parent index is less than value at current index
			{
				swap(data[idx], data[prt_idx]); //swap if less
				bubble_up(prt_idx); //recursive call
			}	
		}
		
		//bubble down the heap
		void bubble_down(int idx, int left_idx, int right_idx)
		{
			int max = idx;
				
			//Compare elements of both child
			if(left_idx < size() && data[left_idx] > data[idx]) //check if value at left child greater than value at current index
				max = left_idx; //set max index to left idx
			
			if(right_idx < size() && data[right_idx] > data[max]) //check if value at right child greater than value at current index
				max = right_idx;
			
			if(max != idx) //if final index is not equal to input index
			{
				left_idx = leftChild(max); //get left child index
				right_idx = rightChild(max); //get right child indx
				swap(data[idx], data[max]); //swap
				bubble_down(max, left_idx, right_idx); //recursive call
			}
		}
		
		//print heap
		void print_queue()
		{
			for(int i=0; i<this->size(); i++)
			{
				std::cout<< "| " << this->data[i] << " |" << std::endl;
			}
			printf("\n");
		}
		
};

//Creates the default constructor for Priority Queue
template<typename T>
PriorityQueue<T>::PriorityQueue()
{
	std::vector<T> vec;
	this->data = vec;
}

//default constructor
template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	data.clear();
}

//copy constructor makes a deep copy of the Priority Queue
template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &p_queue)
{
	int n_size = p_queue.size();
	
	for(int i=0; i<n_size; i++)
	{
		data.push_back(p_queue.data[i]);
	}
}

//assignment operator assigns one PriorityQueue to another using a deep copy
template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& p_queue)
{
	if(this != &p_queue) //check if Priorty Queue is different from this
	{
		std::vector<int> new_data; //create temporary vector to store heap values
		for(int i=0; i<p_queue.size(); i++)
		{
			new_data.push_back(p_queue.data[i]);
		}
		
		data.clear(); //clear previous heap data
		data = new_data; //assign new data
	}
	
	return *this;
}


//returns the size of the Priority Queue
template<typename T>
int PriorityQueue<T>::size() const
{
	return this->data.size();
}

//this adds elements to the Priority Queue
template<typename T>
void PriorityQueue<T>::push(T x)
{
	std::lock_guard<std::mutex> guard(mx);//this does the mutex.lock() and mutex.unlock() 
										  //using Resource Acquisition Is Initialization so it always unlocks even if an exception occurs
	data.push_back(x);
	int q_size = size();
	int i = q_size - 1;

	bubble_up(i); //bubble up to ensure max-heap property is maintained
}

//this removes the top item in the Priority Queue
template<typename T>
void PriorityQueue<T>::pop()
{
	std::lock_guard<std::mutex> guard(mx);
	if(data.size() == 0)
	{
		return;
	}
	
	T last_val = this->data.back(); //get the last value in the heap
	data[0] = last_val; //replace root value with last value before popping. This avoids having an empty root node
	data.pop_back(); //removes the last element in the heap
	
	//Bubble down
	int curr_idx = 0;
	int left_idx = leftChild(curr_idx); //get current left child index
	int right_idx = rightChild(curr_idx); //get current right child index
	bubble_down(curr_idx, left_idx, right_idx); //bubble down to ensure max-heap property is maintained
	
}

//This returns the root element in the heap
template<typename T>
T PriorityQueue<T>::top() const
{
	if(this->data.size() == 0)
	{
		printf("Empty Heap, contains no top\n");
		exit(0);
	}
		
	return this->data.at(0); //returns the first element of array/top of heap
}

#endif
