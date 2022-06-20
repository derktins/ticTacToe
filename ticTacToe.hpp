// header file for ticTacToe.cpp

#include <iostream>
#include <ios>
#include <limits>
#include "ticTacToe_functions.cpp"



void ExplainGame(char input[]);
void PrintBoard(char input[]);
int GetChoice();
int PlayerTurn(int player, int already_chosen[]);
int SwitchPlayer(int player);
bool IsGameOver(int input[], int num_moves);
