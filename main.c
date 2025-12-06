#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define BOARD_SIZE 3
#define EMPTY_CELL ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];  
    char currentPlayer;               
    int movesCount;                      
    int gameOver;                        
} Game;

void clearScreen(void);
void initializeGame(Game *game);
void displayBoard(const Game *game);
void displayWelcomeScreen(void);
int isValidMove(const Game *game, int row, int col);
int makeMove(Game *game, int row, int col);
void getPlayerInput(Game *game);
void switchPlayer(Game *game);
int checkWin(const Game *game, char player);
int checkDraw(const Game *game);
void playGame(Game *game);
void displayGameResult(const Game *game);
int playAgain(void);

void clearScreen(void) {
    printf("\033[H\033[J");
}

void initializeGame(Game *game) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY_CELL;
        }
    }
    
    game->currentPlayer = PLAYER_X;  
    game->movesCount = 0;
    game->gameOver = 0;
}

void displayBoard(const Game *game) {
    clearScreen();
    printf("\n");
    printf("     |     |     \n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        char c1 = (game->board[i][0] == EMPTY_CELL) ? ('0' + (i * BOARD_SIZE + 0)) : game->board[i][0];
        char c2 = (game->board[i][1] == EMPTY_CELL) ? ('0' + (i * BOARD_SIZE + 1)) : game->board[i][1];
        char c3 = (game->board[i][2] == EMPTY_CELL) ? ('0' + (i * BOARD_SIZE + 2)) : game->board[i][2];

        printf("  %c  |  %c  |  %c  \n", c1, c2, c3);
        
        if (i < BOARD_SIZE - 1) {
            printf("_____|_____|_____\n");
        }
    }
    
    printf("     |     |     \n\n");
}

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


int isValidMove(const Game *game, int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        printf("❌ Error: Position out of bounds!\n");
        return 0;
    }
    
    if (game->board[row][col] != EMPTY_CELL) {
        printf("❌ Error: Position already occupied! Choose another position.\n");
        return 0;
    }
    
    return 1;
}

int makeMove(Game *game, int row, int col) {
    if (isValidMove(game, row, col)) {
        game->board[row][col] = game->currentPlayer;
        game->movesCount++;
        return 1;
    }
    return 0;
}


void getPlayerInput(Game *game) {
    int position = -1;
    int row, col;
    int validInput = 0;
    char message[100] = ""; 
    
    while (!validInput) {
        displayBoard(game);
        
        if (strlen(message) > 0) {
            printf("%s\n", message);
            message[0] = '\0'; 
        }

        printf("🎯 Player %c's turn\n", game->currentPlayer);
        printf("Enter position (0-8): ");
        
      
        if (scanf("%d", &position) != 1) {
            while (getchar() != '\n');
            strcpy(message, "❌ Invalid input! Please enter a number between 0 and 8.");
            continue;
        }
        
        if (position < 0 || position > 8) {
            strcpy(message, "❌ Invalid position! Please enter a number between 0 and 8.");
            continue;
        }
        row = position / BOARD_SIZE;
        col = position % BOARD_SIZE;
        
        if (makeMove(game, row, col)) {
            validInput = 1;
        } else {
            strcpy(message, "❌ Error: Position already occupied! Choose another position.");
        }
    }
}


void switchPlayer(Game *game) {
    if (game->currentPlayer == PLAYER_X) {
        game->currentPlayer = PLAYER_O;
    } else {
        game->currentPlayer = PLAYER_X;
    }
}

int checkWin(const Game *game, char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] == player && 
            game->board[i][1] == player && 
            game->board[i][2] == player) {
            return 1;
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (game->board[0][j] == player && 
            game->board[1][j] == player && 
            game->board[2][j] == player) {
            return 1;
        }
    }

    if (game->board[0][0] == player && 
        game->board[1][1] == player && 
        game->board[2][2] == player) {
        return 1;
    }
 
    if (game->board[0][2] == player && 
        game->board[1][1] == player && 
        game->board[2][0] == player) {
        return 1;
    }
    
    return 0;
}

int checkDraw(const Game *game) {
    if (game->movesCount == (BOARD_SIZE * BOARD_SIZE)) {
        if (!checkWin(game, PLAYER_X) && !checkWin(game, PLAYER_O)) {
            return 1;
        }
    }
    return 0;
}

void playGame(Game *game) {
    while (!game->gameOver) {
        getPlayerInput(game);
        
        if (checkWin(game, game->currentPlayer)) {
            game->gameOver = 1;
            displayBoard(game);
            printf("🎉 Player %c WINS! Congratulations!\n", game->currentPlayer);
            break;
        }
        
        if (checkDraw(game)) {
            game->gameOver = 1;
            displayBoard(game);
            printf("🤝 It's a DRAW! Well played, both players!\n");
            break;
        }
   
        switchPlayer(game);
    }
}

void displayGameResult(const Game *game) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║              GAME OVER                 ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("Total moves made: %d\n\n", game->movesCount);
}

int playAgain(void) {
    char response[10];
    
    printf("\nDo you want to play again? (yes/no): ");
    
    if (fgets(response, sizeof(response), stdin) != NULL) {
        for (int i = 0; response[i]; i++) {
            response[i] = tolower(response[i]);
        }
        
        if (strncmp(response, "yes", 3) == 0 || response[0] == 'y') {
            return 1;
        }
    }
    
    return 0;
}


int main(void) {
    Game game;
    int continueGame = 1;
    
    displayWelcomeScreen();
    
    while (continueGame) {
        initializeGame(&game);
        
        playGame(&game);
        
        displayGameResult(&game);
        
        continueGame = playAgain();
        
        if (continueGame) {
            printf("\n═══════════════════════════════════════\n");
            printf("Starting new game...\n");
            printf("═══════════════════════════════════════\n\n");
        }
    }
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║     Thanks for playing Tic-Tac-Toe!   ║\n");
    printf("║         See you next time! 👋         ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    return 0;
}