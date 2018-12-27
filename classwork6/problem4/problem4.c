
#include "problem4.h"
#include <string.h>

const char* find_shortest(const char * const * strings, int len)
{

    /*
    This function finds the shortest string, given an array of strings
    and returns a pointer to it.
    */
    int i;
    int each_str_len[len];
    const char* result;
    int index;
    int index_null; //stores the index of the null element

    if(strings == NULL) //this checks if there's a null string
        result = NULL;

    else
    {
        for(i=0; i<len; i++)
        {
            if(strings[i] == NULL)
            {
                index_null = i;
                continue;
            }
            index = i-len+2;

            each_str_len[i] = strlen(strings[i]); //store length of each non-null string
        }
        
        
        for(i=0; i<len; i++)
        {
            if(i == index_null)
                continue;
            if((each_str_len[i] < each_str_len[index]))
            {
                index = i; //return index of string with shortest length
            }
        }

        result = strings[index];
        }

    return result;

}

