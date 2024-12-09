#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "d.h"  // Include the header file containing definitions and prototypes

// Global variables
bool gameOver = false;  // Tracks if the game is over
PLAYER* winner = NULL;  // Pointer to the winning player
NODE* squares[100];     // Array to store the board squares for quick access

// Function to create a new node for the game board
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));  // Allocate memory for the new node
    if (!newNode) {  // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize the node properties
    newNode->data = data;
    memset(newNode->playerSymbols, ' ', MAX_PLAYERS);  // Initialize player symbols as empty
    newNode->playerSymbols[MAX_PLAYERS] = '\0';       // Null-terminate the player symbols string
    newNode->rlink = NULL;  // No right link yet
    newNode->llink = NULL;  // No left link yet
    return newNode;
}

// Function to create the game board as a doubly linked list
NODE* createTable(NODE* head) {
    int i;
    NODE* p = head;

    // Create 100 nodes for the game board
    for (i = 100; i > 0; i--) {
        NODE* temp = createNode(i);  // Create a node for each square
        p->rlink = temp;             // Link the current node to the next
        temp->llink = p;             // Link the next node back to the current
        p = p->rlink;                // Move to the next node
        squares[i - 1] = p;          // Store the node in the squares array
    }

    return head;
}

// Function to place a player at the start of the board
NODE* createPlayer(NODE* head) {
    // Move to the end of the list to find the first square
    while (head->rlink != NULL) {
        head = head->rlink;
    }
    return head;  // Return the starting position
}

// Function to display the game board along with player positions
void displayBoard(NODE* head, int no_of_players) {
    printf("\t\t********** SNAKE AND LADDER GAME **********\n\n");
    printf("\tSnakes: 46 -> 9, 77 -> 23, 99 -> 1\n");
    printf("\tLadders: 14 -> 36, 43 -> 81, 71 -> 98\n\n");

    NODE* p = head->rlink;  // Skip the head node
    for (int i = 0; i < 10; i++) {  // Loop through rows
        for (int j = 0; j < 10; j++) {  // Loop through columns
            printf("[%-2d)%s]", p->data, p->playerSymbols);  // Display the square number and players
            p = p->rlink;  // Move to the next square
        }
        printf("\n\n");
    }
}

// Function to generate a random die roll (1-6)
int randomDie() {
    int rem;
    do {
        rem = rand() % 7;  // Generate a number between 0 and 6
    } while (rem == 0);    // Repeat if the number is 0
    return rem;
}

// Function to get a die roll value from the player
int rollPhysicalDie() {
    int userInput;

    // Prompt the player to enter a number
    printf("Enter the number rolled on the physical die (1-6): ");
    scanf("%d", &userInput);

    // Validate the input
    if (userInput < 1 || userInput > 6) {
        printf("Invalid input. Please enter a number between 1 and 6.\n");
        return rollPhysicalDie();  // Recursive call for valid input
    }

    return userInput;
}




// Function to move a player on the board
void movePlayer(PLAYER* player, int steps) {
    NODE* currentSquare = player->position;  // Get the player's current position
	
	int curposition = currentSquare->data;
	if(curposition >= 95){
		if(curposition + steps > 100){
			printf("too close for winning \n");
			return;
		}
	}
	
    // Clear the player's symbol from the current square
    currentSquare->playerSymbols[player->id - 1] = ' ';

    // Move the player forward by the given number of steps
    for (int i = 0; i < steps; i++) {
        if (currentSquare->llink != NULL) {  // Check if there is a next square
            currentSquare = currentSquare->llink;  // Move to the next square
        } else {
            break;  // Stop if at the end of the board
        }
    }

    // Update the player's position and set their symbol on the new square
    player->position = currentSquare;
    currentSquare->playerSymbols[player->id - 1] = '@' + player->id;

    // Check if the player has reached the final square
    if (player->position->data == 100) {
        gameOver = true;  // Set game over flag
        winner = player;  // Set the winner
    }
}

// Function to check and handle snakes or ladders
void checkSnakeOrLadder(PLAYER* player) {
    NODE* currentSquare = player->position;
    int currentSquareNumber = player->position->data;

    // Check for specific snake or ladder positions
    switch (currentSquareNumber) {
        case 46:{ player->position = squares[8]; 
        	player->position->playerSymbols[player->id - 1] = '@' + player->id;
        	currentSquare->playerSymbols[player->id - 1] = ' ';
        break;
        }   // Snake: 46 -> 9
        case 77:{ player->position = squares[22]; 
        	player->position->playerSymbols[player->id - 1] = '@' + player->id;
        	currentSquare->playerSymbols[player->id - 1] = ' ';
        break;
        }  // Snake: 77 -> 23
        case 99:{ player->position = squares[0]; 
        	player->position->playerSymbols[player->id - 1] = '@' + player->id;
        	currentSquare->playerSymbols[player->id - 1] = ' ';
        break; 
        }  // Snake: 99 -> 1
        case 14: {player->position = squares[35]; 
        	player->position->playerSymbols[player->id - 1] = '@' + player->id;
        	currentSquare->playerSymbols[player->id - 1] = ' ';
        break;
        }  // Ladder: 14 -> 36
        case 43:{ player->position = squares[80]; 
        	player->position->playerSymbols[player->id - 1] = '@' + player->id;
        	currentSquare->playerSymbols[player->id - 1] = ' ';
        break;
        }  // Ladder: 43 -> 81
        case 71:{ player->position = squares[97]; 
        	player->position->playerSymbols[player->id - 1] = '@' + player->id;
        	currentSquare->playerSymbols[player->id - 1] = ' ';
        break;
        }  // Ladder: 71 -> 98
    }

    return;
}
