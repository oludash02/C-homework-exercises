#include "problem3.h"
#include <stdio.h>

int* find_sequence(int* seq, int n)
{
	int *result; //pointer to beginning of longest sequence

	int i; //initialize counter
	int initial_len = 0; //initialize length
	int sequence_len = 0; //initialize length of longest sequence

	int begin = 0; //variable to store beginning of sequence
	if(n<=0 || seq == NULL )
	{
		printf("n cannot be <= 0 \n");
		result = NULL;
	}
	else
	{
		for(i=0; i<n; i++)
		{
			//checks if the next value in the array is less than current value
            if((i+1) < n)
            {
                if(seq[i+1] > seq[i])
                {
                    ++sequence_len;

                    if(sequence_len > initial_len)
                    {
                        initial_len = sequence_len; //reset initial length of sequence
                        begin = i - sequence_len+1; //store beginning of sequence
                    }
                }
                else
                {
                    sequence_len = 0;
                }
            }

		}

		//begin = begin + 1; //set the next integer as actual beginning of sequence
		//initial_len = initial_len - 1; //calculate actual length of sequence

		if(initial_len == 0)
		{
			result = NULL;
		}
		else
		{
			result = (seq + begin);
		}
		/*
		//Uncomment this to check lengths and index
		printf("Index of begin sequence: %i\n", begin);
		printf("seq length: %i\n", sequence_len);
		printf("initial length: %i\n", initial_len);

        */
	}
	return result;

}

