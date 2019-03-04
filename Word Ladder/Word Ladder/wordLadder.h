//
//  wordLadder.h
//  Word Ladder
//
//  Created by Aaron Adams on 9/6/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//

#ifndef Word_Ladder_wordLadder_h
#define Word_Ladder_wordLadder_h
#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include<vector>
using namespace std;


class LinkedList{
    
protected:
    struct Node{
        
         vector <string> ladder1;
        
        shared_ptr<Node> next;
        
        shared_ptr<Node> prev;
        
        
        Node(vector<string> t) :ladder1(t), next(nullptr), prev(nullptr){}
        
        Node(vector <string>t, shared_ptr<Node> next, shared_ptr<Node> prev) : ladder1(t), next(nullptr), prev(nullptr){}

        Node(): ladder1(), next(nullptr), prev(nullptr){}
        
    };
    
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;
    

    
    
public:
    void append1(vector<string> word);
    void compare1(vector<string>& dictionary, string words, vector<string> ladder, LinkedList& queue, string endingWord, vector<bool>& usedWords);
    void nextTier1(vector<string>& dictionary, LinkedList& queue, string finalWord);
    bool isItDone1(LinkedList& queue,vector<string> tempLadder, string endingWord);
};
#endif
