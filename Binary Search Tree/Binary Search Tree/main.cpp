//
//  main.cpp
//  Binary Search Tree
//
//  Created by Aaron Adams on 11/6/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>




template <typename T>
struct Node{
    
    Node(T t) :data(t), left(nullptr), right(nullptr){}
    T data;
    std:: shared_ptr<Node>left;
    std:: shared_ptr<Node>right;
    
};

//Tree rotation, right side
template <typename T>
void zig(std:: shared_ptr<Node<T>>& tree) {
    if(!tree) return;
    if(! tree->right) return;
    auto A = tree;
    tree = tree->right;
    A->right = tree->left;
    tree->left = A;
};

//Tree rotation, left side
template<typename T>
void zag(std:: shared_ptr<Node<T>>& tree){
    
    if(!tree) return;
    if(! tree->left) return;
    auto A = tree;
    tree = tree->left;
    A->left = tree->right;
    tree->right = A;
    
    
    
}





int main(int argc, const char * argv[]) {
    
    
    
    
    
    
    
    
    
    
    return 0;
}
