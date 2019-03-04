//
//  main.cpp
//  Let Me Guess
//
//  Created by Aaron Adams on 11/16/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#include <iostream>
#include <memory>
#include <functional>
#include <string>

using namespace std;


class LinkedListTree{


protected:

    
    struct Node{
        
    public :
        Node(string t) :data(t), left(nullptr), right(nullptr){};
        string data;
        std:: shared_ptr<Node>left;
        std:: shared_ptr<Node>right;
        virtual string ask(){return "Neither";};
        
        
        
    
    };
    
    
    struct Question:Node{
    
        Question(string t):Node(t){};
        
        string ask(){
            cout  << this->data << endl;
            string response;
            cin >> response;
            
            return response;
            
        }
    
    
    };
    
    struct Answer :public Node{
        
        Answer(string t):Node(t){};
        
        string ask(){
            cout << "I got it! Are you thinking of a " << this->data << "?    (Y or N)" <<endl;
            string response;
            cin >> response;
            return response;
            
            
        }
    };
    
  
    shared_ptr<Node> head;
    
    

public:
    string response;
    LinkedListTree(string intial){
        
        head = make_shared<Answer>(intial);
        
    }
    
    void replace(shared_ptr<Node>&);  //will use the other functions inside of it
    
    string WhatAreYouThinking();   //What were you acutally thinking about?
    
    string howCouldITell(); //gets new question
    
    void run();
    

};



string LinkedListTree ::  WhatAreYouThinking(){
    string response;
    
    cout << "What were you actually thinking about?" << endl;
    
    cin >> response;
    cin.ignore();
    
    
    return response;
}

string LinkedListTree:: howCouldITell(){

string response;

cout << "What should have I asked to get that? "<< endl;
    getline(cin,response);
   return response;
}


void LinkedListTree:: replace(shared_ptr<Node>& par){
    
    
    
    shared_ptr<Node> newAnswer = make_shared<Answer>(WhatAreYouThinking());
    shared_ptr<Node> newQuestion = make_shared<Question>(howCouldITell());
    
    
    newQuestion->left = newAnswer;
    newQuestion->right = par;
    
    par = newQuestion;
    
    
    
    
        return;
    }
   
    
    


//auto current = head;


void LinkedListTree:: run(){
    
    
    auto current = head;
    
    shared_ptr<Node> parent;
    
    
   
    
    
    
    while(current != nullptr){
        
        
        response = current->ask();
        
        if(response == "Y" || response == "y" || response == "Yes" || response == "yes" || response == "YES"){
            
            if(current->left == nullptr){   //means it was an asnswer node and at the end
                
                cout << "haha I guessed it!" << endl;
                return;
            }
            
            else{
                
                parent = current; //traverse left
                current = current->left;
                
                
            }
        }
        
        if(response == "N" || response == "n" || response == "No" || response == "no" || response == "NO"){
            
            if(current->right == nullptr  && current->left == nullptr){
                
                if(parent == nullptr){
                
                    replace(head);
                    return;
                }
                else{
                    
                    if(parent->left == current){
                        
                        replace(parent->left);
                    }
                    else{
                        replace(parent->right);
                        
                    }
                    
                    
                }
                return;
                
            }
            
            else{
                
                
                parent = current; //traverse to right
                current= current->right;
                
                
                
                
                
            }
            
        }
        
       
        
    }
    
}









int main() {
    
    LinkedListTree tree("flower");
    
    string response;
    
    
    do{
    
        tree.run();
        
        cout << "Do you want to continue? (enter Y)" << endl;
        cin >> response;
    }while(response == "Y" || response == "y" || response == "yes" || response == "Yes" || response == "YES");
    
    
    
    
   
    
    
    
    return 0;
}
