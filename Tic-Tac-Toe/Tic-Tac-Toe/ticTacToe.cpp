#include <iostream>
#include "ticTacToe.h"



using namespace std;

TicTacToe :: TicTacToe(){
    
    reset();
    
}

void TicTacToe :: reset(){
    board[0][0]= '1';
    board[0][1]= '2';
    board[0][2]= '3';
    board[1][0]= '4';
    board[1][1]= '5';
    board[1][2]= '6';
    board[2][0]= '7';
    board[2][1]= '8';
    board[2][2]= '9';
    
    turn = 'X';
    
    numMoves = 0;
    
    
       
    


    void move(int cell);
    
    
}

void TicTacToe:: move(){
    
    
    
    if (turn == 'X')
    {
        cout << "Player X choose cell: ";
    }
    else if (turn == 'O')
    {
        cout << "Player O choose cell: ";
    }
    cin >> cell;
    
    
    switch (cell){
            
           
            
        case 1: row = 0; column = 0;
            break;
       
        case 2: row = 0; column = 1;
            break;
       
        case 3: row = 0; column = 2;
            break;
        
        case 4: row = 1; column = 0;
            break;
            
        case 5: row = 1; column = 1;
            break;
        
        case 6: row = 1; column = 2;
            break;
        
        case 7: row = 2; column = 0;
            break;
        
        case 8: row = 2; column = 1;
            break;
        
        case 9: row = 2; column = 2;
            break;
            
        default:
    cout << "Enter number between 1-9: ";
            move();
    }
    
    
    
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        
        board[row][column] = 'X';
        
        turn = 'O';
        
    }
    
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
       
        board[row][column] = 'O';
        
        turn = 'X';
        
       
    }
    
    else{
        cout << endl << "Cell taken!!!" << endl << endl;
        
        move();
    }
    
    displayBoard();
}




void TicTacToe :: displayInstructions() {
    
    cout << "This is the game of Tic Tac Toe.";
    cout << " X moves first.";
    cout << " Each player chooses their move by selecting the cell they want to place their mark in.";
    cout << "The cells are numbered as follows: " << endl << endl;
    
    
    cout << " 1 | 2 | 3 " << endl;
    cout << "-----------" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "-----------" << endl;
    cout << " 7 | 8 | 9 " << endl << endl;
    cout << " X goes first" << endl << endl << endl;
    
}

void TicTacToe:: displayBoard(){
    {
        
        
        
        cout << "     |     |     " << endl;
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
        cout << "     |     |     " << endl << endl << endl;    }
    
    
    
    
}

bool TicTacToe:: checkForWin(){
    
    
    for (int i = 0; i < 3; i++){ //checking for tie
        
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            return true;
        }
    }
    
    for (int i = 0; i < 3; i++){ //Checking for tie
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    tie = true;
    return true;

}

char TicTacToe:: getPlayer1(){
    
    return X;
    
}

char TicTacToe:: getPlayer2(){
    
    return O;
    
}


void TicTacToe:: gameDone(){
    
    if (turn == 'O' && !tie)
    {
        
        cout << endl << endl << " X wins!!!" << endl << endl;
    }
    else if (turn == 'X' && !tie)
    {
        
        cout << endl << endl << " O wins!!!" << endl << endl;
    }
    
    else
    {
        
        cout << endl << endl << " Tie game! " << endl << endl;
    }

    reset();
    
    
}


    
    
    
    


