
#ifndef BLACKJACK_H

#define BLACKJACK_H



#include <iostream>

#include <vector>

using namespace std;



enum Status { PLAYER_TURN, DEALER_TURN, PLAYER_WIN, DEALER_WIN };

enum Move { HIT, PASS };

class Blackjack {
    
private:
    
    vector <int> playerHand;
    
    vector <int> dealerHand;
    
    bool showHole;
    
    int deck[13];
    
    Status status;
    
    
    
    int hit();
    
    void pass();
    
    
    
public:
    
    void resolveWinner();
    
    Blackjack();
    
    void reset();
    
    Status getStatus();
    
    int getPlayerScore();
    
    void displayPlayerHand();
    
    int getDealerScore();
    
    void displayDealerHand();
    
    void makeMove(Move move);
    
    void displayInstructions();
    
};



#endif

