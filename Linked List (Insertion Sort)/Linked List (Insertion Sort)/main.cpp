//
//  main.cpp
//  Linked List (Insertion Sort)
//
//  Created by Aaron Adams on 10/19/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#include <iostream>
#include <memory>
#include <functional>


using namespace std;


template <typename T>
class LinkedList{

protected:
    struct Node{
    
        T data;
    
        shared_ptr<Node> next;
    
        Node(T t) :data(t), next(nullptr){}
        
    };
    shared_ptr<Node> head;

public:
    
    LinkedList& operator=(Node& list){   //deep copy
    
        if (list == NULL) return NULL;
        
        auto result = new Node;
        result->value = list->value;
        result->next = Clone(list->next);
        return result;
    
    }
    
    LinkedList& operator=(Node&& list){    //shallow copy
        
        if (list == NULL) return NULL;

        auto cloneHead = head;
        
        
        
        
    }
    
    
    void insert(T data);
    void remove(T data);
    void size();
    void print();
    void printSquare();
    
    template <typename F>
    
    void forEach(F func){
        
        int i = 0;
        
        auto current = head;
        
        while(current){
            
            cout << "Node("<< i << ")";
            ++i;
            
            func(current->data);
            
            current = current->next;
            
        }
        
    }

    
};









void printSquare(int i){
    
    cout << " data squared " << i*i << endl;
    
}




int main() {

    
    
    LinkedList<int> list;
    LinkedList<int> list2;
    
    list.print();
    list.insert(5);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.insert(4);
    list.insert(4);
    list.insert(6);
    list.print();
    list.remove(1);
    list.remove(6);
    list.remove(4);   //remove recursively removes all nodes with same data value
    
    list.size();
    list.print();
    
    list.forEach(printSquare);
    
    LinkedList<string> l2;
    
    
    list2 = list;
    
    
    cout << "Copy of Linked List: ";
    
    list2.print();    //Deep Copy of LinkedList
    
    
    
    return 0;
}






//-----------------Functions--------------//

template <typename T>
void LinkedList<T> :: size(){
    
    auto current = head;
    int i = 0;
    
    while (current != nullptr){
        
        ++i;
        
        current = current->next;
    }
    
    cout << "Linked List size: " << i << endl;
}

//-------------------------------------//
template <typename T>
void LinkedList<T>:: print(){
    
    auto current = head;
    
    cout << "Linked List: ";
    
    while(current){
        
        cout << current->data << ". ";
        current = current->next;
        
    }
    
    cout << endl;
    
    
}

//-----------------------------------------//

template <typename T>

void LinkedList<T>:: remove(T data){
    
    auto realNode = make_shared<Node>(data);
    
    auto previous = head;
    
    auto current =  head->next;
    
    
    
    if(realNode->data == head->data){        //removes if it's the first number in list
        
        head = current;
        head->next = current->next;
        return;
        
        cout << "Removed: " << data << " from linked list " << endl;
    }
    
    else{
        
        
        while(current->next != nullptr){    //traverses
            
            previous = current;
            current = current->next;
            
            if(realNode->data == current->data){
                
                previous->next = current->next;
                
                cout << "Removing: " << data << " from Linked List" << endl;
                
                remove(data);
                
                //does recursion in the case that there are multiple nodes of the same value
                return;
                
            }
        }
        
        return;      //if it didn't find anything
    }
}


//------------------------------------------------//


template <typename T>

void LinkedList<T>::insert(T data){
    
    cout << "Inserting: " << data << " into Linked List  " << endl;
    
    if(head == nullptr){                       //base case if head has nothing
        
        head = make_shared<Node>(data);
        
        return;
    }
    
    auto previous = head;
    
    auto current =  head->next;
    
    auto realNode = make_shared<Node>(data);     //actual new node getting put in
    
    
    if(realNode->data < previous->data){          //base case if new node needs to be first
        
        auto tempNode = make_shared<Node>(data);
        
        tempNode->next = head;
        head = tempNode;
        
        previous = tempNode;
        current = tempNode->next;
        
    }
    
    else
    {
        
        while(current!=nullptr&&current->next != nullptr){
            
            previous = current;
            current = current->next;
            
            if(realNode->data < current->data){
                
                auto tempNode = make_shared<Node>(data);
                
                previous->next = tempNode;
                
                tempNode->next = current;
                
                return;
                
            }
            
        }
        
        auto tempNode = make_shared<Node>(data);
        
        
        tempNode->next = nullptr;
        current->next = tempNode;
        return;
        
    }
    
}


