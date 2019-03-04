#ifndef _PERFECT_PLAYER_
#define _PERFECT_PLAYER_

#include "Player.h"
#include <functional>
#include <vector>



    struct Node{
        
        Node(Board b) :board(b), winnerFromHere(), children(){}
        
        Board board;
        Board:: Player winnerFromHere;
        std::vector<std::shared_ptr<Node>> children;
        
    };
    
    
    void playFromNode(std::shared_ptr<Node> n, Board::Player turn);
    

class PerfectPlayer:public Player{

public:
    
    std:: shared_ptr<Node> head;
    
  PerfectPlayer(Board::Player);
  virtual Board move(Board board);
 
private:
    std::shared_ptr<Node> plan;
    Node*cur;
};

#endif
