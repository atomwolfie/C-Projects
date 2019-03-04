#include "PerfectPlayer.h"
#include <memory>
#include <algorithm>
#include <assert.h>
#include <iostream>


using namespace std;

PerfectPlayer::PerfectPlayer(Board::Player player):
Player(player), plan(), cur(nullptr)
{
    auto start = std:: make_shared<Node>(Board());
    
    playFromNode(start,Board::PLAYER_X);
    
    if(player == Board:: PLAYER_X){
        auto dummy = std::make_shared<Node>(Board());
        dummy -> winnerFromHere = start->winnerFromHere;
        dummy->children.push_back(start);
        plan = dummy;
    }
    else{
        plan = start;
    }
    
    cur = plan.get();
    
        
}



void playFromNode(std::shared_ptr<Node> n, Board::Player turn){

    Board :: Player otherTurn;
    Board :: Player mPlayer = turn;
    
//*********************BASE CASES *********************************//
    

   
    if(!n->board.movesRemain()){
        
        n->winnerFromHere = n->board.winner();

        return;
    }
    
//***************************************************************//
    
    for(int i=0;i<3;i++)
       
        for(int j=0;j<3;j++){
            
            if(n->board(i,j)== Board::EMPTY){
                
                auto next = n->board.move(i,j, mPlayer);
                
                n->children.push_back(std::make_shared<Node>(next));

                
            }
            
            otherTurn =  turn == Board::PLAYER_X ? Board :: PLAYER_O : Board :: PLAYER_X;
            
            
            

        }

    for(auto& child : n->children){
        
        playFromNode(child, otherTurn);
    }

    
    
    n->winnerFromHere = otherTurn;
    
    for(auto&child : n->children){
        
        if(child->winnerFromHere == turn){
           
            n->winnerFromHere = turn;
        }
        
        else if(child->winnerFromHere == Board :: EMPTY){
            
            if(n->winnerFromHere == otherTurn){
                
                n->winnerFromHere = Board::EMPTY;
            }
            
            
        }
    }
    
}
    


Board PerfectPlayer::move(Board board){
    
    auto next = std::find_if(cur->children.begin(), cur->children.end(), [&board](std::shared_ptr<Node> child) {
        
        
        //finds board in tree
        if(board == child->board){
            
            return true;
        }
        else{
            
            return false;
        }
        
    });
    
    assert(next != cur->children.end());
    
    std:: shared_ptr<Node> best = nullptr;
    
    for (auto& child : (*next)->children) {
        
        if(child->winnerFromHere == mPlayer){   //best move
            
            best = child;
        }
       
        
    }
    
    if(best == nullptr){
        
        for(auto& child : (*next)->children){
            
            if(child->winnerFromHere == Board:: EMPTY){    //defensive
                
                best = child;
                
            }
        }
    
    }
    
    if(best == nullptr){
        
        best = (*next)->children[0];   //losing no matter what
    }
        
    cur = best.get();
    
    
    return best->board;

    
  
}

