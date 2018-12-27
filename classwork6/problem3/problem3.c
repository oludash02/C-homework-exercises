
#include "problem3.h"
#include <stdio.h>
#include <string.h>

void find_frequency(const char* str, int len, unsigned int histogram[26])
{
    /*
    This function computes the histogram containing a count of the
    occurrences of each character int the string.
    */
    unsigned int histogram2[26] = {0};
    histogram = histogram2; //just to set all values in histogram to 0
    int i = 0, j;
    int find_index = 0; //find the index of the current chars
    char start_char = 97;
    int len_of_str = 0;
    len_of_str = strlen(str);
    //printf("length of string %i\n", len_of_str);

    if(str == NULL || len == 0)
    {
        printf("You entered an empty string or inputted length = 0\n");
    }
    else if(len != len_of_str)
    {
        printf("Length of string doesn't match the value of len\n");
    }
    else
    {
        while((str[i] != '\0') && i < len)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                find_index = str[i] - 'a';
                histogram[find_index]++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                find_index = str[i] - 'A';
                histogram[find_index]++;
            }
            i++;
        }

        /*
        This prints the characters and corresponding frequency
        */
        printf("Character \t Frequency\n");

        for(j=0; j<26; j++)
        {
            printf("%4c\t\t%4i \n", (start_char+j), histogram[j]);
        }
    }

}

