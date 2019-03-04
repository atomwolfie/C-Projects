//Aaron Adams
//Tic tac toe
//Xcode

#include <iostream>
#include <string>
#include "ticTacToe.h"

using namespace std;


int main() {
    
    char answer;
   
    TicTacToe game;
    
    game.reset();
    
    game.displayInstructions();
    
    game.displayBoard();
    
    
    do{
        
        
        
    do{
        
        
               
        game.move();
        
        
    
    }while(!game.checkForWin());
    
    game.gameDone();
    
        
    cout << "Do you want to play again? (enter Y for yes or N for no): ";
    
    cin >> answer;
    
    
    }while(answer == 'Y' || answer == 'y');
    
    cout << endl << "See Ya!!! " << endl;
    
    
        return 0;
    
}



    

