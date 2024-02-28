#include <stdio.h>

//In C, when you declare a function that takes a multi-dimensional array as a parameter, 
//you need to include the size of the array in the declaration.
// This is because arrays lose their size information when passed to functions; 
//the size information is not automatically preserved.

void printboard(char board[3][3]);  // function declarations
void makemove(char board[3][3], int currentplayer);
int checkwinner(char board[3][3]);
int istie(char board[3][3]);

void main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int currentplayer = 1;
    int winner;

    do {
        printboard(board);          // function call to print board
        makemove(board, currentplayer); // function call to make player take a move

        winner = checkwinner(board);
        if (winner == 1) {
            printboard(board);
            printf("PLAYER 1 (X) IS THE ***WINNER***!!");
        } else if (winner == 2) {
            printboard(board);
            printf("PLAYER 2 (O) IS THE ***WINNER***!!");
        }

        // switch players:
        currentplayer = (currentplayer == 1) ? 2 : 1;

    } while (istie(board) == 0 && winner == 0); // until the board is not full, and until there is no winner
		
		if(istie(board) == 1 && winner == 0){			//board is full and  no winner
			printboard(board);
    		printf("\n*****There Is a tie*****\n");
		}
		
	  printf("\n****Game over****\n");					

   
}

// printing board to show every current situation
void printboard(char board[3][3]) {
    int i, j;

    printf("\n    1   2   3\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]); // to print X or O at [i][j] position with separators
        }
        printf("|\n");
        if (i < 2) {
            printf("  -------------\n"); // Separator between rows
        }
    }
    printf("\n");
}


// function -> allowing player to make a move
void makemove(char board[3][3], int currentplayer) {
    int row, col;

    printf("\nPlayer %d, Enter row [1,2,3]: ", currentplayer);
    scanf("%d", &row);
    printf("Player %d, Enter column [1,2,3]: ", currentplayer);
    scanf("%d", &col);

    if (board[row - 1][col - 1] == ' ') {			//indexing starts from 0 usually
        if (currentplayer == 1)
            board[row - 1][col - 1] = 'X'; // player 1 has X
        else
            board[row - 1][col - 1] = 'O'; // player 2 has O
    } else { // board[row][col]!=' ' (cell is taken already)
        printf("\nCell already filled, Try again..\n");
        makemove(board, currentplayer); // calling the function itself again to make the player take a move (recursion)
    }
}

// function to check who's the winner
int checkwinner(char board[3][3]) {
    int i, j;
    // for horizontal wins, check for rows:
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            if (board[i][0] == 'X') {
                return 1; // player 1 is the winner
            } else {
                return 2; // player 2 is the winner
            }
        }
    }

    // for vertical wins, check for columns:
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            if (board[0][j] == 'X') {
                return 1; // player 1 is the winner
            } else {
                return 2; // player 2 is the winner
            }
        }
    }

    // for cross wins, check diagonals:
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        if (board[0][0] == 'X') {
            return 1; // player 1 is the winner
        } else {
            return 2; // player 2 is the winner
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        if (board[0][2] == 'X') {
            return 1; // player 1 is the winner
        } else {
            return 2; // player 2 is the winner
        }
    }

    return 0; 	// every time until there is no final decision whos winner it will return 0( no winner) to main
}

// function to check if it's a tie or not (optional)
int istie(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // board is not full
            }
        }
    }
    return 1; // board is full
}