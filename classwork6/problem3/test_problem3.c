
#include "problem3.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

    // Put anything here that you think is appropriate to test your function
    const char* str = "Hello, how are you doing today?";
    unsigned int histogram[26]; //initialize histogram with zeros to compute
    int len = 0;
    len = strlen(str); //computes the length of the character

    find_frequency(str, len, histogram);
    return(0);
}

