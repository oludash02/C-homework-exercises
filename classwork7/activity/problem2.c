/* problem2.c - Activity summary */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("activity.tsv", "r");
    char str[200]; //stores each line in the file
    char *t; //stores the " " separated words in each line in activity.tsv
    int i=0,j=0,k;
    long int seconds; //extracts the number of seconds from activity
    char *duration; //time spent exercising for each activity
    char *in; 
    time_t tym = time(NULL); //get current time
    int total_time = 0; //initialize total time for exercise
    long int convert_to_sec[4] = {86400, 604800, 31536000}, val; //stores no of seconds in a 'd' 'w' 'y'
    char digit[10]; //extracts the integer part of the duration
    bool stop = false, invalid = false;


    if(argc == 1 || !strcmp(argv[1], " ") || argc > 2) //checks if summary duration is not specified
    {
        printf("Invalid number of arguments\n");
        printf("***usage***\n");
        printf("./summarize 1w  (use integer plus either 'd' for days, 'w' for weeks and 'y' for years)\n");
    }
    else if(!fp || ferror(fp) || fp==NULL) //checks if file does not exist or is corrupted
    {
        printf("error: activity file doesn't exist or is corrupted\n");
    }
    else
    {
        in = argv[1]; //extract summary duration
        strncpy(digit,in,strlen(in)-1); //copies the integer part of duration

        for(k=0; k<strlen(digit); k++)
        {
            if(!isdigit(digit[k])) //check if the integer part contains no characters
            {
                printf("first argument for duration must be an integer\n");
                invalid = true;
            }
        }

        if(invalid == false)
        {

            while((fgets(str, 200, fp) != NULL) && stop == false) //get each line in file
            {
                t = strtok(str, " "); //strtok separates lines by " "

                while(t != NULL)
                {
		    if(strlen(t) != 1) //don't count white spaces or tabs
		    {
                    	i++;

                    	if(i == 1)
                    	{
                        	seconds = atoi(t); //extract timestamp
                    	}
                    	if(j == 2)
                    	{
                        	duration = t; //extract time of activity
                    	}
			j++;
		    }
                    t = strtok(NULL, " ");
                    
                }

                if((atoi(digit) >= 1))
                {
		//sum of total time spent exercising
                    switch(in[strlen(in)-1])
                    {
                        case 'd':
                            val = tym - convert_to_sec[0];
                            if(seconds >= val && seconds <= tym)
                            {
                                total_time = total_time + atoi(duration);
                            }
                            break;
                        case 'w':
                            val = tym - convert_to_sec[1];
                            if(seconds >= val && seconds <= tym)
                            {
                                total_time = total_time + atoi(duration);
                            }
                            break;
                        case 'y':
                            val = tym - convert_to_sec[2];
                            if(seconds >= val && seconds <= tym)
                            {
                                total_time = total_time + atoi(duration);
                            }
                            break;
                        default:
                            printf("Should be d, w or y\n");
                            stop = true;
                            break;
                    }
                }
                else
                    printf("invalid integer used\n");

                i = 0;
                j = 0;
            }

            printf("Total exercise: %d minutes\n", total_time);
        }
	    
	 fclose(fp);

    }
	
    return 0;
}



