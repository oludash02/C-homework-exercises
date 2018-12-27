
#include "problem1.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    char board[3][3];
    char win;

    //Test case if X or O won placed horizontally
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';
    board[1][0] = ' ';
    board[1][1] = 'O';
    board[1][2] = ' ';
    board[2][0] = 'O';
    board[2][1] = 'O';
    board[2][2] = 'X';
    win = check_win(board);
    printf("%c\n", win);

    //Test case if X or O won placed vertically
    board[0][0] = 'O';
    board[0][1] = 'X';
    board[0][2] = 'O';
    board[1][0] = 'X';
    board[1][1] = 'X';
    board[1][2] = 'O';
    board[2][0] = 'X';
    board[2][1] = 'O';
    board[2][2] = 'O';
    win = check_win(board);
    printf("%c\n", win);

    //Test case if X or O won diagonally
    board[0][0] = 'X';
    board[0][1] = 'O';
    board[0][2] = 'X';
    board[1][0] = 'O';
    board[1][1] = 'X';
    board[1][2] = 'O';
    board[2][0] = 'X';
    board[2][1] = ' ';
    board[2][2] = 'O';
    win = check_win(board);
    printf("%c\n", win);

    //Test case for disproportionate number of X's or O's
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'O';
    board[1][0] = 'O';
    board[1][1] = 'X';
    board[1][2] = 'X';
    board[2][0] = 'X';
    board[2][1] = 'O';
    board[2][2] = 'X';
    win = check_win(board);
    printf("%c\n", win);

    //Test case with invalid characters
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'O';
    board[1][0] = 'O';
    board[1][1] = ' ';
    board[1][2] = 'X';
    board[2][0] = 'B';
    board[2][1] = 'O';
    board[2][2] = 'X';
    win = check_win(board);
    printf("%c\n", win);

    //Test case when the game is still going
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'O';
    board[1][0] = 'O';
    board[1][1] = 'X';
    board[1][2] = 'X';
    board[2][0] = ' ';
    board[2][1] = 'O';
    board[2][2] = 'O';
    win = check_win(board);
    printf("%c\n", win);

    //Test case when the board is filled
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'O';
    board[1][0] = 'O';
    board[1][1] = 'X';
    board[1][2] = 'X';
    board[2][0] = 'X';
    board[2][1] = 'O';
    board[2][2] = 'O';
    win = check_win(board);
    printf("%c\n", win);

    //Test case when the board is mostly empty
    board[0][0] = 'X';
    board[0][1] = 'O';
    board[0][2] = ' ';
    board[1][0] = ' ';
    board[1][1] = ' ';
    board[1][2] = ' ';
    board[2][0] = ' ';
    board[2][1] = ' ';
    board[2][2] = ' ';
    win = check_win(board);
    printf("%c\n", win);

    return 0;
}

