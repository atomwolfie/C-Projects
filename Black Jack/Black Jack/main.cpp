#include <iostream>

#include "blackjack.h"



using namespace std;



int main() {
    
    
    Blackjack play;
    
    
    
    play.displayInstructions();
    
    
    
    
    play.reset();
    
    play.getDealerScore();
    
    play.getPlayerScore();
    
    play.displayDealerHand();
    
    play.displayPlayerHand();
    
    
    
    play.resolveWinner();
    
    
    
    
    return 0;
    
}