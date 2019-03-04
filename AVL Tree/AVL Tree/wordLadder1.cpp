//
//  wordLadder1.cpp
//  AVL Tree
//
//  Created by Aaron Adams on 10/12/16.
//  Copyright © 2016 Aaron Adams. All rights reserved.
//

#include "wordLadder1.h"

using namespace std;



void LinkedList:: nextTier1(vector<string>& dictionary, LinkedList& queue, string finalWord){
    
    
    vector<bool> usedWords;
    
    for(int i = 0; i < dictionary.size(); ++i){
        usedWords.push_back(false);
    }
    
    
    int enqueued = 0;
    int dequeued = 0;
    bool done = false;
    
    shared_ptr<Node> temp = head;
    
    string endingWord;
    
    
    endingWord = finalWord;
    
    
    
    while(temp != nullptr){
        
        for(int i = 0; i < temp->ladder1.size(); ++i){
            
            
            
            compare1(dictionary, temp->ladder1[i], temp->ladder1,  queue, endingWord, usedWords, enqueued, dequeued);
            
            done = isItDone1(queue,temp->ladder1, endingWord, enqueued, dequeued);
            
            
            if (done == true){
                return;
            }
            
            
            temp = temp->next;
            dequeued++;
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    
}






void LinkedList:: compare1(vector<string>& dictionary, string word, vector<string> ladder, LinkedList& queue, string endingWord, vector<bool>& usedWords, int& enqueued, int& dequeued){
    
    vector<string> dictionaryCopy = dictionary;
    
    // string done = "false";
    
    string tempWord = ladder.back();
    
    
    vector<string> newWordLadder = ladder;
    
    
    
    
    
    vector<char> aZ = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    for(int i = 0; i< word.size(); ++i){
        for(int j = 0; j < aZ.size(); ++j){      //changing letter by letter all combos
            tempWord[i] = aZ[j];
            
            
            int low = 0;
            int high = dictionary.size() - 1;
            
            
            
            
            while(low <= high){
                
                int mid = (low + high)/2;
                
                
                if(tempWord == dictionaryCopy[mid]){
                    
                    
                    if(tempWord != word && usedWords[mid] == false){
                        
                        
                        newWordLadder.push_back(tempWord);
                        
                        queue.append1(newWordLadder, endingWord);
                        enqueued++;
                        
                        usedWords[mid] = true;
                        
                        
                        
                        newWordLadder = ladder;
                        
                    }
                    
                    break;
                    
                }
                
                
                if(tempWord < dictionaryCopy[mid]){
                    
                    high = mid -1;
                }
                
                else{
                    
                    
                    low = mid + 1;
                    
                }
            }
        }
        
        
        
        tempWord = word;
    }
    if(head != nullptr){
        head = head->next;
    }
    
    if(head!=nullptr){
        head->prev = nullptr;
    }
    return;
}

















void LinkedList :: append1(vector<string> wordLadder, string endWord){
    
    shared_ptr<Node> temp = make_shared<Node>();
    
    
    temp->ladder1 = wordLadder;
    temp->next = nullptr;
    
    if(head == nullptr) { // empty list becomes the new node
        head = temp;
        tail = temp;
        temp->prev = nullptr;
        return;
    }
    else { // find last and link the new node
        
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
//give tail it's score or priority
        tail->priority = priority(wordLadder, endWord);
    }
    
}



int LinkedList :: priority(vector<string> ladder, string endWord){
    int score = 0;
    for(int i = 0; i < ladder[0].size(); ++i){
        score++;
    }
    for(int i = 0; i< ladder[0].size(); ++i){
        if(ladder.back()[i] == endWord[i]){
            score--;
        }
    }
    
    return score;
}





bool LinkedList:: isItDone1(LinkedList& queue,vector<string> tempLadder, string endingWord, int enqueued, int dequeued){
    
    string tempWord;
    
    
    shared_ptr<Node> temp = head;
    
    
    while(temp != nullptr){
        
        
        tempWord = temp->ladder1.back();
        
        if(tempWord == endingWord){
            int ladderSize = 0;
            cout << "Method: Queue" << endl << endl;
            cout << "[";
            for(int i = 0; i < temp->ladder1.size(); ++i){
                cout << temp->ladder1[i] << ", ";
                ladderSize++;
            }
            cout << "]"<< endl;
            
            cout << "Ladder size: " << ladderSize << endl;
            cout << "ladders enqueued: " << enqueued << endl;
            cout << "ladders dequeued: " << dequeued << endl << endl;

            return true;
        }
        
        temp = temp->next;
        
    }
    return false;
}

