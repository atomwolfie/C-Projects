#include "Blackjack.h"

#include <ctime>





Blackjack::Blackjack() { //calls reset
    
    reset();
    
}



void Blackjack::reset() {   //restarts the game
    
    cout << "Dealing cards... " << endl << endl;
    
    for (int i=0; i<13; i++)
        
        deck[i]=4;
    
    
    
    showHole=false;
    
    status=PLAYER_TURN;
    
    
    
    playerHand.clear();
    
    dealerHand.clear();
    
    
    
    srand(time(NULL));
    
    
    
    int card = rand()%13;
    
    
    
    playerHand.push_back(card+1);
    
    deck[card]--;
    
    
    
    card = rand()%13;
    
    dealerHand.push_back(card+1);
    
    deck[card]--;
    
    
    
    card = rand()%13;
    
    playerHand.push_back(card+1);
    
    deck[card]--;
    
    
    
    card = rand()%13;
    
    dealerHand.push_back(card+1);
    
    deck[card]--;
    
}



Status Blackjack::getStatus()

{
    
    return status;
    
}



int Blackjack::getPlayerScore()

{
    
    int bestScore=0;
    
    int i;
    
    for(i=0; i<playerHand.size(); i++)
        
    {
        
        if (playerHand.at(i)>10)
            
            bestScore+=10;
        
        else
            
            bestScore+=playerHand.at(i);
        
    }
    
    
    
    for(i=0; i<playerHand.size(); i++)
        
    {
        
        if (playerHand.at(i)==1 && (bestScore+10)<=21)
            
            bestScore+=10;
        
    }
    
    return bestScore;
    
}



int Blackjack::getDealerScore()

{
    
    
    int bestScore=0;
    
    int i;
    
    for(i=0; i<dealerHand.size(); i++)
        
    {
        
        if (dealerHand.at(i)>10)
            
            bestScore+=10;
        
        else
            
            bestScore+=dealerHand.at(i);
        
    }
    
    
    
    for(i=0; i<dealerHand.size(); i++)
        
    {
        
        if (dealerHand.at(i)==1 && (bestScore+10)<=21)
            
            bestScore+=10;
        
    }
    
    return bestScore;
    
    return 0;
    
}



void Blackjack::displayDealerHand()

{
    
    cout<<"Dealer Hand: ";
    
    for (int i=0; i<(int)dealerHand.size(); i++)
        
    {
        
        if (i==1 && !showHole)
            
            cout<<"H ";
        
        else
            
        {
            
            switch (dealerHand[i])
            
            {
                    
                case 1: cout<<"A "; break;
                    
                case 11: cout<<"J "; break;
                    
                case 12: cout<<"Q "; break;
                    
                case 13: cout<<"K "; break;
                    
                default: cout<<dealerHand[i]<<" ";
                    
            }
            
        }
        
    }
    
    cout<<endl;
    
}



void Blackjack::displayPlayerHand()

{
  
    
    cout<<"Player Hand: ";
    
    for (int i=0; i<(int)dealerHand.size(); i++){
        
        if (i==1 && !showHole){
            
            cout<<"H ";
        }
        
        
        else{
            
            switch (dealerHand[i]){
                    
                case 1: cout<<"A "; break;
                    
                case 11: cout<<"J "; break;
                    
                case 12: cout<<"Q "; break;
                    
                case 13: cout<<"K "; break;
                    
                default: cout<<dealerHand[i]<<" ";
                    
            }
            
        }
        
    }
    
    cout<<endl;
    
}



void Blackjack::displayInstructions(){
    
    cout << "Welcome to Black Jack" << endl;
    
    cout << "The object is to get to 21" << endl;
    
    cout << "Enter h to hit or p to pass " << endl << endl;
    
    
    
}



void Blackjack:: makeMove(Move move){
    
    
    
    if (move == HIT)
        
        hit();
    
    else
        
        pass();
    
}



int Blackjack::hit(){
    
    int card;
    
    
    
    do {
        
        card=rand()%13;
        
    } while (deck[card]<=0);
    
    
    
    if (status==PLAYER_TURN)
        
        playerHand.push_back(card+1);
    
    else
        
        dealerHand.push_back(card+1);
    
    
    
    deck[card]--;
    
    
    
    
    return card+1;
    
}



void Blackjack::pass(){
    
    
    
    
    if (status == PLAYER_TURN){
        
        
        
        cout << "you decided to pass" << endl;
        
        status = DEALER_TURN;
        
        
        
    }
    
    
    
    else{
        
        
        
        status = PLAYER_TURN;
        
        
        
        cout << "The dealer chose to pass " << endl;
        
    }
    
}



void Blackjack::resolveWinner(){
    
    
    
    
    if(getPlayerScore() > getDealerScore() && getPlayerScore() <= 21){
        
        status = PLAYER_WIN;
        
        
        
        cout << "You win with " << getPlayerScore() << " points, to the dealer's " << getDealerScore() << " points " << endl;
        
    }
    
    else if(getPlayerScore() < getDealerScore() && getDealerScore() <= 21){
        
        status = DEALER_WIN;
        
        
        
        cout << " The dealer wins with " << getDealerScore() << " to your " << getPlayerScore() << " points" <<endl;
        
    }
    
    else if( getPlayerScore() <= 21 && getDealerScore() > 21){
        
        status = PLAYER_WIN;
        
        
        
        cout << "You win with " << getPlayerScore() << " points, to the dealer's " << getDealerScore() << " points " << endl;
        
    }
    
    else if (getDealerScore() <= 21 && getPlayerScore() > 21){
        
        status = DEALER_WIN;
        
        
        
        
        
        cout << " The dealer wins with " << getDealerScore() << " to your " << getPlayerScore() << " points" <<endl;
        
        
        
    }
    
    else if (getPlayerScore() == 21 && (getDealerScore() < 21 || getDealerScore() > 21)){
        
        status = PLAYER_WIN;
        
        
        
        cout << "You win with " << getPlayerScore() << " points, to the dealer's " << getDealerScore() << " points " << endl;
        
        
        
        
        
    }
    
    else if (getDealerScore() == 21 && (getPlayerScore() < 21 || getPlayerScore() > 21)){
        
        status = DEALER_WIN;
        
        
        
        
        
        cout << " The dealer wins with " << getDealerScore() << " to your " << getPlayerScore() << " points" <<endl;
        
    }
    
    
    
    else if (getDealerScore() == getPlayerScore()){
        
        status = DEALER_WIN;
        
        
        
        
        
        cout << "tie!" << endl;
        
        
        
        
        
        
        
    }
    
    else{
        
       
    }
    
    
    
    
    
}

