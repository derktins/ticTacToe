// functions for ticTacToe.cpp

#include <iostream>
#include <ios>
#include <limits>


using namespace std;
  


//Function which prints the game board displaying numbers for each space on the board and adding X's and O's to it as the game is played
void PrintBoard(char input[]){
    std::cout << "    |    |    \n";
    std::cout << "  " << input[0] << " |  " << input[1] << " |  " << input[2]<< " \n";
    std::cout << "____|____|____\n";
    std::cout << "    |    |    \n";
    std::cout << "  " << input[3] << " |  " << input[4] << " |  " << input[5]<< " \n";
    std::cout << "____|____|____\n";
    std::cout << "    |    |    \n";
    std::cout << "  " << input[6] << " |  " << input[7] << " |  " << input[8]<< " \n";
    std::cout << "    |    |    \n";
}


//Function that prints a welcome message and an explanation of how the game is played.
void ExplainGame(char input[]){
    std::cout << "Welcome to Tic Tac Toe.  Please note the numbering system on the board below.  You will make your moves by entering a number corresponding with the spaces on the board.\n\n";

    PrintBoard(input);

}






//function which asks the user for an integer input and rejects any non integer inputs.
int GetChoice(){
    cout << "Enter a number 1-9 to make your move.\n";
    int x = 0;
    while(!(cin >> x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Please choose a number 1-9.\n";
    }

    return x;

}

//Function which calls GetChoice() for the user's desired play.  Will reject any input not between 1 and 9 or any choice which has already been played.
int PlayerTurn(int player, int already_chosen[]){
    char choice;
    std::cout << "It is player " << player << "'s turn.\n";
    
    choice = GetChoice();

    while (choice > 9 || choice < 1 || choice == already_chosen[choice-1]){
        cout << "Please choose a number between 1 and 9 which has not already been played.\n";
        choice = GetChoice();
    }
  
    
    

    return choice;
}

//Function which changes the state of variable "player, which is used to keep track of which player's turn it is."
int SwitchPlayer(int player){
    if (player == 1){
        return 2;
    }
    return 1;
}







//This function is called at the end of each turn to check if the game is over.  Will end the game if any player satisfies win conditions or if all spaces are played.
bool IsGameOver(char input[], int num_moves){
    if (num_moves > 8){
        return true;
    }
    for (int i = 0; i < 3; i++){
        if (input[i] == input[i+3] && input[i] == input[i+6]){
            return true;
        }
    }
    
    
    for (int i = 0; i < 7; i+=3){
        if (input[i] == input[i+1] && input[i] == input[i+2]){
            return true;
        }
    }
    

    if (input[0] == input[4] && input[0] == input[8]){
        return true;
    }

    
    if (input[2] == input[4] && input[2] == input[6]){
        return true;
    }

    return false;

}




