//
//  main.cpp
//  Word Ladder
//
//  Created by Aaron Adams on 9/6/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//

//#include <iostream>
//#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "wordLadder1.h"
#include "avlTreeTemplate.h"
//#include "wordLadder1.cpp"


using namespace std;

int inDictionary (vector<string>, string);

int main(int argc, const char * argv[]) {
    
    vector<string> dictionary;
    string word;
    
    
    
    ifstream myfile("dictionary.txt");
    
    
    copy(istream_iterator<string>(myfile),
         
         istream_iterator<string>(),
         
         back_inserter(dictionary));
    
    try {
        
        cout << "Dictionary created " << endl << endl;
        
        cout << "The size of your dictionary is: " << dictionary.size() << endl << endl;
        
    } catch(...) {
        
        cout << "Data Unavailable\n Cannot find dictionary.txt";
    }
    
    
    
    string startingWord;
    string endingWord;
    
    
    
    cout << "dictionary test" << endl;
    for(int i = 0; i < 10; ++i){
        cout << dictionary[i] << endl;
        
    }
    cout << endl;
    
    
//--------------------------------------------------------------------------------------//
    
    //TREE
//    AvlTree<string> tree;
//    startingWord = "oops";
//    endingWord = "pops";
//    cout << "oops --> pops" << endl;
//    vector<string> startingVector = {startingWord};
//    tree.insert(startingVector, endingWord);
//    tree.theWork(dictionary, endingWord);
//    tree.toString();
//    cout << endl << endl << endl << endl;
//    
//QUEUE
//    LinkedList queue;
//        string queueWord = "oops";
//        string endingQueueWord = "pops";
//        cout << endl <<  "oops --> pops" << endl << endl;
//        vector<string> queueVector = {queueWord};
//        queue.append1(queueVector);
//        queue.nextTier1(dictionary, queue, endingQueueWord);
    //--------------------------------------------------------------------------------------//
    
    
    
    
    
    
//--------------------------------------------------------------------------------------//
//TREE1
//    AvlTree<string> tree1;
//    
//    string startingWord1 = "kiss";
//    string endingWord1 = "woof";
//    cout << "kiss --> woof" << endl;
//    vector<string> startingVector1 = {startingWord1};
//    
//    
//    tree1.insert(startingVector1, endingWord1);
//    tree1.theWork(dictionary, endingWord1);
//    tree1.toString();
//    cout << endl << endl << endl << endl;

//QUEUE 1
//    LinkedList queue1;
//    string queueWord1 = "kiss";
//    string endingQueueWord1 = "woof";
//    cout << endl <<  "kiss --> woof" << endl << endl;
//    vector<string> queueVector1 = {queueWord1};
//    queue1.append1(queueVector1);
//    queue1.nextTier1(dictionary, queue1, endingQueueWord1);
//--------------------------------------------------------------------------------------//
    
    
    
//--------------------------------------------------------------------------------------//
//TREE2
//    AvlTree<string> tree2;
//    
//    string startingWord2 = "cock";
//    string endingWord2 = "numb";
//    cout << "cock --> numb" << endl;
//    vector<string> startingVector2 = {startingWord2};
//    
//    
//    tree2.insert(startingVector2, endingWord2);
//    tree2.theWork(dictionary, endingWord2);
//    tree2.toString();
//    cout << endl << endl << endl << endl;

//    QUEUE2
//    LinkedList queue2;
//    string queueWord2 = "cock";
//    string endingQueueWord2 = "numb";
//    cout << endl <<  "cock --> numb" << endl << endl;
//    vector<string> queueVector2 = {queueWord2};
//    queue2.append1(queueVector2);
//    queue2.nextTier1(dictionary, queue2, endingQueueWord2);
//--------------------------------------------------------------------------------------//

    
    
    
    
    
//--------------------------------------------------------------------------------------//
//TREE3
//    AvlTree<string> tree3;
//    
//    string startingWord3 = "jura";
//    string endingWord3 = "such";
//    cout << "jura --> such" << endl;
//    vector<string> startingVector3 = {startingWord3};
//    
//    
//    tree3.insert(startingVector3, endingWord3);
//    tree3.theWork(dictionary, endingWord3);
//    tree3.toString();
//    cout << endl << endl << endl << endl;
   
        //QUEUE3
//        LinkedList queue3;
//        string queueWord3 = "jura";
//        string endingQueueWord3 = "such";
//        cout << endl <<  "jura --> such" << endl << endl;
//        vector<string> queueVector3 = {queueWord3};
//        queue3.append1(queueVector3);
//        queue3.nextTier1(dictionary, queue3, endingQueueWord3);

//---------------------------------------------------------------------------------------------//
    
    
    //---------------------------------------------------------------------------------------------//
//TREE4
    AvlTree<string> tree4;
    
    string startingWord4 = "stet";
    string endingWord4 = "whey";
    cout << "stet --> whey" << endl;
    vector<string> startingVector4 = {startingWord4};
    
    
    tree4.insert(startingVector4, endingWord4);
    tree4.theWork(dictionary, endingWord4);
    tree4.toString();
    cout << endl << endl << endl << endl;
    
//QUEUE4
    LinkedList queue4;
    string queueWord4 = "stet";
    string endingQueueWord4 = "whey";
    cout << endl <<  "stet --> whey" << endl << endl;
    vector<string> queueVector4 = {queueWord4};
    queue4.append1(queueVector4, endingQueueWord4);
    queue4.nextTier1(dictionary, queue4, endingQueueWord4);
    //---------------------------------------------------------------------------------------------//
    
    
    
    
    
    
    
//---------------------------------------------------------------------------------------------//
//TREE 5
//    AvlTree<string> tree5;
//    
//    string startingWord5 = "swag";
//    string endingWord5 = "boss";
//    cout << "swag --> boss" << endl;
//    vector<string> startingVector5 = {startingWord5};
//    
//    
//    tree5.insert(startingVector5, endingWord5);
//    tree5.theWork(dictionary, endingWord5);
//    tree5.toString();
//    cout << endl << endl << endl << endl;
    
//QUEUE5
//    LinkedList queue5;
//    string queueWord5 = "swag";
//    string endingQueueWord5 = "boss";
//    cout << endl <<  "swag --> boss" << endl << endl;
//    vector<string> queueVector5 = {queueWord5};
//    queue5.append1(queueVector5);
//    queue5.nextTier1(dictionary, queue5, endingQueueWord5);
//---------------------------------------------------------------------------------------------//
    
    
    return 0;
}
