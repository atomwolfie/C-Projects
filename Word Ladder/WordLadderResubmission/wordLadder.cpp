//
//  wordLadder.cpp
//  Word Ladder
//
//  Created by Aaron Adams on 9/6/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//

#include "wordLadder.h"

using namespace std;



void LinkedList:: nextTier(vector<string>& dictionary, LinkedList& queue, string finalWord){
    
    
    vector<bool> usedWords;
    
    for(int i = 0; i < dictionary.size(); ++i){
        usedWords.push_back(false);
    }
    
    
    
    bool done = false;
    
    shared_ptr<Node> temp = head;

    string endingWord;
      
    
    endingWord = finalWord;
    
    
    
    while(temp != nullptr){
        
        for(int i = 0; i < temp->ladder.size(); ++i){
            
            
                
            compare(dictionary, temp->ladder[i], temp->ladder,  queue, endingWord, usedWords);
            
            done = isItDone(queue,temp->ladder, endingWord);
            
            
            if (done == true){
                
                
                return;
            }
            
         
            temp = temp->next;
            
        }
        

    }
    
   
    
    
    
    
    
    
    
    
}






 void LinkedList:: compare(vector<string>& dictionary, string word, vector<string> ladder, LinkedList& queue, string endingWord, vector<bool>& usedWords){
    
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
                    
                    queue.append(newWordLadder);
                    
                    
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

















void LinkedList :: append(vector<string> wordLadder){
    
shared_ptr<Node> temp = make_shared<Node>();
    
    
    temp->ladder = wordLadder;
    temp->next = nullptr;
    
    if(head == nullptr) { // empty list becomes the new node
        head = temp;
        tail = temp;
        temp->prev = nullptr;
        return;
    }
    else { // find last and link the new node
        
        //shared_ptr<Node> last = tail;
        
      
        
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        
    }
    
}





bool LinkedList:: isItDone(LinkedList& queue,vector<string> tempLadder, string endingWord){
    
    string tempWord;

    
    shared_ptr<Node> temp = head;

   
    while(temp != nullptr){
        
        
        tempWord = temp->ladder.back();
        
            if(tempWord == endingWord){
                cout << "ladder: " << endl;
                
                for(int i = 0; i < temp->ladder.size(); ++i){
                   cout << temp->ladder[i] << endl;
                }
                
                return true;
            }
        
        temp = temp->next;
        
    }
    return false;
}

