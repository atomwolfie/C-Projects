#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int nextPrime(int n);
bool isPrime(int n);


enum Status { ACTIVE, EMPTY, DELETED };

// We store two things.  The key itself and the record associated with the key.
// In our case, the HashKey will be the word.  The HashRecord will be a node containing the word (again) and the count.
// Note that you have to supply a toString for the HashRecord or you can't print the hash table.
template <typename HashKey, typename HashRecord>
class HashEntry
{
public:
    HashKey key;
    HashRecord * rec;
    Status info;
    int wordLength;
    int letterScore;
    int usedScore;
    int score;
    
    int numFinds;
    int numProbes;
    
    HashEntry(HashRecord * hr = NULL, const HashKey & e = HashKey(), Status i = EMPTY)
    : key( e ), rec( hr ), info( i ) { }
    
};


template <typename HashKey, typename HashRecord>
class HashTable
{
public:
    bool remove(const HashKey & x);
    bool isEmpty() { return activeElements == 0; }
    HashRecord * insert(const HashKey x, HashRecord * h);
    HashTable(int size = 977) : hashTable(nextPrime(size)){
        makeEmpty();
    };
    HashRecord *find(const HashKey & x);
    void makeEmpty();
    
    //Edit the howMany here, should always be equal
    string toString(int howMany = 50);
    void getLength(int howMany = 50);
    void getLetterScore(int howMany = 50);
    void getScore(int howMany = 50);
    void itemsInTable(int howMany = 50);
    void findsAndProbes(int howMany = 50);
    
private:
    vector<HashEntry<HashKey, HashRecord>> hashTable;
    int activeElements;
    bool isActive(int currentPos) const;
    //myhash is the original hash function
    size_t myhash(const HashKey & x) const;
    int findPos(const HashKey & x);
    void rehash();
    //this is the hash function I replaced myhash with
    unsigned int hashFunction(const HashKey & x) const;
};


template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>:: findsAndProbes(int howMany){
    int ct = 0;
    
    
    cout << "number of finds and probes of each entry: " << endl;
    for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++)
        if (hashTable[i].info == ACTIVE){
            
            cout << hashTable[i].rec->toString() << ", number of finds: " << hashTable[i].numFinds << endl;

            cout << hashTable[i].rec->toString() << ", number of probes: " << hashTable[i].numProbes << endl;
            ct++;
        }
    
}





template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>:: itemsInTable(int howMany){
    int ct = 0;
    
    for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++)
        if (hashTable[i].info == ACTIVE){
            ct++;
        }
    
    cout << endl << "There are " << ct << " number of entries in this hash table" << endl << endl;
}




//Computes the score of each hash entry
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::getScore(int howMany){
    
    int ct = 0;
    int score = 0;
    for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++){
        score = 0;
        
        if (hashTable[i].info == ACTIVE){
            
            score = hashTable[i].wordLength * hashTable[i].letterScore * hashTable[i].usedScore;
            hashTable[i].score = score;
            cout  << hashTable[i].rec->toString() << ", score: " << hashTable[i].score << endl;

            ct++;
        }
        
    }
}







//gets leeter score in a hash entry
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::getLetterScore(int howMany){
    int ct = 0;
    int letterCount;
    for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++){
        letterCount = 0;
        if (hashTable[i].info == ACTIVE){
            string word = hashTable[i].rec->toString();
            
            for(int j = 0; j < word.length() - 2; j++){
                if(word[j] == 'a'){
                    letterCount += 1;
                }
                 if(word[j] == 'b'){
                    letterCount += 3;
                }
                 if(word[j] == 'c'){
                    letterCount += 3;
                }
                 if(word[j] == 'd'){
                    letterCount += 2;
                }
                 if(word[j] == 'e'){
                    letterCount += 1;
                }
                 if(word[j] == 'f'){
                    letterCount += 4;
                }
                 if(word[j] == 'g'){
                    letterCount += 2;
                }
                 if(word[j] == 'h'){
                    letterCount += 4;
                }
                 if(word[j] == 'i'){
                    letterCount += 1;
                }
                 if(word[j] == 'j'){
                    letterCount += 8;
                }
                 if(word[j] == 'k'){
                    letterCount += 5;
                }
                 if(word[j] == 'l'){
                    letterCount += 1;
                }
                 if(word[j] == 'm'){
                    letterCount += 3;
                }
                 if(word[j] == 'n'){
                    letterCount += 1;
                }
                 if(word[j] == 'o'){
                    letterCount += 1;
                }
                 if(word[j] == 'p'){
                    letterCount += 3;
                }
                 if(word[j] == 'q'){
                    letterCount += 10;
                }
                 if(word[j] == 'r'){
                    letterCount += 1;
                }
                 if(word[j] == 's'){
                    letterCount += 1;
                }
                 if(word[j] == 't'){
                    letterCount += 1;
                }
                 if(word[j] == 'u'){
                    letterCount += 1;
                }
                 if(word[j] == 'v'){
                    letterCount += 4;
                }
                 if(word[j] == 'w'){
                    letterCount += 4;
                }
                 if(word[j] == 'x'){
                    letterCount += 8;
                }
                 if(word[j] == 'y'){
                    letterCount += 4;
                }
                 if(word[j] == 'z'){
                    letterCount += 10;
                }
            }
            
            hashTable[i].letterScore = letterCount;
           // cout << word << ", letterscores: " << hashTable[i].letterScore << endl;
            ct++;
        }
        
    }
}




//gives each kay the length of the word it contains
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::getLength(int howMany){
    int ct = 0;
    int wordLength = 0;
    
    for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++){
        wordLength = 0;
        if (hashTable[i].info == ACTIVE){
            
            string word = hashTable[i].rec->toString();
            
            for (int j = 0; j < word.length(); j++){
                wordLength++;
            }
                        
            if(wordLength - 2 < 3){
                hashTable[i].wordLength = 0;
            }
            if(wordLength - 2 == 3){
                hashTable[i].wordLength = 1;
            }
            if(wordLength - 2 == 4){
                hashTable[i].wordLength = 2;
            }
            if(wordLength - 2 == 5){
                hashTable[i].wordLength = 3;
            }
            if(wordLength - 2 == 6){
                hashTable[i].wordLength = 4;
            }
            if(wordLength - 2 == 7){
                hashTable[i].wordLength = 5;
            }
            if(wordLength - 2 >= 8){
                hashTable[i].wordLength = 6;
            }
            //cout << word << ", length Value: " << hashTable[i].wordLength << endl;
            ct++;
        }
    }
}




// Convert the Hash table to a string.  Since the hashtablel is large, HowMany indicates how many entries will be displayed.
template <typename HashKey, typename HashRecord>
string HashTable<HashKey, HashRecord>::toString(int howMany){
    int ct = 0;
    stringstream ss;
    ss << "Current size of table: " << hashTable.size() << endl;
    for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++)
        if (hashTable[i].info == ACTIVE){
            ss << hashTable[i].rec->toString() << " ";
            
            ct++;
        }
    return ss.str();
}

// return the subscript where x is located in the hash table.
// Quadratic probing is used.  Can you figure out why this implements quadratic probing?
template <typename HashKey, typename HashRecord>
int HashTable<HashKey, HashRecord>::findPos(const HashKey & x)
{
    
    
    int numProbes = 0;
    int offset = 1;
//  int currentPos1 = myhash(x);
    int currentPos = hashFunction(x);
    hashTable[currentPos].numFinds =  hashTable[currentPos].numFinds + 1;

    while (hashTable[currentPos].info != EMPTY &&
           hashTable[currentPos].key != x){
        numProbes++;
        hashTable[currentPos].numProbes = numProbes;

        currentPos += offset;  // Compute ith probe
        offset += 2;
        if (currentPos >= (int)hashTable.size()){    // Cheaper than  mod
            currentPos -= hashTable.size();
        }
    }
    
    return currentPos;
};

// Remove all elements of the table by setting status to empty.
// Have you seen the range based loop for accessing elements of a vector?
// for (auto &entry:hashTable) says, let a reference variable "entry" iterate through all entries of the hashTable vector
// The "auto" part says to figure out the type of the element automatically (based on what is passed in).
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::makeEmpty()
{
    activeElements = 0;
    for (auto & entry : hashTable)
        entry.info = EMPTY;
};

// Create a new hashtable which is at least twice as large as the current size.
// Actually, rehashing can make the table smaller (if entries have been removed), but this isn't considered here.
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::rehash()
{
    vector<HashEntry <HashKey, HashRecord>> oldhashTable = hashTable;
    
    // Create new double-sized, empty table
    hashTable.resize(nextPrime(2 * oldhashTable.size()));
    for (auto & entry : hashTable)
        entry.info = EMPTY;
    
    // Copy table over
    activeElements = 0;
    for (auto & entry : oldhashTable)
        if (entry.info == ACTIVE)
            insert(entry.key, entry.rec);
    
};

// Return true if given entry is active.
template <typename HashKey, typename HashRecord>
bool HashTable<HashKey, HashRecord>::isActive(int currentPos) const
{
    return hashTable[currentPos].info == ACTIVE;
};

// use built=in hash functions to find a location.
template<typename HashKey, typename HashRecord>
size_t HashTable<HashKey, HashRecord>::myhash(const HashKey & x) const
{
    static hash<HashKey> hf;
    return hf(x) % hashTable.size();
};




//MY REWITTEN HASH Function--------------------------------------------------------------//
template<typename HashKey, typename HashRecord>
unsigned int HashTable<HashKey, HashRecord>:: hashFunction(const HashKey & x) const
{
    //static hash<HashKey> hf;
    //return hf(x) % hashTable.size();
    
    unsigned int hash = 0;
    for(size_t i = 0; i < x.length(); i++){
        hash = hash << 7 ^ x[i];
    }
    
    return hash % hashTable.size();
    
};
//-------------------------------------------------------------------------------------//







// Use lazy deletion to remove an element
// Return boolean to indicate success of operation
template <typename HashKey, typename HashRecord>
bool HashTable<HashKey, HashRecord>::remove(const HashKey & x)
{
    int currentPos = findPos(x);
    if (!isActive(currentPos))
        return false;
    
    hashTable[currentPos].info = DELETED;
    return true;
};

// Insert item with key x and record pointer h into the hash table.
template<typename HashKey, typename HashRecord>
HashRecord * HashTable<HashKey, HashRecord>::insert(const HashKey x, HashRecord * h){
    int repititionCt = h->ct - 1;
    //hashTable[currentPos].usedScore = h->ct;
    
    // Insert x as active
    int currentPos = findPos(x);
    if (isActive(currentPos))
        return NULL;
    
    hashTable[currentPos].key = x;
    hashTable[currentPos].rec = h;
    if(repititionCt == 0){
        hashTable[currentPos].usedScore = 5;
    }
    else if(repititionCt == 1 || repititionCt == 2 || repititionCt == 3){
        hashTable[currentPos].usedScore = 4;
    }
    else if(repititionCt == 4 || repititionCt == 5 || repititionCt == 6){
        hashTable[currentPos].usedScore = 3;
    }
    else if(repititionCt == 7 || repititionCt == 8 || repititionCt == 9){
        hashTable[currentPos].usedScore = 2;
    }
    else{
        hashTable[currentPos].usedScore = 1;
    }
    hashTable[currentPos].info = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++activeElements > (int)(hashTable.size() / 2))
        rehash();
    
    return h;
};

// Return record for item with key x.
template<typename HashKey, typename HashRecord>
HashRecord * HashTable<HashKey, HashRecord>::find(const HashKey & x){
    int pos = findPos(x);
    if (isActive(pos)){
        return hashTable[pos].rec;
    }
    return NULL;
};
#endif
