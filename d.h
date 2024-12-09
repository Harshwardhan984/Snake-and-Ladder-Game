#ifndef A_H
#define A_H

#include <stdbool.h>  // Include for using bool type

// Maximum number of players allowed in the game
#define MAX_PLAYERS 10

// Structure representing a square/node on the game board
typedef struct node {
    int data;                                // Square number
    char playerSymbols[MAX_PLAYERS + 1];    // Symbols of players on this square
    struct node* rlink;                     // Pointer to the next square
    struct node* llink;                     // Pointer to the previous square
} NODE;

// Structure representing a player
typedef struct player {
    int id;          // Unique identifier for the player
    NODE* position;  // Current position of the player on the board
} PLAYER;

// Global variables
extern bool gameOver;              // Tracks if the game has ended
extern PLAYER* winner;             // Pointer to the winning player
extern NODE* squares[100];         // Array of pointers to all the board squares

// Function to create a new square/node on the board
NODE* createNode(int data);

// Function to initialize and create the game board
NODE* createTable(NODE* head);

// Function to place a player at the start of the game
NODE* createPlayer(NODE* head);

// Function to display the game board and player positions
void displayBoard(NODE* head, int no_of_players);

// Function to roll a virtual die (generates random number between 1 and 6)
int randomDie();

// Function to get the die roll from the player (for physical dice)
int rollPhysicalDie();

// Function to move a player forward based on dice roll
void movePlayer(PLAYER* player, int steps);

// Function to check if the player landed on a snake or ladder and adjust position
void checkSnakeOrLadder(PLAYER* player);

// Additional Features for Extension
void resetGame(NODE* head, PLAYER* players[], int no_of_players);
/*
 * Function to reset the game to its initial state.
 * - Resets player positions to the start
 * - Clears player symbols from the board
 */

// Function to display the game rules
void displayRules();
/*
 * Function to print the rules of the game to the console.
 * - Explains the snake and ladder mechanics
 * - Explains the dice roll rules and turn-taking
 */

// Function to save the game state
void saveGame(const char* filename, NODE* head, PLAYER players[], int no_of_players);
/*
 * Saves the current game state to a file.
 * - Useful for resuming a game later
 * - Includes player positions and turn data
 */

// Function to load a saved game state
void loadGame(const char* filename, NODE* head, PLAYER players[], int* no_of_players);
/*
 * Loads a saved game state from a file.
 * - Restores player positions and the game board
 * - Updates the number of players
 */

// Function to display player stats
void displayPlayerStats(const PLAYER players[], int no_of_players);
/*
 * Displays detailed statistics for each player.
 * - Player ID, current position, and more
 */

#endif // A_H
