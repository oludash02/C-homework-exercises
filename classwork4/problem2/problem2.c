
#include "problem2.h"
#include <stdio.h>
#include <time.h>

void print_time(time_t mytime)
{

        /*
        This function prints date and time in format below
        Weekday, Month Day, Year hours:minutes:seconds
        */
        int len = 256; //set up length of buffer
        char str_len[len];
        struct tm *date_time; //initialize a tm struct to get address of time

        date_time = gmtime(&mytime);

        strftime(str_len, len, "%A, %B %d, %Y %H:%M:%S\n", date_time); //strftime prints the time in specific format: check http://www.cplusplus.com/reference/ctime/strftime/
        printf("%s", str_len);

}

