# Snake-and-Ladder-Game
This is a Snake and Ladder Game implemented in C using efficient data structures. The game is designed to be interactive, adhering to the classic rules of the game while providing additional features like customizable die rolling methods and detailed gameplay statistics.

# Features

Classic Gameplay: Snakes send players down the board, while ladders help them climb faster.
Interactive Rolling: Players can roll a die virtually or input results from a physical die.
Multiple Players: Supports up to 10 players per game.
Dynamic Board: The game board is implemented as a doubly linked list.
Customizable: Easily extensible with additional features like game saving, stats, and more.
Files in the Repository
main.c: Contains the main game loop and player interaction logic.
d.h: Header file with structure definitions and function prototypes.
d.c: Contains the implementation of board setup, player movements, and game mechanics.

# Data Structures Used

1. Doubly Linked List (Game Board Representation)
Purpose: The game board is represented as a doubly linked list of nodes. Each node corresponds to a square on the board, providing a flexible and memory-efficient way to store the board's structure.
Structure (NODE):
int data: Stores the square number (e.g., 1 to 100).
char playerSymbols[MAX_PLAYERS + 1]: Stores the symbols representing players currently on the square.
struct node* rlink: Pointer to the next square (right link).
struct node* llink: Pointer to the previous square (left link).
Key Benefits:
Easy traversal in both directions.
Simplifies board manipulation, such as adding new features (e.g., traps, boosters).

2. Array (Quick Access to Squares)
Purpose: An array of pointers (NODE* squares[100]) provides direct access to each square on the board.
Usage: This allows quick lookup for snakes and ladders without needing to traverse the linked list.
Key Benefits:
Improves performance for operations like moving players, checking snakes/ladders.

3. Structs for Players
Structure (PLAYER):
int id: A unique identifier for each player.
NODE* position: A pointer to the current position of the player on the board.
Purpose: This encapsulates player-specific data, making it easier to manage multiple players in the game.
Key Benefits:
Simplifies operations related to player movement and tracking.

4. Global Variables
bool gameOver: Tracks whether the game has ended.
PLAYER* winner: Points to the winning player when the game ends.
Purpose: Shared states that are essential for game logic and flow control.

# How to Run

Compile the Game:
gcc main.c d.c -o snake_ladder -lm

Run the Game:
./snake_ladder

Follow the on-screen instructions to play the game.

Game Rules
The board consists of 100 squares.
Players roll a die to move forward.
Landing on a ladder moves the player to a higher square.
Landing on a snake moves the player to a lower square.
Rolling a 6 gives the player an extra turn.
The first player to reach square 100 wins the game.
Example Gameplay
A welcome message introduces the game and displays the rules.
Players take turns rolling the die, either virtually or manually.
The board is updated after each turn, displaying player positions.
The game ends when a player reaches square 100.

# Future Enhancements

Save and Load functionality to resume games.
Detailed player statistics.
Enhanced visual representation of the board.
