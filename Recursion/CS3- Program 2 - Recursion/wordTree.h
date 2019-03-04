//
//  wordTree.h
//  CS3- Program 2 - Recursion
//
//  Created by Aaron Adams on 9/20/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//

#include<string>
#include<vector>

using namespace std;

struct node{
    
    string word;
    int siblingCount;
    int level;
    node *left;
    node *right;
};



class wordTree{
public:
    wordTree();
    ~wordTree();
    
    void preorderBuild(string word, int siblingCount);
    void find(string word);
    void makeEmpty();
    void printInOrder(node *root);
    int maxKids(node *root);
    string toPreOrder(node *root, string& word);
    void cloneTree(node* root, node* &copiedNode);
    void upCase(node* &root);
    int fringe(node* root, int& leafCt);
    int nodesInLevel(node* root,int leveldesired, int& nodesCt);
    void treeHeight(node* &root, node* node, int levelCt);
    bool findPath(node* root, vector<string> &path, string k);
    string leastCommonAncestor(node *root, string w1, string w2);
    node *root;

private:
    void makeEmpty(node *&child);
    void preorderBuild(string word, int siblingCount,node *child);
    void find(string word, node *child);
    
    
   // node *root;
};

















#ifndef CS3__Program_2___Recursion_wordTree_h
#define CS3__Program_2___Recursion_wordTree_h


#endif
