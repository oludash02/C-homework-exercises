/* problem1.c - Activity log */
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	/*
 	This program logs activity to a file named activity.tsv
 	*/
    FILE *fp;
    fp = fopen("activity.tsv", "a"); //opens file for reading and appending
    int i = 0;
    time_t val = time(NULL); //initialize a pointer to the current time in seconds

    if((argc < 3) || (argc > 4)) //checks if there's a valid number of arguments
    {
        printf("*****usage*****\n");
		printf("Input format: ./log activity duration notes\n");
    }
    else
    {
		if((strcmp(argv[1], " ")==0) || strcmp(argv[2], " ")==0) //prints a usage message if duration or activity is not specified
		{
			printf("You must enter an activity and duration\n");
			printf("**usage**\n");
			printf("Input format: ./log activity duration notes\n");
		}
		else
		{
			if(argc == 4) //saves all logs if inputted completely
				fprintf(fp, "%lu\t%s\t%s\t%s\n", val, argv[1], argv[2], argv[3]);
			else //saves timestamp, activity and duration only
				fprintf(fp, "%lu\t%s\t%s\n", val, argv[1], argv[2]);
		}
    }

    fclose(fp);

    return 0;
}

