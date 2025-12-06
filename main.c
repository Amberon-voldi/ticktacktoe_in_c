/*
 * Tic-Tac-Toe Game in C
 * Author: Auto-Generated for BCA First Semester
 * Description: A complete console-based Tic-Tac-Toe game with full validation
 * 
 * Features:
 * - 3x3 game board using 2D array
 * - Two-player gameplay (X and O)
 * - Input validation and error handling
 * - Win/Draw detection
 * - Clean console output with graphics
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants for the game board and players
#define BOARD_SIZE 3
#define EMPTY_CELL ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Struct to hold game state
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];  // 2D array for game board
    char currentPlayer;                  // Current player (X or O)
    int movesCount;                      // Total moves made
    int gameOver;                        // Flag to check if game is over
} Game;

// ============= FUNCTION DECLARATIONS =============

/*
 * Function: clearScreen
 * Purpose: Clears the console screen
 * Parameters: void
 * Returns: void
 */
void clearScreen(void);

/*
 * Function: initializeGame
 * Purpose: Initialize the game board and set starting conditions
 * Parameters: pointer to Game structure
 * Returns: void
 */
void initializeGame(Game *game);

/*
 * Function: displayBoard
 * Purpose: Display the current state of the game board with borders
 * Parameters: pointer to Game structure
 * Returns: void
 */
void displayBoard(const Game *game);

/*
 * Function: displayWelcomeScreen
 * Purpose: Display welcome banner and game instructions
 * Parameters: void
 * Returns: void
 */
void displayWelcomeScreen(void);

/*
 * Function: isValidMove
 * Purpose: Check if a move is valid (within bounds and cell is empty)
 * Parameters: pointer to Game structure, row, column
 * Returns: 1 if valid, 0 if invalid
 */
int isValidMove(const Game *game, int row, int col);

/*
 * Function: makeMove
 * Purpose: Place current player's symbol on the board
 * Parameters: pointer to Game structure, row, column
 * Returns: 1 if successful, 0 if failed
 */
int makeMove(Game *game, int row, int col);

/*
 * Function: getPlayerInput
 * Purpose: Get and validate player input for their move
 * Parameters: pointer to Game structure
 * Returns: void
 */
void getPlayerInput(Game *game);

/*
 * Function: switchPlayer
 * Purpose: Switch between players X and O
 * Parameters: pointer to Game structure
 * Returns: void
 */
void switchPlayer(Game *game);

/*
 * Function: checkWin
 * Purpose: Check if current player has won
 * Parameters: pointer to Game structure, the player to check
 * Returns: 1 if player won, 0 otherwise
 */
int checkWin(const Game *game, char player);

/*
 * Function: checkDraw
 * Purpose: Check if game is a draw (board full, no winner)
 * Parameters: pointer to Game structure
 * Returns: 1 if draw, 0 otherwise
 */
int checkDraw(const Game *game);

/*
 * Function: playGame
 * Purpose: Main game loop - handle turns until game ends
 * Parameters: pointer to Game structure
 * Returns: void
 */
void playGame(Game *game);

/*
 * Function: displayGameResult
 * Purpose: Display the final game result (winner or draw)
 * Parameters: pointer to Game structure
 * Returns: void
 */
void displayGameResult(const Game *game);

/*
 * Function: playAgain
 * Purpose: Ask player if they want to play again
 * Parameters: void
 * Returns: 1 if yes, 0 if no
 */
int playAgain(void);


// ============= FUNCTION IMPLEMENTATIONS =============

/*
 * Clear the console screen using ANSI escape codes
 */
void clearScreen(void) {
    printf("\033[H\033[J");
}

/*
 * Initialize the game with an empty board and starting player
 */
void initializeGame(Game *game) {
    // Set all cells to empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY_CELL;
        }
    }
    
    // Set game starting conditions
    game->currentPlayer = PLAYER_X;  // X always starts
    game->movesCount = 0;
    game->gameOver = 0;
}

/*
 * Display the game board with borders and position numbers
 */
void displayBoard(const Game *game) {
    clearScreen();
    printf("\n");
    printf("     |     |     \n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %c  |  %c  |  %c  \n", 
               game->board[i][0], 
               game->board[i][1], 
               game->board[i][2]);
        
        if (i < BOARD_SIZE - 1) {
            printf("_____|_____|_____\n");
        }
    }
    
    printf("     |     |     \n\n");
}

/*
 * Display the reference board showing position numbers (0-8)
 */
void displayReferenceBoard(void) {
    printf("Reference Board (Position Numbers):\n");
    printf("     |     |     \n");
    printf("  0  |  1  |  2  \n");
    printf("_____|_____|_____\n");
    printf("  3  |  4  |  5  \n");
    printf("_____|_____|_____\n");
    printf("  6  |  7  |  8  \n");
    printf("     |     |     \n\n");
}

/*
 * Display welcome banner and instructions
 */
void displayWelcomeScreen(void) {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║        TIC-TAC-TOE GAME IN C           ║\n");
    printf("║     A BCA First Semester Project       ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    printf("📋 GAME RULES:\n");
    printf("   • Two players: X and O\n");
    printf("   • Players take turns marking spaces\n");
    printf("   • First to get 3 in a row (horizontal, vertical, or diagonal) wins\n");
    printf("   • If all 9 spaces are filled with no winner, the game is a draw\n\n");
    
    printf("🎮 HOW TO PLAY:\n");
    printf("   • Positions are numbered 0-8\n");
    printf("   • Enter the position number for your move\n");
    printf("   • Each position can only be used once\n\n");
}

/*
 * Check if a move is valid (position is within bounds and cell is empty)
 */
int isValidMove(const Game *game, int row, int col) {
    // Check if row and col are within board bounds
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        printf("❌ Error: Position out of bounds!\n");
        return 0;
    }
    
    // Check if cell is empty
    if (game->board[row][col] != EMPTY_CELL) {
        printf("❌ Error: Position already occupied! Choose another position.\n");
        return 0;
    }
    
    return 1;
}

/*
 * Make a move on the board
 * Note: Using pointers implicitly through game structure pointer
 */
int makeMove(Game *game, int row, int col) {
    if (isValidMove(game, row, col)) {
        game->board[row][col] = game->currentPlayer;
        game->movesCount++;
        return 1;
    }
    return 0;
}

/*
 * Get player input and make move
 * Converts 1D position (0-8) to 2D array coordinates
 */
void getPlayerInput(Game *game) {
    int position = -1;
    int row, col;
    int validInput = 0;
    char message[100] = ""; // Buffer for error messages
    
    while (!validInput) {
        // Refresh screen and show board
        displayBoard(game);
        
        // Show any error message from previous attempt
        if (strlen(message) > 0) {
            printf("%s\n", message);
            message[0] = '\0'; // Clear message
        }

        printf("🎯 Player %c's turn\n", game->currentPlayer);
        printf("Enter position (0-8): ");
        
        // Read input
        if (scanf("%d", &position) != 1) {
            // Clear the input buffer if invalid input
            while (getchar() != '\n');
            strcpy(message, "❌ Invalid input! Please enter a number between 0 and 8.");
            continue;
        }
        
        // Validate input range
        if (position < 0 || position > 8) {
            strcpy(message, "❌ Invalid position! Please enter a number between 0 and 8.");
            continue;
        }
        
        // Convert 1D position to 2D coordinates
        row = position / BOARD_SIZE;
        col = position % BOARD_SIZE;
        
        // Try to make the move
        if (makeMove(game, row, col)) {
            validInput = 1;
        } else {
            strcpy(message, "❌ Error: Position already occupied! Choose another position.");
        }
    }
}

/*
 * Switch player from X to O or O to X
 */
void switchPlayer(Game *game) {
    if (game->currentPlayer == PLAYER_X) {
        game->currentPlayer = PLAYER_O;
    } else {
        game->currentPlayer = PLAYER_X;
    }
}

/*
 * Check if the given player has won
 * Checks rows, columns, and diagonals
 */
int checkWin(const Game *game, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] == player && 
            game->board[i][1] == player && 
            game->board[i][2] == player) {
            return 1;
        }
    }
    
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (game->board[0][j] == player && 
            game->board[1][j] == player && 
            game->board[2][j] == player) {
            return 1;
        }
    }
    
    // Check main diagonal (top-left to bottom-right)
    if (game->board[0][0] == player && 
        game->board[1][1] == player && 
        game->board[2][2] == player) {
        return 1;
    }
    
    // Check anti-diagonal (top-right to bottom-left)
    if (game->board[0][2] == player && 
        game->board[1][1] == player && 
        game->board[2][0] == player) {
        return 1;
    }
    
    return 0;
}

/*
 * Check if the game is a draw
 * Game is a draw when board is full and no player has won
 */
int checkDraw(const Game *game) {
    if (game->movesCount == (BOARD_SIZE * BOARD_SIZE)) {
        // Board is full, check if no one won
        if (!checkWin(game, PLAYER_X) && !checkWin(game, PLAYER_O)) {
            return 1;
        }
    }
    return 0;
}

/*
 * Main game loop - alternate turns until game ends
 */
void playGame(Game *game) {
    while (!game->gameOver) {
        // Get player input (handles display refresh)
        getPlayerInput(game);
        
        // Check if current player won
        if (checkWin(game, game->currentPlayer)) {
            game->gameOver = 1;
            displayBoard(game);
            printf("🎉 Player %c WINS! Congratulations!\n", game->currentPlayer);
            break;
        }
        
        // Check if game is a draw
        if (checkDraw(game)) {
            game->gameOver = 1;
            displayBoard(game);
            printf("🤝 It's a DRAW! Well played, both players!\n");
            break;
        }
        
        // Switch to next player
        switchPlayer(game);
    }
}

/*
 * Display the final game result
 */
void displayGameResult(const Game *game) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║              GAME OVER                 ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("Total moves made: %d\n\n", game->movesCount);
}

/*
 * Ask if players want to play again
 */
int playAgain(void) {
    char response[10];
    
    printf("\nDo you want to play again? (yes/no): ");
    
    if (fgets(response, sizeof(response), stdin) != NULL) {
        // Convert to lowercase for comparison
        for (int i = 0; response[i]; i++) {
            response[i] = tolower(response[i]);
        }
        
        if (strncmp(response, "yes", 3) == 0 || response[0] == 'y') {
            return 1;
        }
    }
    
    return 0;
}


// ============= MAIN FUNCTION =============

/*
 * Main entry point for the Tic-Tac-Toe game
 * Handles the main game loop and replay functionality
 */
int main(void) {
    Game game;
    int continueGame = 1;
    
    // Display welcome screen
    displayWelcomeScreen();
    
    // Display reference board for position numbers
    displayReferenceBoard();
    
    // Main game loop - allows replaying
    while (continueGame) {
        // Initialize new game
        initializeGame(&game);
        
        // Play the game
        playGame(&game);
        
        // Display result
        displayGameResult(&game);
        
        // Ask if players want to play again
        continueGame = playAgain();
        
        if (continueGame) {
            printf("\n═══════════════════════════════════════\n");
            printf("Starting new game...\n");
            printf("═══════════════════════════════════════\n\n");
        }
    }
    
    // Closing message
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║     Thanks for playing Tic-Tac-Toe!   ║\n");
    printf("║         See you next time! 👋         ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    return 0;
}