#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 *This problem works similar to the linux utility wc
 *it counts words, newlines, and bytes in a file.
 * -l print the number of newlines
 *  -w print the number of words
 *  -c print the number of bytes
 *  Format: ./wordcount file -l -c -w
*/

int main(int argc, char *argv[])
{
    FILE *fp;
	FILE *temp_file; //stores file inputted via stdin
    int i;
    char *str_name; //stores file name
    char *argts; //initialize argument
	char stdin_name[50];
	bool file_entered = false, find_arg = false; //this helps check what should be printed out
    bool if_word=false,if_line=false,if_char=false;
    char *filename;
	
    if(argc > 5) //checks if number of input arguments are valid
    {
        printf("Invalid number of input commands\n");
        printf("***usage***\n");
        printf("./wordcount filename -l -w -c\n");
    }
    else
    {
        for(i=0; i<argc; i++)
        {
            str_name = argv[i];
            if(*str_name != '-' && *str_name != '.') //condition to find the input file in command line
            {
                fp = fopen(str_name, "r");
				file_entered = true;
            }
        }

		if(file_entered == false)
		{
			printf("Enter a valid string: ");
			//fscanf(stdin,"%[^\n]%*c", &stdin_name);
			fgets(stdin_name, 5000, stdin); //get words from stdin
			temp_file = fopen("temp_file.tsv", "w");//create temporary file for writing
			fprintf(temp_file, stdin_name);
			fclose(temp_file);

			fp = fopen("temp_file.tsv", "r"); //open temporary file
			file_entered = true;
		}


        char str[1000]; //initialize each line to read from the file
        char delim[] = " ";
        int new_line=0, word_cnt=0, no_bytes=0;
        char *t; //initialize " " separated words

        if(!fp)
        {
            printf("Input file could not be found\n");
        }
        else
        {
            while(fgets(str, 1000, fp) != NULL) //reads all sentence in each line
            {
                no_bytes = no_bytes + strlen(str); //sum number of bytes based on length of sentence

                if((str[strlen(str) - 1] == '\n'))
                {
                    new_line++; //increment lines if last character is \n
                }
                if(strlen(str) == 1); //skip strtok if next line is empty

                else
                {
                    t = strtok(str, delim); //separate all sentences in each line by " "
                }

                while((t != NULL))
                {
					//This ensures that a " " is not registered as a word count
                    if(strlen(t) == 1)
                    {
                        if(t[0] == '\n')
                            word_cnt--;
                    }
                    word_cnt++;
                    t = strtok(NULL, delim);
                }
            }

            if(argc == 1) //prints newline, word count, number of bytes and filename if not specified
            {
                printf("%d %d %d \n", new_line, word_cnt, no_bytes);
            }
			if(argc >= 2)
			{
				argts = argv[1];
				if(argts[0] != '-' && argc == 2)
					printf("%d %d %d %s\n", new_line, word_cnt, no_bytes, argts);
				else
					find_arg = true; //find argument if not filename
			}
            if(find_arg == true)
            {

                for(i=1; i<argc; i++)
                {
                    argts = argv[i];
			
		    if(argts[0] != '-' && argts[0] != '.')
                        filename = argts;
                    if(strcmp(argts,"-l") == 0)
                    {
                        if_line = true;
                        //printf("%d %s\n", new_line, argv[1]);
                    }
                    else if(strcmp(argts,"-w") == 0)
                    {
                        if_word = true;
                        //printf("%d %s\n", word_cnt, argts, argv[1]);
                    }
                    else if(strcmp(argts,"-c") == 0)
                    {
                        if_char = true;
                        //printf("%d %s\n", no_bytes, argv[1]);
                    }
                    else
                    {
                        if(*argts == '-')
                            printf("Invalid command: usage -l -w -c\n");
                        else
                            printf("\n");
                    }
                }
                if(if_line == true)
                    printf("%d ", new_line);
                if(if_word == true)
                    printf("%d ", word_cnt);
                if(if_char == true)
                    printf("%d ", no_bytes);
                if(if_word || if_line || if_char)
                    printf("%s\n ", filename);
            }


		fclose(fp);

		}

    }

    return 0;
}


