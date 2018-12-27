#include "problem1.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char check_win(char board[3][3])
{
    /*
    This function checks a tic-tac-toe board for a win condition
    */

    char winner;

    int i,j,k;
    int countXs=0, countOs=0; //To count number of X's and O's in the board
    bool okay = true, invalid_board = false, dont_run = false; //check if board is okay
    bool someone_won = false; //nobody has won yet

    //This if statement checks if board is invalid
    if(okay == true)
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if((board[i][j] != 'x') && (board[i][j] != 'o') && (board[i][j] != ' '))
                {
                    invalid_board = true;
                }
                if(board[i][j] == 'x')
                {
                    countXs++;
                }
                if(board[i][j] == 'o')
                {
                    countOs++;
                }
            }
        }
        if((invalid_board == true) || (abs(countXs - countOs) > 1))
        {
            winner = '0';
            dont_run = true;
        }
    }

    //this if statement checks if there's a win or lose, ongoing game or cat's game
    if(dont_run == false)
    {
        for(i=0; i<3; i++)
        {
            if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) // Test along columns
            {
                winner = board[i][0];
                someone_won = true;
                break;
            }
            if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) // Test along rows
            {
                winner = board[0][i];
                someone_won = true;
                break;
            }
            if(((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))) //Test along diagonals
            {
                if(((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) == true)
                {
                    winner = board[0][0];
                    someone_won = true;
                    break;
                }
                if(((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) == true)
                {
                    winner = board[0][2];
                    someone_won = true;
                    break;
                }

            }
        }
        //If there's no win, this checks if game is a cat's game or ongoing
        if(someone_won == false)
        {
            int count_empty=0;
            for(j=0; j<3; j++)
            {
                for(k=0; k<3; k++)
                {
                    if(board[j][k] == ' ')
                    {
                        count_empty++;
                    }
                }
            }

            if(count_empty >= 1)
            {
                winner = ' ';
            }
            else
            {
                winner = '.';
            }
        }
    }

    return winner;
}