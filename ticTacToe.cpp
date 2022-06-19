// a tic tac toe game with 2 players.  Players take turns entering their move in the console

#include <iostream>
#include "ticTacToe.hpp"

int main(){

    char board_state[] = {'1','2','3','4','5','6','7','8','9', '\0'};
    int player = 1;
    bool game_over = false;
    int num_moves = 0;
    int already_chosen[9];

    ExplainGame(board_state);
    std::cout << "\n\n";

    while (game_over == false){
        char choice = PlayerTurn(player, already_chosen);
        
        
        if (player == 1){
            board_state[choice - 1] = 'X';
            already_chosen[choice - 1] = choice;
        }
        else{
            board_state[choice - 1] = 'O';
            already_chosen[choice-1] = choice;
        }


        PrintBoard(board_state);
        num_moves++;
        player = SwitchPlayer(player);
        game_over = IsGameOver(board_state, num_moves);
    }

    char play_again;
    std::cout << "The game is over.\n\n";
    std::cout << "Would you like to play again?  y/n:\n";
    std::cin >> play_again;

    if (play_again == 'y'){
        main();
    }

    

    return 0;
}