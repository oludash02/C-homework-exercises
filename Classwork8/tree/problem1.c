/*
 *This is an implementation of the Linux utility 'tree' 
 *It prints out the subdirectory structure of a specified directory
 *on the command line.
 * Default is set to pwd if no directory is specified
*/

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

static int no_direct = 0; //number of directories
static int no_files = 0; //number of files

void listdir_tree(char *path, int start_indent)
{
	DIR *dir;
    struct dirent *getDir;
    struct stat statbuf;
	int indent = start_indent*4; //this increases indentation as number of subdirectories increase
	
    if((dir = opendir(path)) == NULL) {

        printf("could not find the directory\n");
    }

	else
	{
    	chdir(path); //change current wording dir

    	while((getDir = readdir(dir)) != NULL) 
		{
        
			lstat(getDir->d_name,&statbuf); //get symbolic link status
	
			if(S_ISDIR(statbuf.st_mode)==0) //this runs the block if it is a file
			{
				if(getDir->d_name[0] == '.')
					continue;

				no_files++;
				printf("%*s%s\n",indent,"",getDir->d_name); //print each file with indentation of 4
			}
        
        	else //this runs the block if it is a direcotory
			{            
				if(getDir->d_name[0] == '.')
					continue;
            	//if(strcmp(".",getDir->d_name) == 0 || strcmp("..",getDir->d_name) == 0)
            	//    continue;
            	printf("%*s%s\n",indent,"",getDir->d_name);
     			no_direct++;       
            	listdir_tree(getDir->d_name,start_indent+1);
        	}
        
    	}

		chdir(".."); //go back to previous directory
    	closedir(dir);
	}

}


int main(int argc, char* argv[])
{

	char *filepath;

	if(argc != 2 || argv[1] == " ")
		filepath = ".";
	else
		filepath = argv[1];

	listdir_tree(filepath, 0);
/*	
	printf("\n");		
	if(no_direct <=1)
		printf("%d directory,  ", no_direct);
	else
		printf("%d directories,   ", no_direct);

	if(no_files <= 1)
		printf("%d file\n", no_files);
	else
		printf("%d files\n", no_files);
*/
	return 0;
}	






















































