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
		getchar();
		scanf("%c", &userInputCompassDirection);
		userInputCompassDirection = toupper(userInputCompassDirection);
		

		
		didThatShipFit = place_a_ship((arrayOfShips + i)->shipNumber, &(myBattleshipGrid[userInputRow - 65][userInputCol - 1]), userInputCompassDirection);
		didTheGridPrint = print_both_grids();
	}


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
	int returnValuePAS = -1;


	return returnValuePAS;
}
