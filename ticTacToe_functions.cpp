// functions for ticTacToe.cpp

# include <iostream>
  



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



void ExplainGame(char input[]){
    std::cout << "Welcome to Tic Tac Toe.  Please note the numbering system on the board below.  You will make your moves by entering a number corresponding with the spaces on the board.\n\n";

    PrintBoard(input);

}

int GetChoice(){
    int choice;
    std::cout << "Please choose you move (enter  1 - 9):  \n";
    std::cin >> choice;
    return choice; 

}

int PlayerTurn(int player){
    std::cout << "It is player " << player << "'s turn.\n";
    int choice = GetChoice();
    return choice;
}

int SwitchPlayer(int player){
    if (player == 1){
        return 2;
    }
    return 1;
}








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




