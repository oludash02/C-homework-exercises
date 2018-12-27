#include "mon.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


void print_tree(Element* root_ptr) {
	/*
	Function prints the nodes in the tree and left and right child
	*/
   if (root_ptr == NULL)
      return;

   print_tree(root_ptr->left_child);
   print_tree(root_ptr->right_child);

   printf("name = %s\n", root_ptr->name);
}

Element* create_left(Element* root, char* data)
{
	/*
	function creates left child in the tree
	*/
	
    Element *node_ptr = NULL;

    //check if root and data are valid
    if(data == NULL)
        printf("NULL data entered\n");
    else if(root == NULL)
        root = (Element *)malloc(sizeof(Element));

    else
    {
        //check if left is NULL
        if(root->left_child == NULL)
        {
            //Allocate memory for node_ptr
            node_ptr = (Element *)malloc(sizeof(Element));
            assert(node_ptr != NULL); //this asserts that allocated memory is not NULL

            //Initialize new node
            node_ptr->left_child = NULL;
            node_ptr->right_child = NULL;

            node_ptr->name = (char *)malloc(sizeof(char) * strlen(data));
            assert(node_ptr->name != NULL);
            strcpy(node_ptr->name, data);

            root->left_child = node_ptr; //assign data to node
        }
    }

    return node_ptr;
}



Element* create_right(Element* root, char* data)
{
	/*
	function creates right child in the tree
	*/
	
    Element* node_ptr = NULL;

     //check if root and data are valid
    if(data == NULL)
        printf("NULL data entered\n");
    else if(root == NULL)
        root = (Element *)malloc(sizeof(Element)); //allocate memory to root if it's NULL
    else
    {
        //check if right is NULL
        if(root->right_child == NULL)
        {
            //Allocate memory for node_ptr
            node_ptr = (Element *)malloc(sizeof(Element));
            assert(node_ptr != NULL);

            //Initialize new node
            node_ptr->left_child = NULL;
            node_ptr->right_child = NULL;

            node_ptr->name = (char *)malloc(sizeof(char) * strlen(data));
            assert(node_ptr->name != NULL);
            strcpy(node_ptr->name, data);

            root->right_child = node_ptr; //assign data to node
        }
    }

    return node_ptr;
}


void free_tree(Element* root)
{
	/*
	Function frees up memory so there are no leaks
	*/
	
    if(root == NULL)
    {
        printf("root is already free\n");
    }
    if(root != NULL && root->left_child != NULL)
    {
       //Recurse
       free_tree(root->left_child); //free left child
    }
    if(root != NULL && root->right_child != NULL)
    {
      //Recurse
       free_tree(root->right_child);//free right child
    }

	/* deallocate the name field */
    if (root->name != NULL) {
       free(root->name);
       root->name = NULL;
    }
    free(root);
    root = NULL;
 
}

//Would complete this function and the main loop then test with valgrind as part of my late submission
int write_tree(FILE* f, Element* e)
{
	/*
	function writes an Element to a file
	*/
	
    //Check if file is valid
    if(f == NULL)
    {
        printf("null/invalid file pointer\n");
    }
    else
    {

        if(e != NULL && e->left_child != NULL)
        {
            if(fprintf(f, "{") != strlen("{"))
              return -1;
            if(write_tree(f, e->left_child) == -1)
                return -1;
        }
        else
        {
            if(fprintf(f, "{") != strlen("{"))
              return -1;
            if(fprintf(f, "NULL ") != strlen("NULL "))
                return -1;
        }

        if(e != NULL && e->right_child != NULL)
        {
            if(write_tree(f, e->right_child) == -1)
                return -1;
        }
        else
        {
            if(fprintf(f, "NULL ") != strlen("NULL "))
                return -1;
        }

        if(e != NULL && e->name != NULL)
        {
            if(fprintf(f, e->name) != strlen(e->name))
                return -1;
            if(fprintf(f, "}") != strlen("}"))
              return -1;
        }
        else
            return -1;

        return 0;
    }
}


Element* load_tree(FILE* f)
{
	/*
	function loads tree from a file
	*/
	
    Element* node_ptr = NULL;
    Element* left_node_ptr = NULL;
    Element* right_node_ptr = NULL;

    char val=' ';
    char* buf = NULL;
    int maxbuf_len = 1024;
    int buflen =0;

    if(f == NULL)
    {
        printf("Error: entered null file\n");
        return NULL;
    }

    buf = (char *)calloc(maxbuf_len, sizeof(char));
    assert((buf != NULL));

    if(fscanf(f, "%c", &val) != sizeof(char))
    {
        free(buf);
		buf = NULL;
		printf("Error: Invalid input stream\n");
		return NULL;
    }

    if( val == '{' )
    {
        left_node_ptr = load_tree(f);
        right_node_ptr = load_tree(f);

        if(fscanf(f, "%c", &val) != sizeof(char))
        {
			free(buf);
			buf = NULL;
            printf("Error: could not find {\n");
            return NULL;
        }
    }

    /* if either a name string or keyword NULL */
    while((val != '}' && (val != ' ')))
    {
       //get here if it's a name string
       buf[buflen] = val;
       buflen+=1;

       if(fscanf(f, "%c", &val) != sizeof(char))
       {
			free(buf);
			buf = NULL;
           	printf("Error: could not find a named string\n");
           	return NULL;
       }
    }

    
    if(strcmp((const char*)buf, "NULL") == 0)
	{
		free(buf); 
		buf = NULL;
     	return NULL;
	}

    else
    {
        //Create a new node
        node_ptr = (Element*)malloc(sizeof(Element));
        node_ptr->left_child = left_node_ptr;
        node_ptr->right_child = right_node_ptr;
        node_ptr->name = (char*)malloc(sizeof(char) * (buflen + 1));
        strcpy(node_ptr->name, buf);
    }
	free(buf);
	buf = NULL;

    return node_ptr;
}
