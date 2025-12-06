# Tic-Tac-Toe Game in C
## BCA First Semester Project

A complete, modular console-based Tic-Tac-Toe game written in C with comprehensive comments for beginners.

---

## 📋 Project Overview

This project demonstrates fundamental C programming concepts suitable for first-year BCA students:
- **Arrays**: 2D array for game board
- **Functions**: Modular design with 12+ functions
- **Pointers**: Used with struct pointers and pass-by-reference
- **Input Validation**: Comprehensive error handling
- **Control Flow**: Loops, conditionals, and game logic

---

## 🎮 Features

✅ **Two-Player Gameplay**: Player X vs Player O  
✅ **Input Validation**: Cannot overwrite filled positions  
✅ **Win Detection**: Checks rows, columns, and diagonals  
✅ **Draw Detection**: Identifies when board is full with no winner  
✅ **Clean UI**: Formatted board display with position reference  
✅ **Replay Functionality**: Play multiple games in one session  
✅ **Clear Comments**: Every function documented for learners  

---

## 📦 Project Structure

```
ticktacktoe_in_c/
├── main.c              # Complete game implementation
├── README.md           # This file
├── HOW_IT_WORKS.md     # Detailed explanation
├── FLOWCHART.txt       # Game flowchart
└── SAMPLE_OUTPUT.txt   # Example game session
```

---

## 🚀 How to Compile and Run

### Prerequisites
- GCC compiler installed
- macOS, Linux, or Windows (with MinGW)

### Compilation

```bash
gcc -Wall -Wextra -std=c99 -o tictactoe main.c
```

**Flags explanation:**
- `-Wall -Wextra`: Show all warnings
- `-std=c99`: Use C99 standard
- `-o tictactoe`: Output executable name

### Running the Game

```bash
./tictactoe
```

---

## 🎯 Game Rules

1. **Board Layout**: 3×3 grid with positions numbered 0-8
2. **Players**: X goes first, O goes second
3. **Turn Structure**: Players alternate entering positions
4. **Winning Condition**: Get 3 of your symbols in a row (horizontal, vertical, or diagonal)
5. **Draw Condition**: All 9 positions filled with no winner

### Position Reference
```
0 | 1 | 2
---------
3 | 4 | 5
---------
6 | 7 | 8
```

---

## 💻 Code Structure

### Main Components

#### 1. **Game Structure** (Line 26-31)
```c
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];  // 2D array
    char currentPlayer;                  // Current player
    int movesCount;                      // Total moves
    int gameOver;                        // Game status
} Game;
```

#### 2. **Core Functions**

| Function | Purpose | Key Concepts |
|----------|---------|--------------|
| `initializeGame()` | Setup new game | Array initialization, struct |
| `displayBoard()` | Show game state | 2D array access, formatting |
| `makeMove()` | Place symbol | Input validation, arrays |
| `checkWin()` | Detect winner | Logic, conditionals |
| `checkDraw()` | Detect draw | Array iteration |
| `playGame()` | Main loop | Loops, game flow |

#### 3. **Key Algorithms**

**Win Detection**: Checks 8 possible winning conditions
- 3 rows
- 3 columns
- 2 diagonals

**Input Conversion**: Converts 1D position (0-8) to 2D coordinates
```c
row = position / 3;
col = position % 3;
```

---

## 🔍 Key Learning Points for Beginners

### 1. **2D Arrays**
The board uses a 2D array:
```c
char board[3][3];
board[row][col] = 'X';
```

### 2. **Pointers & Struct**
Game state passed by pointer:
```c
void initializeGame(Game *game);  // Using pointer
game->currentPlayer = 'X';        // Arrow operator
```

### 3. **Function Modularity**
Each task has a dedicated function:
- Input handling
- Validation
- Game logic
- Display

### 4. **Input Validation**
```c
if (position < 0 || position > 8) {
    printf("Invalid position!\n");
    continue;  // Ask again
}
```

### 5. **Control Flow**
Nested loops and conditionals for game logic:
```c
while (!game->gameOver) {
    displayBoard(game);
    getPlayerInput(game);
    if (checkWin(game, currentPlayer)) {
        game->gameOver = 1;
    }
}
```

---

## 📊 Data Flow Diagram

```
START
  ↓
Display Welcome & Rules
  ↓
Initialize Game
  ↓
┌─→ Display Board
│   ↓
│   Get Player Input
│   ↓
│   Validate Move
│   ├─ Invalid? → Ask again
│   └─ Valid? → Make Move
│   ↓
│   Check Win?
│   ├─ Yes → End Game (Winner)
│   └─ No → Continue
│   ↓
│   Check Draw?
│   ├─ Yes → End Game (Draw)
│   └─ No → Continue
│   ↓
│   Switch Player
└─ Repeat until game over
  ↓
Ask Play Again?
├─ Yes → Go back to Initialize
└─ No → Continue
  ↓
Display Goodbye
  ↓
END
```

---

## 📝 Sample Game Session

See `SAMPLE_OUTPUT.txt` for a complete game example.

---

## ✨ Optional Improvements

### Easy Level (Beginner)
1. **Player Names**: Allow players to enter their names
   ```c
   char player1Name[50], player2Name[50];
   ```

2. **Win Counter**: Keep track of wins across games
   ```c
   int playerXWins = 0, playerOWins = 0;
   ```

3. **Game Statistics**: Display total games, wins, draws
   ```c
   printf("Games played: %d\n", totalGames);
   ```

### Intermediate Level
1. **Difficulty Levels**: Add AI opponent (Easy, Medium, Hard)
2. **Game History**: Save and display previous moves
3. **Undo Move**: Allow players to undo last move
4. **Enhanced Graphics**: Use ANSI colors for better visuals

### Advanced Level
1. **Network Play**: Play over network using sockets
2. **Game Save/Load**: Store game state to file
3. **Web Interface**: Convert to JavaScript/web version
4. **Minimax Algorithm**: Unbeatable AI using game theory

---

## 🐛 Troubleshooting

### Issue: "Compilation failed"
**Solution**: Ensure you have GCC installed
```bash
gcc --version
```

### Issue: "Program crashes on input"
**Solution**: The program validates input. Enter numbers 0-8 only.

### Issue: "Can play in occupied space"
**Solution**: This shouldn't happen - the validation should prevent it. Check input validation.

---

## 📚 Related C Concepts to Study

After completing this project, explore:
- File I/O (saving games)
- Dynamic memory allocation (malloc/free)
- Recursion (minimax for AI)
- Bit manipulation (efficient board storage)
- Data structures (linked lists, queues)

---

## 🎓 Assessment Criteria

This project successfully demonstrates:

| Criterion | Status |
|-----------|--------|
| Uses arrays | ✅ 2D array for board |
| Uses functions | ✅ 12+ functions |
| Uses pointers | ✅ Struct pointers |
| Input validation | ✅ Position validation |
| Game logic | ✅ Win/draw detection |
| Clear comments | ✅ Every function documented |
| Compiles with GCC | ✅ No warnings |
| Clean output | ✅ Formatted display |
| Follows C standards | ✅ C99 standard |

---

## 📄 License

Educational use - Free to modify and distribute for learning purposes.

---

## 👨‍💻 Author Notes

This code is written specifically for BCA first-semester students. Every function includes:
- Purpose statement
- Parameter descriptions
- Return value explanation
- Inline comments explaining logic

Feel free to modify, extend, and learn from this code!

---

**Last Updated**: December 2025  
**Tested On**: macOS with GCC 14.x
