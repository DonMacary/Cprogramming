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
int print_the_grid(void);

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
int what_is_your_play(char currentPlayer, int gridLocation);

/* TIC TAC TOE char array */
char ticTacToeGrid[3][3];

int main(void)
{
	puts("Good luck to you."); // Remove this

	/* PRINT THE LEGEND AND CURRENT STATUS OF THE GAME */
	print_the_grid();

	/* DETERMINE IF THERE ARE NO MORE MOVES LEFT */
	any_plays_left();

	/* DID SOMEONE WIN?  INFORM THE PLAYERS AND END THE GAME */
	did_someone_win();

	/* OTHERWISE, ALLOW THE NEXT PLAYER TO MAKE A MOVE */
	what_is_your_play('U', 0);

	// NOTE:  Don't forget error checking and input validation along the way.

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
int print_the_grid(void)
{
	puts("No grid was printed."); // Remove this

	return 0x90C05; // You'll need to change this
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
	puts("The 2D array was not evaluated."); // Remove this

	return 0x90C05; // You'll need to change this
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
	puts("Nobody knows who won."); // Remove this

	return 0x90C05; // You'll need to change this
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
int what_is_your_play(char currentPlayer, int gridLocation)
{
	puts("No play was made."); // Remove this

	return 0x90C05; // You'll need to change this}
}
