#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>

const int kBoardSize = 3;

void PrintBoard(const std::vector<std::vector<char>>& board);

void InitializeBoard(std::vector<std::vector<char>>& board);

bool MakeMove(std::vector<std::vector<char>>& board,
              int row,
              int col,
              char player);

char CheckWinner(const std::vector<std::vector<char>>& board);

bool IsBoardFull(const std::vector<std::vector<char>>& board);

void SwitchPlayer(char& player);

#endif