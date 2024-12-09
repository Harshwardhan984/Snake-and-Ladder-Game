#include <stdio.h>
#include <stdlib.h>
#include "d.h"  // Updated header file name for consistency

int main() {
    // Create the head of the board and initialize the game board
    NODE* head = (NODE*)malloc(sizeof(NODE));
    head = createTable(head);

    // Variable declarations
    char ch;
    int rem = 0;
    PLAYER players[MAX_PLAYERS];   // Array to hold player information
    int no_of_players;

    // Welcome message and rules display
    printf("\t\tWelcome to the Snake and Ladder Game!\n");
    displayRules();

    // Input the number of players with validation
    do {
        printf("Enter the number of players (max no. of players is %d): ", MAX_PLAYERS);
        scanf("%d", &no_of_players);
        if (no_of_players > MAX_PLAYERS || no_of_players < 1) {
            printf("Invalid number of players. Please enter between 1 and %d.\n", MAX_PLAYERS);
        }
    } while (no_of_players > MAX_PLAYERS || no_of_players < 1);

    // Initialize players
    for (int k = 0; k < no_of_players; k++) {
        players[k].id = k + 1;                // Assign unique IDs to players
        players[k].position = createPlayer(head);  // Place players at the starting square
    }

    // Main game loop
    while (1) {
        for (int k = 0; k < no_of_players; k++) {
            // Roll the die and move the player
            int remtem;
            rem = 0;
            while(1){
            printf("Do you want to roll die auto? (y/n): ");
                scanf(" %c", &ch);
                if (ch == 'y') {
                    remtem = randomDie();
                }
                else
                remtem = rollPhysicalDie();
                
		rem = rem + remtem;
            printf("Player %d rolled a %d\n", players[k].id, remtem);
            if(remtem == 6){
            	
            	printf("Player %d got one more chance to roll die\n", players[k].id);
            }
            else 
            	break;
            }
            
            movePlayer(&players[k], rem);
            checkSnakeOrLadder(&players[k]);  // Adjust position for snakes and ladders

            // Check if the game is over
            if (gameOver) {
                printf("\n*** Congratulations! Player %d has won the game! ***\n", winner->id);
                printf("Do you want to start a new game? (y/n): ");
                scanf(" %c", &ch);
                if (ch == 'n') {
                    free(head);  // Free allocated memory before exiting
                    return 0;
            
                    break;
                }
            }
        }

        // Display the updated game board after every round
        displayBoard(head, no_of_players);

        // Ask players if they want to continue
        printf("\nDo you wish to continue? (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'n') {
            printf("Thanks for playing! Exiting the game.\n");
            break;
        }
    }

    // Free memory before exiting
    free(head);
    return 0;
}

// Function to display the game rules
void displayRules() {
    printf("\n--- Game Rules ---\n");
    printf("1. The game is played on a 100-square board.\n");
    printf("2. Players take turns rolling a die to move forward.\n");
    printf("3. Landing on a ladder will move you up to a higher square.\n");
    printf("4. Landing on a snake will send you down to a lower square.\n");
    printf("5. The first player to reach square 100 wins the game.\n");
    printf("6. If you roll a 6, you get an extra turn!\n\n");
}


