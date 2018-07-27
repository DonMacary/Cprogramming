/*
Team DCR!
Donnie, Chris, & Ricky
27 July 2018
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 6 /////////////////////////////////////////////
////////////////////////////////////////////// MULTI-DIMENSIONAL ARRAYS /////////////////////////////////////////////
//////////////////////////////////////////////////// "Tic Tac Toe" //////////////////////////////////////////////////
////////////////////////////////////////////////////// Stub Code ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Replicate a tic tac toe grid using a two-dimensional char array of global scope (for ease of use)
// Define the following prototype functions in main(void) according to their specifications:
//     int printTheGrid(void);
//     int any_plays_left(void);
//     char did_someone_win(void);
//     int what_is_your_play(char currentPlayer, int gridLocation);
// Loop through those functions, in the order listed above and below, taking input until:
//     Someone wins *or*
//     There are no more selections (stalemate)
// Check for bad input (e.g., Selection 99) and reported errors (e.g., what_is_your_play() should return -1 on
//     an invalid selection)
// Direct reference to array elements (e.g., myArray[0][1]) is authorized.  In other words, pointer arithmetic
//     is not mandatory.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
/*
* FUNCTION:   int print_the_grid(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, 1
*             On failure, 0
*
* NOTES:      This function should first print out a tic tac toe legend:
*              1 | 2 | 3
*             -----------
*              4 | 5 | 6
*             -----------
*              7 | 8 | 9
*
*             Then, this function should print out the current state of the 2D char array in a similar format:
*                |   | X
*             -----------
*              X | O |
*             -----------
*                |   |
*/
int print_the_grid(char * ticTacToeGrid);


/*
* FUNCTION:   int any_plays_left(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the number of available choices
*             On failure, 0
*
* NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
*/
int any_plays_left(void);

/*
* FUNCTION:   char did_someone_win(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
*             On failure, 0
*
* NOTES:      There are 8 possible win conditions:
*                 Top row, middle row, bottom row
*                 Left column, middle column, right column
*                 Backslash, "Frontslash" (TM pending)
*/
char did_someone_win(void);

/*
* FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
*
* ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
*             int gridLocation should indicate the position on the grid to place "currentPlayer" as
*                 defined by whomever defined print_the_grid().
*
* RETURNS:	   On a successful choice, 1
*             If the user chooses a location that has already been taken, 0
*             On failure, -1
*
* NOTES:      Verify that gridLocation has not already been chosed before accepting the play
*             If the play is valid, record the selection within the 2D tic tac toe array
*/
int what_is_your_play(char currentPlayer);

/* TIC TAC TOE char array */
char ticTacToeGrid[3][3];
char ticTacToeLedgend[3][3] = { '1','2','3','4','5','6','7','8','9' };  //initialized second array for Legend Display

int main(void)
{
	int menuSelection = 0;
	int number = 0;
	//printf("Lets play a game...\n");
	_flushall();
	//scanf("%d", &number);
	
	do
	{
		char tempSelect[10] = { 0 };
		printMenu();
		
		fgets(tempSelect, sizeof(tempSelect), stdin);  //gets player's input

		menuSelection = atoi(tempSelect);

		_flushall();
		//scanf("%d", &menuSelection);
		switch (menuSelection)
		{
		case 1:
			puts("\nTime to play Tic Tac Toe!\n"); //prints greeting

			int playerNum = 0;
			while (any_plays_left() > 0)  //start while loop and continue running while moves are left
			{
				print_the_grid(&(ticTacToeLedgend[0][0]));  //prints legend
				print_the_grid(&(ticTacToeGrid[0][0]));  //prints current state of game
				printf("Remaining moves left:  %d\n\n", any_plays_left());  //displays remaining moves

				what_is_your_play((playerNum % 2) + 1);  //designates which player is making move by using odds as play 1 and evens as player 2
				if (did_someone_win() == '0')
				{
					playerNum++;  //itterates through playerNum to get odd/even number
				}
				else
				{
					break;  //if did_someone_win returns value other than 0, break the game because someone won
				}


			}
			print_the_grid(&(ticTacToeGrid[0][0]));  //prints the "final" game board after a win or draw
			if (did_someone_win() == 'X')  //looks to see if player 1 "X" won
			{
				printf("\t**********************\n\t*                    *\n\t*   Player 1 wins!   *\n\t*                    *\n\t**********************\n\n\n");
			}
			else if (did_someone_win() == 'O')  //looks to see if player 2 "O" won
			{
				printf("\t**********************\n\t*                    *\n\t*   Player 1 wins!   *\n\t*                    *\n\t**********************\n\n\n");
			}
			else  //executes if neither player wins
			{
				printf("No more moves, no one wins.\n");
			}
			break;


		//case 2:
			//printf("\n\nExiting...");
			//break;

		default:
			break;
		}
	} while (menuSelection != 2);

	//while (1);
	return 0;
}

/*
* FUNCTION:   int printTheGrid(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, 1
*             On failure, 0
*
* NOTES:      This function should first print out a tic tac toe legend:
*              1 | 2 | 3
*             -----------
*              4 | 5 | 6
*             -----------
*              7 | 8 | 9
*
*             Then, this function should print out the current state of the 2D char array in a similar format:
*                |   | X
*             -----------
*              X | O |
*             -----------
*                |   |
*/
int print_the_grid(char * ticTacToeGrid)  //defines function of print_the_grid, used to print both Legend and Current Game
{
	for (int i = 0; i < 9; i++)
	{
		printf(" %c ", *(ticTacToeGrid + i));
		if (i == 8)
		{
			printf("\n\n\n\n");
			return 1;
		}
		else if (i % 3 == 2)
		{
			printf("\n");
			printf("-----------\n");
		}
		else
		{
			printf("|");
		}
	}

	return 0;
}

/*
* FUNCTION:   int any_plays_left(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the number of available choices
*             On failure, 0
*
* NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
*/
int any_plays_left(void)
{
	int moves = 0;
	char * ptr = &ticTacToeGrid[0][0];  //created temp pointer and assigned it to the memory location of ticTacToeGrid array

	for (int i = 0; i < 9; i++)
	{
		if (*(ptr + i) == '\0')  //checks through the array via the temporary * ptr to see if spots are left ( \0 means a spot is available)
		{
			moves++;  //counts moves left
		}
	}

	return moves;
}

/*
* FUNCTION:   char did_someone_win(void)
*
* ARGUMENTS:  NONE
*
* RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
*             On failure, 0
*
* NOTES:      There are 8 possible win conditions:
*                 Top row, middle row, bottom row
*                 Left column, middle column, right column
*                 Backslash, "Frontslash" (TM pending)
*/
char did_someone_win(void)
{
	char * ptr = &ticTacToeGrid[0][0];  //created temp pointer and assigned it to the memory location of ticTacToeGrid array


	if ((*(ptr + 0) == *(ptr + 1)) && (*(ptr + 1) == *(ptr + 2)) && (*(ptr + 0) != '\0')) //Top row win
	{
		return *(ptr + 0);
	}
	else if ((*(ptr + 3) == *(ptr + 4)) && (*(ptr + 4) == *(ptr + 5)) && (*(ptr + 3) != '\0'))  //Middle row win
	{
		return *(ptr + 3);
	}
	else if ((*(ptr + 6) == *(ptr + 7)) && (*(ptr + 7) == *(ptr + 8)) && (*(ptr + 6) != '\0'))  //Bottom row win
	{
		return *(ptr + 6);
	}
	else if ((*(ptr + 0) == *(ptr + 3)) && (*(ptr + 3) == *(ptr + 6)) && (*(ptr + 0) != '\0'))  //First column win
	{
		return *(ptr + 0);
	}
	else if ((*(ptr + 1) == *(ptr + 4)) && (*(ptr + 4) == *(ptr + 7)) && (*(ptr + 1) != '\0'))  //Second Column win
	{
		return *(ptr + 1);
	}
	else if ((*(ptr + 2) == *(ptr + 5)) && (*(ptr + 5) == *(ptr + 8)) && (*(ptr + 2) != '\0'))  //Third column win
	{
		return *(ptr + 2);
	}
	else if ((*(ptr + 0) == *(ptr + 4)) && (*(ptr + 4) == *(ptr + 8)) && (*(ptr + 0) != '\0'))  //Back slash win
	{
		return *(ptr + 0);
	}
	else if ((*(ptr + 6) == *(ptr + 4)) && (*(ptr + 4) == *(ptr + 2)) && (*(ptr + 6) != '\0'))  //Forward slash win
	{
		return *(ptr + 6);
	}
	else
	{
		return '0';  //Cat wins
	}
}

/*
* FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
*
* ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
*             int gridLocation should indicate the position on the grid to place "currentPlayer" as
*                 defined by whomever defined print_the_grid().
*
* RETURNS:	   On a successful choice, 1
*             If the user chooses a location that has already been taken, 0
*             On failure, -1
*
* NOTES:      Verify that gridLocation has not already been chosed before accepting the play
*             If the play is valid, record the selection within the 2D tic tac toe array
*/
int what_is_your_play(char currentPlayer)
{
	char * ptr = &ticTacToeGrid[0][0];  //created temp pointer and assigned it to the memory location of ticTacToeGrid array
	int goodInput = 0;
	char temp[10] = { 0 };

	while (goodInput == 0)
	{
		int playerInput = 0;

		printf("Player %d, what is your move?\n", currentPlayer);

		fgets(temp, sizeof(temp), stdin);  //gets player's input

		playerInput = atoi(temp);  //convert temp to an integer, and assigns to playerInput

		playerInput = playerInput - 1;  //realligns playerInput to ticTacToeGrid array

		if (playerInput < 0 || playerInput > 8)  //checks for input being within game peramaters
		{
			printf("Error: this is not a valid selection\n");
		}
		else if (*(ptr + playerInput))  //checks that choosen space is available or not
		{
			printf("Error:  this spot is occupied\n");
		}
		else //places the X or O into position by assigning the value(*) of (ptr + playerInput) to either X or O
		{
			goodInput = 1;
			if (currentPlayer == 1)
			{
				*(ptr + playerInput) = 'X';
			}
			if (currentPlayer == 2)
			{
				*(ptr + playerInput) = 'O';
			}
		}
	}
	return 1;
}

int printMenu(void)
{
	printf("Would you like to play a game of Tic-Tac-Toe?  \n");
	printf("1 - Play Tic-Tac-Toe \n2 - Exit this program\n - Enter a selection from the above menu options. \n\n");

	return 0;
}