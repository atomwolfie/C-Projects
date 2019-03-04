#include <iostream>
#include <iostream>

using namespace std;


const int SIZE = 3;


class TicTacToe{
    
    
    
public:
    
    enum Status { ONGOING, DRAW, PLAYER_1_WIN, PLAYER_2_WIN };

    
    TicTacToe();
    
    void reset();
    
    Status getStatus();
    
    char getPlayer1();
    
    char getPlayer2();
    
    char nextToMove();
    
    void displayInstructions();
    
    void displayBoard();

    void move();

    bool checkForWin();
    
    void gameDone();
    
   
    
    
private:
    
    char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    
    char X, O;
    
    int numMoves, cell;
    
    int row = 0, column = 0;
    
    char player[2];
    
    Status status;
    
    bool tie = false;
    
    char turn;
    
    
};




















