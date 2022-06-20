// a tic tac toe game with 2 players.  Players take turns entering their move in the console

#include <iostream>
#include <ios>
#include <limits>
#include "ticTacToe.hpp"

int main(){

    char board_state[] = {'1','2','3','4','5','6','7','8','9', '\0'};// keeps track of which spaces are marked with X or marked with O.  Used as input to PrintBoard().
    int player = 1;//keeps track of who's turn it is.
    bool game_over = false;//Changes to true when the game ends
    int num_moves = 0;//tracks total number of moves taken in the game.
    int already_chosen[9];//Keeps track of which spaces have been played already.

    ExplainGame(board_state);//Prints explanation of game and the board to the console
    std::cout << "\n\n";

    //While loop runs until game ends.
    while (game_over == false){
        char choice = PlayerTurn(player, already_chosen);//Get the players input for which space to play
        
        
        if (player == 1){//updates board_state and already_chosen with player 1s choice
            board_state[choice - 1] = 'X';
            already_chosen[choice - 1] = choice;
        }
        else{//updates board_state and already_chosen with player 2's choice
            board_state[choice - 1] = 'O';
            already_chosen[choice-1] = choice;
        }

        //at the end of each turn, the board is printed, num_moves is incremented, player is switched, and the program checks to see if the game is over or not.
        PrintBoard(board_state);
        num_moves++;
        player = SwitchPlayer(player);
        game_over = IsGameOver(board_state, num_moves);
    }

    //asks user if they would like to play a new game and runs program again if input is "y"
    char play_again;
    std::cout << "The game is over.\n\n";
    std::cout << "Would you like to play again?  y/n:\n";
    std::cin >> play_again;

    if (play_again == 'y'){
        main();
    }

    

    return 0;
}