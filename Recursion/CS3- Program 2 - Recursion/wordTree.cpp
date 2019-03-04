//
//  wordTree.cpp
//  CS3- Program 2 - Recursion
//
//  Created by Aaron Adams on 9/20/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//

#include "wordTree.h"
#include <iostream>
wordTree::wordTree(){
    root=NULL;
}


//was written to compare numbers, will need to be altered to simply build insertings Nodes of strings
void wordTree::preorderBuild(string key, int siblingCount, node *child){
    
    
    if(key[0] == child->word[0]){
        if(child->left != NULL)
            preorderBuild(key, siblingCount, child->left);
        else{
            child->left = new node;
            child->left->word = key;
            child->left->siblingCount = siblingCount;
            child->left->left = NULL;    //Sets the left child of the child node to null
            child->left->right = NULL;   //Sets the right child of the child node to null
        }
    }
    else if(key[0] != child->word[0]){
        if(child->right!= NULL)
            preorderBuild(key, siblingCount, child->right);
        else{
            child->right=new node;
            child->right->word = key;
            child->right->siblingCount = siblingCount;
            child->right->left=NULL;  //Sets the left child of the child node to null
            child->right->right=NULL; //Sets the right child of the child node to null
        }
    }
}

void wordTree::preorderBuild(string key, int siblingCount)
{
    if(root!=NULL)
        preorderBuild(key, siblingCount, root);
    else{
        root= new node;
        root->word = key;
        root->siblingCount = siblingCount;
        root->left=NULL;
        root->right=NULL;
    }
}



void wordTree::find(string key, node *child){
        
    if(child != NULL){
        if(key == child->word){
            cout << "Found the word!" << endl;
            cout << "word: " << child->word << endl;
            cout << "siblings: " << child->siblingCount << endl;
        }
        else
             find(key, child->left);
             find(key, child->right);
    }
    
}

void wordTree:: find(string key){
     find(key, root);
}





wordTree:: ~wordTree(){
    makeEmpty();
}

void wordTree:: makeEmpty(node *&child){
    
    if(child == NULL){
        return;
    }
        makeEmpty(child->left);
        makeEmpty(child->right);
        cout << "deleting " << child->word <<endl;
        child = NULL;
        delete child;
   
}

void wordTree:: makeEmpty(){
    makeEmpty(root);
}



/* Given a binary tree, print its nodes in inorder*/
void wordTree:: printInOrder(struct node* node){
    
    if (node == NULL){
        return;
    }
    
    for(int i = 0; i < node->level; ++i){
        
        if(node == root){
            break;
        }
        
        cout << "  ";
    }
    
    cout << node->word << " [" << node->siblingCount << ": " << maxKids(node) << "]" <<endl;
    
    /* first recur on left child */
    printInOrder(node->left);
    
    /* now recur on right child */
    printInOrder(node->right);
}



int wordTree :: maxKids(node *node1){
    
    int kidCt = 0;
    
    if(node1 == NULL) return 0;
    
    for(node* kid = node1->left; kid != NULL; kid = kid->right){
                
            kidCt++;
        kidCt += maxKids(kid);
       
        }
    return kidCt;
}


string wordTree:: toPreOrder(node *node, string& word){
            
    if(node == NULL){
        return "No tree found";
    }
    
    word += node->word;
    word += " ";
    toPreOrder(node->left, word);
    toPreOrder(node->right, word);
    cout << "Returning: " <<  word << endl;

    
    return word;
}

void wordTree:: cloneTree(node* root, node* &copiedNode){
    
    if (root == NULL){
        copiedNode = NULL;
    }
    else{
        copiedNode = new node;
        copiedNode->word = root->word;
        cloneTree(root->left, copiedNode->left);
        cloneTree(root->right, copiedNode->right);
    }
  
}


void wordTree:: upCase(node *&node){
    
    if(node == NULL){
        return;
    }
    
    node->word[0] = toupper(node->word[0]);
    cout << node->word << endl;
    upCase(node->left);
    upCase(node->right);
    
}


int wordTree:: fringe(node *root, int& leafCt){
        
    if(root == NULL) return 0;
    
    if(root->left == NULL && root->right == NULL){
        
        leafCt++;
        cout << "+1" << endl;
    }
    fringe(root->left, leafCt);
    fringe(root->right, leafCt);
    
    
    return leafCt;
    
}


int wordTree:: nodesInLevel(node *root,int leveldesired, int& nodesCt){
    
    if(root == NULL){
        return 0;
    }
    
    
    else if(leveldesired == 0){
        return 1;
    }
    
    if(leveldesired == root->level){
        nodesCt++;
    }
    nodesInLevel(root->left, leveldesired, nodesCt);
    nodesInLevel(root->right, leveldesired, nodesCt);
    
    return nodesCt;
}

void wordTree:: treeHeight(node *&root, node* node, int levelCt){
    
    if(root == NULL){
        return;
    }
    
    levelCt = 0;
    
    for(int i = 0; i < root->word.length(); ++i){
        if(root->word[i] != node->word[i]){
            ++levelCt;
            root->level = levelCt;
        }
    }
    treeHeight(root->left, node,  levelCt);
    treeHeight(root->right, node, levelCt);
    
}

bool wordTree:: findPath(node *root, vector<string> &path, string k){
    
    // base case
    if (root == NULL) return false;
    
    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root->word);
    
    // See if the k is same as root's key
    if (root->word == k)
        return true;
    
    // Check if k is found in left or right sub-tree
    if ( (root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)) )
        return true;
    
    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
    
}

string wordTree:: leastCommonAncestor(node *root, string w1, string w2){
    
    // to store paths to n1 and n2 from the root
    vector<string> path1, path2;
    
    // Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return -1
    if ( !findPath(root, path1, w1) || !findPath(root, path2, w2)){
        return "Wut";
    }
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
    
    
}

