#include <iostream>
#include <limits>

#include "functions.hpp"

int main() {
  std::vector<std::vector<char>> board;
  InitializeBoard(board);

  char current_player = 'X';
  int row = 0, col = 0;

  PrintBoard(board);

  while (true) {
    std::cout << "Player " << current_player << ", enter your move (row and column): ";

    while (!(std::cin >> row >> col)) {
      std::cin.clear();  // Clear the error state
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
      std::cerr << "Invalid input: Please enter integers." << std::endl;
    }

    if (MakeMove(board, row, col, current_player)) {
      PrintBoard(board);  // ✅ Show updated board after move

      char winner = CheckWinner(board);  // ✅ Check winner first
      if (winner != ' ') {
        std::cout << "Player " << winner << " wins!" << std::endl;
        break;
      }

      if (IsBoardFull(board)) {  // ✅ Then check for tie
        std::cout << "It's a tie!" << std::endl;
        break;
      }

      SwitchPlayer(current_player);
    } else {
      // Optional: reprint the board so player sees the current state
      PrintBoard(board);
    }
  }

  return 0;
}
