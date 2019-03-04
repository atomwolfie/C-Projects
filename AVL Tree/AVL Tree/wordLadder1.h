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
        int priority;
        
        shared_ptr<Node> next;
        shared_ptr<Node> prev;
        
        
        Node(vector<string> t) :ladder1(t), priority(0), next(nullptr), prev(nullptr){}
        
        Node(vector <string>t, shared_ptr<Node> next, shared_ptr<Node> prev) : ladder1(t), priority(0), next(nullptr), prev(nullptr){}
        
        Node(): ladder1(), priority(0), next(nullptr), prev(nullptr){}
        
    };
    
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;
    
    
    
    
public:
    void append1(vector<string> word, string endWord);
    void compare1(vector<string>& dictionary, string words, vector<string> ladder, LinkedList& queue, string endingWord, vector<bool>& usedWords, int& enqueued, int& dequeued);
    void nextTier1(vector<string>& dictionary, LinkedList& queue, string finalWord);
    bool isItDone1(LinkedList& queue,vector<string> tempLadder, string endingWord, int enqueued, int dequeued);
    int priority(vector<string> ladder, string endWord);

};
#endif
