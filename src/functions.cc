#include "functions.hpp"
#include <iostream>

// Prints the Tic-Tac-Toe board
void PrintBoard(const std::vector<std::vector<char>>& board) {
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    for (unsigned int j = 0; j < kBoardSize; ++j) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

// Initializes the board with spaces
void InitializeBoard(std::vector<std::vector<char>>& board) {
  board.clear();
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    board.push_back(std::vector<char>(kBoardSize, ' '));
  }
}

// Attempts to place player's move
bool MakeMove(std::vector<std::vector<char>>& board, int row, int col, char player) {
  // FIX: changed > to >= so that indices 3 are rejected (valid are 0..2)
  if (row < 0 || row >= kBoardSize || col < 0 || col >= kBoardSize) { 
    std::cerr << "Error: Move out of bounds!\n";
    return false;
  }

  // Cell already taken
  if (board[row][col] != ' ') {
    std::cerr << "Error: Cell already occupied!\n";
    return false;
  }

  board[row][col] = player;
  return true;
}

// Checks if there's a winner
char CheckWinner(const std::vector<std::vector<char>>& board) {
  // Check rows
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return board[i][0];                                        
    }
  }

  // Check columns
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return board[0][i];                                         
    }
  }

  // Main diagonal
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return board[0][0];
  }

  // Anti-diagonal
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return board[0][2];
  }

  // FIX: Added return ' ' for "no winner"
  return ' ';
}

// Checks if the board is full
bool IsBoardFull(const std::vector<std::vector<char>>& board) {
  for (unsigned int i = 0; i < kBoardSize; ++i) {
    for (unsigned int j = 0; j < kBoardSize; ++j) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

// Switches current player
void SwitchPlayer(char& player) {
  player = (player == 'X') ? 'O' : 'X';
}
