//
//  main.cpp
//  Hashing
//
//  Created by Aaron Adams on 10/20/16.
//  Copyright © 2016 Aaron Adams. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "hashTable.hpp"




using namespace std;

class Pair{
public:
    string word;
    int ct;
    Pair(string w = "no word", int c = 0){
        word = w;
        ct = c;
    }
    string toString(){
        stringstream ss;
        ss << word << " " << ct;
        return ss.str();
    }
};


int main (){
    
    string word; char x; HashTable<string, Pair> myhash;
    
    ifstream fin;
    
    fin.open("game0.txt"); while (fin >> word){
        Pair * p = myhash.find(word);
        if (p ==NULL) myhash.insert(word, new Pair(word, 1));
        else {
            cout << word << " already there\n"; p->ct++;
        }
        
    } cout << myhash.toString() << endl;
    
    
    //Default hashtable viewing and score getting is set to the first 50 values in the hash table
    //To change it edit the howMany value in the following functons in the .hpp file: toString, getScore, get letterScore, and  getLength
    //The value should be the same in each
    
    
   //RUN BOTH OF THESE BEFORE OBATAINING SCORES SO THE LENGTH AND LETTER SCORES CAN BE DETERMINED FIRST
    myhash.getLetterScore();
    myhash.getLength();

    cout  << endl;
    cout << "Scores" << endl;
    myhash.getScore();
    
    myhash.itemsInTable();

    myhash.findsAndProbes();
    
    //OTHER TESTS
    
//    string boss = "boss";
//    cout << endl << "deleting boss" << endl;
//    if(myhash.remove(boss) == false){
//        cout << "didn't delete anything" << endl;
//    }
//    else{
//        cout << "deleted" << endl;
//    }
//    
//    cout << endl << "finding queue" << endl;
//    cout << myhash.find("queue") << endl;
//    
//    cout << endl << "making empty..." << endl;
//    myhash.makeEmpty();
//    
//    cout << myhash.toString();
//    myhash.getLength();
    
    
    
    return 0;
}
