# Tic-Tac-Toe Game in C
## BCA First Semester Project

A simple, modular console-based Tic-Tac-Toe game written in C.

---

## 🎮 Features

- **Two-Player Gameplay**: Player X vs Player O
- **Clean Interface**: Auto-refreshing terminal for smooth gameplay
- **Input Validation**: Prevents invalid moves and overwriting
- **Win/Draw Detection**: Automatically detects game end
- **Replay**: Play multiple games in one session

---

## 🚀 How to Compile and Run

### Prerequisites
- GCC compiler installed (macOS, Linux, or Windows with MinGW)

### Compilation

```bash
gcc -Wall -Wextra -std=c99 -o tictactoe main.c
```

### Running the Game

```bash
./tictactoe
```

---

## 🎯 How to Play

1. The board positions are numbered **0-8**:
   ```
   0 | 1 | 2
   ---------
   3 | 4 | 5
   ---------
   6 | 7 | 8
   ```
2. Enter the number corresponding to the position you want to mark.
3. Players alternate turns (X starts first).
4. Get 3 in a row (horizontal, vertical, or diagonal) to win!

---

## 💻 Code Structure

- **`main.c`**: Contains the entire source code.
- **Modular Design**: Uses functions for initialization, display, input, and game logic.
- **Data Structures**: Uses a `struct` to hold game state and a 2D array for the board.

---

## 📝 License

Educational use - Free to modify and distribute for learning purposes.
