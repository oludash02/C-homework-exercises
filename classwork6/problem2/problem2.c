
#include "problem2.h"
#include <stdio.h>
#include <string.h>

void lower(char* str)
{

     /*
     This function converts the characters in a string to lowercase
     characters which are not letters are left unmodified and a NULL string
     doesn't crash the function
     */

    int i = 0;
    const int upperTolower = 32; //this is added to convert an uppercase to lower case
    //int lengthOfchar = strlen(str); //finds the length of the string

    if(str == NULL)
    {
        printf("");
    }
    else if(strcmp(str, "") == 0)
    {
        printf("");
    }
    else
    {
        
        while(str[i] != '\0')
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + upperTolower;
            }
            i++;
        }

        //for(i=0; str[i] != '\0'; i++)
        //{
            //printf("%c", str[i]);
        //}
    }

    //printf("\n");
}

