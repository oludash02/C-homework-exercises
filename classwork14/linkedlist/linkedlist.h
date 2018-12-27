#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdio>
#include <string>

//OutOfBoundsException handling
class OutofBoundsException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Index out of bounds";
		}
};

template<typename T>
struct Node
{
	T data;
	Node<T> *next;
	//Initialize the node;
	Node(T value) 
	{
		data = value;
		next = NULL;
	}
};

template<typename T>
class LinkedList //public Node
{

	private:
		int list_length; //length of list
		Node<T> *head; //pointer to head of linked list
		
	public:
		LinkedList(); //default constructor
		~LinkedList(); //destructor
		
		LinkedList(int length, T* values); //constructor initializes elements of the array
		LinkedList(const LinkedList &); //copy constructor
		
		int size() const; //returns current size of the LinkedList
		T& getItem(int n); //returns n-th item in the LinkedList
		
		void insert(T x, int pos); // insert x into the list at position pos
		void remove(int pos); //removes n-th item in the LinkedList
		void put_head(T value);
    	void put_tail(T value);
		LinkedList& operator=(const LinkedList &); //makes a deep copy of another LinkedList
		
		void print_list() const; //prints the list
		
};


//Default constructor
template<typename T>
LinkedList<T>::LinkedList()
{
	this->list_length = 0;
	this->head = NULL;
}

//Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T> *current_node = this->head;
	Node<T> *next_node = NULL;
	
	while(current_node != NULL)
	{
		next_node = current_node->next;
		delete current_node;
		current_node = next_node;
	}
	
	this->head = NULL;
}


//Copy constructor creates a deep copy of the Array
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &new_list): list_length(new_list.list_length)
{
	this->head = NULL; //initialize head of list
	Node<T> *temp_node = new_list.head; //make a shallow copy of head of new list
	Node<T> *next_node = NULL;
	
	while(temp_node != NULL) //while node is not NULL
	{	
		Node<T> *insert_node = new Node<T>(temp_node->data); //copy node data
		
		if(!this->head) //check if head has been previously assigned data
		{
			this->head = insert_node;
			next_node = this->head;	
		}
		else
		{
			next_node->next = insert_node;
			next_node = insert_node;
		}
	
		temp_node = temp_node->next;
	}
	
}



//This creates a deep copy on the input list via the assignment operator
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &new_list)
{
	if(&new_list != this) //check if not self
	{
		this->head = NULL;
		Node<T> *temp_node = new_list.head;		
		Node<T> *next_node = NULL;
		int count = 0;
		
		while(temp_node != NULL) //while node is not NULL
		{	
			Node<T> *insert_node = new Node<T>(temp_node->data); //copy node data
			insert_node->next = NULL; 
			
			if(next_node != NULL) //check if node elements has been previously assigned
				next_node->next = insert_node;
			else
				this->head = insert_node; //assign node elements to node of current list
			
			next_node = insert_node;
			temp_node = temp_node->next;
			count++;
		}
		
		//this->list_length = count; //set length to length of copied list
	}
	
	return *this;
}


/*
* put_head and put_tail are helper functions to make insert functions much simpler
*/
//Insert to head of Linked List
template<typename T>
void LinkedList<T>::put_head(T value)
{
  Node<T> *head_node=new Node<T>(value);
  head_node->next = this->head;
  this->head = head_node;
  this->list_length++;
}

//Inserts to tail of Linked List
template<typename T>
void LinkedList<T>::put_tail(T value)
{
  if (this->head == NULL) 
  {
    Node<T> *new_node=new Node<T>(value);
    this->head = new_node;
  } 
  else 
  {
    Node<T> *tail_node=NULL;
    Node<T> *node_ptr = this->head;
    while(node_ptr != NULL)
    {
    	tail_node = node_ptr;
    	node_ptr = node_ptr->next;
	}
    
    Node<T> *new_node=new Node<T>(value);
    tail_node->next = new_node;
  }
  
  this->list_length++;
}



//return size of a linked list
template<typename T>
int LinkedList<T>::size() const
{
	return(this->list_length);
}


//This prints contents of the Linked List
template<typename T>
void LinkedList<T>::print_list() const
{
	Node<T> *start = this->head;
	
	while(start != NULL)
	{
		std::cout << start->data << std::endl;
		start = start->next;
	}
	std::cout << std::endl;
}

//This returns the n-th item in the Linked List
template<typename T>
T& LinkedList<T>::getItem(int n)
{
	if(n < 0 || (n >= this->list_length))
	{
		throw OutofBoundsException();
		throw;
	}
	
	Node<T> *node_ptr = this->head;
	if(n == 0)
	{
		return node_ptr->data;
	}
	
	else
	{
		int count = 0;
		
		while(node_ptr != NULL)
		{
			if(count == n)
			{
				break;
			}
			count++;
			node_ptr = node_ptr->next;
		}
		
		return node_ptr->data;		
	}
	
}

//this removes element at position (pos) from a linked list 
template<typename T>
void LinkedList<T>::remove(int pos)
{
	if(pos < 0 || (pos >= this->list_length))
	{
		throw OutofBoundsException(); //throw exception index is out of bounds
		throw;
	}
	
	Node<T> *temp_node = NULL; //create temporary node
	Node<T> *node_ptr = this->head;
	int count=0;
	while(node_ptr != NULL) //run while node_ptr is not till you reach input position
	{
		if(count == pos)
			break;
		count++;
		temp_node = node_ptr;
		node_ptr = node_ptr->next; //go to next node in the list
	}
	
	if(temp_node == NULL) //if the current node is empty, set head to next node
	{
		this->head = node_ptr->next;
		delete node_ptr;
	}
	else
	{
		temp_node->next = node_ptr->next; //if current node is not empty, set it to head of next node
		delete node_ptr;
	}
	this->list_length--; //update list length
	
}


//This initializes a linked list with a set of values
template<typename T>
LinkedList<T>::LinkedList(int length, T* values): list_length(length)
{
	if(length == 0)
	{
		printf("Pointer to a null list\n");
		return;
	}
	
	this->head = NULL;
	for(int i=length-1; i>=0; i--)
	{
		Node<T> *new_node = new Node<T>(values[i]); //Set node elements to current values
		new_node->next = this->head;
		this->head = new_node;		
	}
}

//this inserts x into position pos in the linked list
template<typename T>
void LinkedList<T>::insert(T x, int pos)
{
	if(pos > this->list_length) //check if the index is valid
	{
		printf("Invalid index\n");
		return;
	}
	
	if(pos == 0)
	{
		put_head(x); //place value at the beginning of list if pos=0
		return;
	}
	
	
	Node<T> *node_ptr = this->head;
	int count=0;
	while(count != pos)
	{
		node_ptr = node_ptr->next; //iterate of list and stop of input position(pos)
		count++;
	}
	
	if(count == this->list_length)
	{
		put_tail(x); //place value at the end of list if pos=length
		return;
	}
	
	Node<T> *new_node = new Node<T>(x); //create new node
	new_node->next = node_ptr->next; //new node should point at current node
	node_ptr->next = new_node; //assign current node to new node
	this->head = node_ptr; //set this list
	this->list_length++;	
	
}

#endif