//
//  Median.h
//  Project 5- Priority Queues
//
//  Created by Aaron Adams on 11/3/16.
//  Copyright © 2016 Aaron Adams. All rights reserved.
//

#ifndef Median_h
#define Median_h

#include <iostream>
#include "SkewHeap.h"

using namespace std;

class Median{
public:
    
    int currMedian;
    bool firstInsert = false;
    //values greater than currMedian
    SkewHeap minHeap;
    
    //values less than currMedian
    SkewHeap maxHeap;
    
    Median(){
         currMedian = 0;
        firstInsert = false;
    }
    
  void  addNum(int x);
  bool  report(bool x);
int getHeapSize(SkewHeap heap);
    int findMedian(SkewHeap minHeap, SkewHeap maxHeap);
};


int Median:: getHeapSize(SkewHeap heap){
    int size = 0;
    size++;
    return heap.heapSize();
}



void Median:: addNum(int x){
    if(firstInsert == false){
        currMedian = x;
        
        firstInsert = true;
    }
    
    if(x < currMedian){
        maxHeap.maxInsert(x);
    }
    if(x > currMedian){
        minHeap.minInsert(x);
    }
    
    
    int minHeapSize = getHeapSize(minHeap);
    int maxHeapSize = getHeapSize(maxHeap);

    
    if(minHeapSize - maxHeapSize > 1){
        //shift left
        maxHeap.maxInsert(currMedian);
        currMedian = minHeap.deleteMin();
        
        
        
        //find min and make it the median
        //make currMedian in MAx heap
        //delete min from heap
        
    }
    else if(maxHeapSize - minHeapSize > 1){
        minHeap.minInsert(currMedian);
        currMedian = maxHeap.deleteMax();
        //shift right
        //find max and make it the median
        //make currMedian in min heap
        //delete max from heap
    }
    
}










bool Median:: report(bool x){
    
    cout << "REPORT: " << endl << endl;
    
    cout << "Median: " << currMedian << endl << endl;
    
    cout << "Min Heap" << endl << endl;
    int minHeapSize = getHeapSize(minHeap);

    cout << "size: " << minHeapSize << endl;
    cout << "number of merges " << minHeap.numMerges << endl << endl;
    minHeap.toString();
    cout << endl << endl << "Max Heap" << endl;
    int maxHeapSize = getHeapSize(maxHeap);
    
    cout << "size: " << maxHeapSize << endl;
    cout << "number of merges " << maxHeap.numMerges << endl << endl;

    maxHeap.toString();
    
    //prints the number of merges required in each heap
    
    return true;
}




#endif /* Median_h */
