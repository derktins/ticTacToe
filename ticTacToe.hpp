// header file for ticTacToe.cpp

#include <iostream>
#include "ticTacToe_functions.cpp"



void ExplainGame(char input[]);
void PrintBoard(char input[]);
int GetChoice();
int PlayerTurn(int player);
int SwitchPlayer(int player);
bool IsGameOver(int input[], int num_moves);
