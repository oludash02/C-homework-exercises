
#include "problem2.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

    char str[] = "HI HOpE yOU are DOING good"; //test case 1
    lower(str);

    char str2[] = ""; //test case 2, NULL string
    lower(str2);

    char str3[] = "ARe You 24 years old!?"; //test case 3
    lower(str3);

    char str4[] = "{Great to see you!}"; //test case 4
    lower(str4);

    return(0);
}

