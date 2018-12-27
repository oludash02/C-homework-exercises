
#include "problem4.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //Test case 1
    const char* const strings[] = {"what","hello","to-do-list","Hi","me-too"};
    const char *value;
    int len;
    len = sizeof(strings)/sizeof(strings[0]);
    value = find_shortest(strings,len);
    printf("%s ", value);

    //Test case 2
    const char* const strings2[] = {"11","114","11212","3234","2222", "0"};
    len = sizeof(strings2)/sizeof(strings2[0]);
    value = find_shortest(strings2,len);
    printf("%s ", value);

    //Test case 3
    const char* const strings3[] = {"what up bro","hello it's victor","to-do-list","Hi hope you have a good day","i like cats"};
    len = sizeof(strings3)/sizeof(strings3[0]);
    value = find_shortest(strings3,len);
    printf("%s ", value);

  return(0);
}

