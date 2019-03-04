//
//  main.cpp
//  CS3- Program 2 - Recursion
//
//  Created by Aaron Adams on 9/20/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//
#include"wordTree.h"
#include <iostream>
#include<fstream>

using namespace std;

int main() {
    
    
    wordTree wordTree;
    string word;
    int subtreeCount;
    ifstream inFile;
    
    inFile.open("prog2In.txt");
    if (!inFile) {
        cout << "Unable to open text file";
    }
    
    while (inFile >> word) {
        
        inFile >> subtreeCount;
        
        wordTree.preorderBuild(word, subtreeCount);
    }
    
    inFile.close();
    
    
    wordTree.find("mops");
    
    cout << endl << "getting tree height... " << endl << endl;

    
    int levelCt = 0;
    wordTree.treeHeight(wordTree.root, wordTree.root, levelCt);

    cout << endl << "printing tree.." << endl << endl;
    
    wordTree.printInOrder(wordTree.root);
    
    cout << endl << "toPreOrder:" << endl;

    string word1 = " ";
    
    wordTree.toPreOrder(wordTree.root, word1);
    
    node* newNode = NULL;
    
    cout << endl << "performing deep copy..." << endl << endl;
    
    wordTree.cloneTree(wordTree.root, newNode);
    
    cout << "executing upCase" << endl << endl;
    
    wordTree.upCase(wordTree.root);
    
    cout << endl << "re-printing..." << endl << endl;
    wordTree.printInOrder(wordTree.root);

    
    cout << endl << "couting leaves" << endl;
    int leafCt = 0;
    cout << wordTree.fringe(wordTree.root, leafCt) << endl;
    
    
    int level;
    int nodesCt = 0;
    cout << "choose what level to check: " << endl;
    cin >>level;
    cout << endl << "the are ";
    cout << wordTree.nodesInLevel(wordTree.root, level, nodesCt);
    cout << " nodes at level " << level << endl;
    
    string w1, w2;
    
    cout << "Least Common Ancestor: " << endl;
    cout << "enter in first word: " << endl;
    cin >> w1;
    cout << "enter in second word" << endl;
    cin >> w2;
    
    cout << wordTree.leastCommonAncestor(wordTree.root, w1, w2) << endl;
    
    
    cout << endl << "deleting tree..." << endl;
    wordTree.makeEmpty();
   
    return 0;
}
