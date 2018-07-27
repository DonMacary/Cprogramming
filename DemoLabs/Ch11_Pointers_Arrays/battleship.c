/*********************************************************************
/   AUTHOR: ELF, Ricky, Yost
/   COURSE: C Programming
/   PROGRAM NAME: battleship.c
/   PROGRAM DESCRIPTION: Battleship Part 1 - setupBoard
/   INSTRUCTIONS:
		Initialize a 2D array.

/*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef TRUE
#define TRUE ((int)1)
#endif

#ifndef FALSE
#define FALSE ((int)0)
#endif

#define GRID_ROWS (10)
#define GRID_COLUMNS (10)
#define GRID_EMPTY_SPACE (0x20)			// Space
#define GRID_HIT (0x2A)					// Asterik
#define SHIP_AIRCRAFT_CARRIER (0x41)	// A
#define SHIP_BATTLESHIP (0x42)			// B
#define SHIP_SUBMARINE (0x53)			// S
#define SHIP_CRUISER (0x43)				// C
#define SHIP_DESTROYER (0x44)			// D

struct Battleship
{
	char name[17];
	int length;
	int shipNumber;
	char code;
};


int print_both_grids(void);
int place_a_ship(int shipNumber, char * gridStartingPointer, int compassDirection);

char myBattleshipGrid[GRID_ROWS][GRID_COLUMNS] = { 0 };
char theirBattleshipGrid[GRID_ROWS][GRID_COLUMNS] = { 0 };
const int shipAircraftCarrierLength = 5;
const int shipBattleshipLength = 4;
const int shipSubmarineLength = 3;
const int shipCruiserLength = 3;
const int shipDestroyerLength = 2;
const int shipNumberAC = 1;
const int shipNumberB = 2;
const int shipNumberS = 3;
const int shipNumberC = 4;
const int shipNumberD = 5;

int main(void)
{
	int i = 0;
	char * placeTheShipHere = NULL;
	char userInputRow = 0;
	int userInputCol = 0;
	char userInputCompassDirection = 0;

	/* Initialized Ships */
	struct Battleship aircraftCarrier;
	struct Battleship battleship;
	struct Battleship submarine;
	struct Battleship cruiser;
	struct Battleship destroyer;

	/****************/
	/* Define Ships */
	/****************/

	/* Aircraft Carrier */
	strncpy(aircraftCarrier.name, "Aircraft Carrier", 17);
	aircraftCarrier.length = shipAircraftCarrierLength;
	aircraftCarrier.shipNumber = shipNumberAC;
	aircraftCarrier.code = SHIP_AIRCRAFT_CARRIER;

	/* Battleship */
	strncpy(battleship.name, "Battleship", 17);
	battleship.length = shipBattleshipLength;
	battleship.shipNumber = shipNumberB;
	battleship.code = SHIP_BATTLESHIP;

	/* Submarine */
	strncpy(submarine.name, "Submarine", 17);
	submarine.length = shipSubmarineLength;
	submarine.shipNumber = shipNumberS;
	submarine.code = SHIP_SUBMARINE;

	/* Cruiser */
	strncpy(cruiser.name, "Cruiser", 17);
	cruiser.length = shipCruiserLength;
	cruiser.shipNumber = shipNumberC;
	cruiser.code = SHIP_CRUISER;

	/* Destroyer */
	strncpy(destroyer.name, "Destroyer", 17);
	destroyer.length = shipDestroyerLength;
	destroyer.shipNumber = shipNumberD;
	destroyer.code = SHIP_DESTROYER;

	/* Array of Battleship Structs */
	struct Battleship arrayOfShips[] = { aircraftCarrier, battleship, submarine, cruiser, destroyer };

	/* Return Values */
	int didTheGridPrint = 0;
	int didThatShipFit = 0;


	/* PRINT THE GRID */
	didTheGridPrint = print_both_grids();

	/* INITIALIZE YOUR GRID */
	for (i = 0; i < 5; i++)
	{
		printf("Placing %s \nWhat grid position?  (e.g. B4)\n", (arrayOfShips + i)->name);
		_flushall();
		scanf("%c%d", &userInputRow, &userInputCol);
		getchar();
		userInputRow = toupper(userInputRow);
		printf("What compass direction? (e.g., N, S, E, W)\n");
		_flushall();
		scanf("%c", &userInputCompassDirection);
		getchar();

		userInputCompassDirection = toupper(userInputCompassDirection);

		//printf("Ship Pointer %p", &((arrayOfShips + i)->shipNumber));
		didThatShipFit = place_a_ship((arrayOfShips + i)->shipNumber, &(myBattleshipGrid[userInputRow - 65][userInputCol - 1]), userInputCompassDirection);
		//if theship fits print the grid
		if (didThatShipFit == 1)
		{
			didTheGridPrint = print_both_grids();
		}
		//if it doesnt print an error and then try again
		else
		{
			printf("The ship does not fit there, try again!\n");
			//since the original author insisted on a while loop here I am just decrementing i expecting it to go back to what it was when it gets to the top of the for loop
			i--;
		}
	}

	while (1);
	return 0;
}

int print_both_grids(void)
{
	int returnValuePBG = -1;
	int rowPBG = 0;
	int colPBG = 0;

	/* PRINT ENEMY GRID */
	/* PRINT COLUMN HEADERS */
	printf("  ");
	for (colPBG = 0; colPBG < GRID_COLUMNS; colPBG++)
	{
		printf("%d ", colPBG + 1);
	}
	printf("\n");

	for (rowPBG = 0; rowPBG < GRID_ROWS; rowPBG++)
	{
		printf("%c ", rowPBG + 0x41); // PRINT ROW HEADER
		for (colPBG = 0; colPBG < GRID_COLUMNS; colPBG++)
		{
			printf("%c ", *(*(theirBattleshipGrid + rowPBG) + colPBG));
		}
		printf("\n");
	}
	printf("\n");

	/* PRINT MY GRID */
	/* PRINT COLUMN HEADERS */
	printf("  ");
	for (colPBG = 0; colPBG < GRID_COLUMNS; colPBG++)
	{
		printf("%d ", colPBG + 1);
	}
	printf("\n");

	for (rowPBG = 0; rowPBG < GRID_ROWS; rowPBG++)
	{
		printf("%c ", rowPBG + 0x41); // PRINT ROW HEADER
		for (colPBG = 0; colPBG < GRID_COLUMNS; colPBG++)
		{
			printf("%c ", *(*(myBattleshipGrid + rowPBG) + colPBG));
		}
		printf("\n");
	}

	returnValuePBG = 0;

	return returnValuePBG;
}

int place_a_ship(int shipNumber, char * gridStartingPointer, int compassDirection)
{
	//just to make this work with just my grid i hard coded some things - specifically to check if i was out of bounds I used the global variable char myBattleshipGrid[GRID_ROWS][GRID_COLUMNS]
	//to tell me exactly where in memory the grid starts - i then subtract that with the gridstartingpointer to tell me where in the grid i actually am. this helps me do out of bounds checking
	int myPosition; //this variable tells me what position I am in on the double array (IE 0-9 is row 1, 10-19 is row 2 ETC)
	myPosition = gridStartingPointer - &(myBattleshipGrid[0][0]);

	char code;
	int length;
	int returnValuePAS = 1;
	switch (shipNumber)
	{
	case 1:
		code = SHIP_AIRCRAFT_CARRIER;
		length = shipAircraftCarrierLength;
		break;
	case 2:
		code = SHIP_BATTLESHIP;
		length = shipBattleshipLength;
		break;
	case 3:
		code = SHIP_SUBMARINE;
		length = shipSubmarineLength;
		break;
	case 4:
		code = SHIP_CRUISER;
		length = shipCruiserLength;
		break;
	case 5:
		code = SHIP_DESTROYER;
		length = shipDestroyerLength;
		break;
	default:
		return returnValuePAS;
	}
	//the switch case handles each compass direction since the math for each is a little different.
	//the function will check two different things: 1.) Are all the spaces empty? 2.)Are all the spaces writeable (IE in the same row/collumn/in the array)
	//if both of those statements are true then it then place the ship number in each spot on the grid and then return a 1 for success.
	switch (compassDirection)
	{
	case 'N':
		//checks if im staying within the array (not printing off the board)
		if ((myPosition - ((length - 1) * 10)) < 0)
		{
			returnValuePAS = -1;
			return returnValuePAS;
		}
		//This loop checks to see if all the spots are empty
		for (int i = 0; i< length; i++)
		{
			if (*(gridStartingPointer - (i * 10)) != '\0')
			{
				returnValuePAS = -1;
				return returnValuePAS;
			}

		}
		//the second loop will actually place the ship in the spots
		for (int i = 0; i < length; i++)
		{
			*(gridStartingPointer - (i * 10)) = code;
		}
		break;
	case 'S':
		//checks if im printing on the array AKA not going off the board
		if ((myPosition + ((length - 1) * 10)) > 99)
		{
			returnValuePAS = -1;
			return returnValuePAS;
		}
		//This loop checks to see if all the spots are empty
		for (int i = 0; i< length; i++)
		{
			if (*(gridStartingPointer + (i * 10)) != '\0')
			{
				returnValuePAS = -1;
				return returnValuePAS;
			}

		}
		//the second loop will actually place the ship in the spots
		for (int i = 0; i < length; i++)
		{
			*(gridStartingPointer + (i * 10)) = code;
		}
		break;
	case 'E':
		//checks if im staying in the same row - if not then return error
		if ((int)((myPosition + length - 1) / 10) >(int) (myPosition / 10))
		{
			returnValuePAS = -1;
			return returnValuePAS;
		}
		//first for loop will check if the ship can be placed on the grid: IE is there space and are all the spots empty
		for (int i = 0; i< length; i++)
		{
			//this checks if there is something at the current spot
			if (*(gridStartingPointer + i) != '\0')
			{
				returnValuePAS = -1;
				return returnValuePAS;
			}

		}
		//the second loop will actually place the ship in the spots
		for (int i = 0; i < length; i++)
		{
			*(gridStartingPointer + i) = code;
		}
		break;
	case 'W':
		//this checks if its in the first row because (int) -1/10 is the same as 1/10 so the following check doesnt work 
		if ((myPosition + 1) - length < 0)
		{
			returnValuePAS = -1;
			return returnValuePAS;
		}
		//checks if i am going into the previous row - if so return error
		if (((int)(myPosition + 1 - length) / 10) < (int)(myPosition / 10))
		{
			returnValuePAS = -1;
			return returnValuePAS;
		}

		//This loop checks to see if all the spots are empty
		for (int i = 0; i< length; i++)
		{
			if (*(gridStartingPointer - i) != '\0')
			{
				returnValuePAS = -1;
				return returnValuePAS;
			}
		}
		//the second loop will actually place the ship in the spots
		for (int i = 0; i < length; i++)
		{
			*(gridStartingPointer - i) = code;
		}
		break;
	}
	return returnValuePAS;
}

//reason i wont be making a check position function is because I wont be able to control which players grid I would be checking at this point so Im just not gonna go down that
//rabbit hole