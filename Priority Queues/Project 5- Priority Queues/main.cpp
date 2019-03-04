//
//  main.cpp
//  Project 5- Priority Queues
//
//  Created by Aaron Adams on 11/3/16.
//  Copyright © 2016 Aaron Adams. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "SkewHeap.h"
#include "Median.h"

using namespace std;

int main() {
    
    //cout << "hi" << endl;
    const int TEST_VALUE = 15; srand(unsigned (time(0)));
    
    Median m;
    
    
    m.addNum(2);
    m.addNum(5);
    m.addNum(7);
    m.addNum(10);
    m.addNum(15);
    m.addNum(12);
    m.addNum(8);
    m.addNum(3);
    m.addNum(1);
    m.addNum(42);
    m.addNum(20);

    m.report(true);
    
    
    //Bigger test case
   // for (int i = 0; i < TEST_VALUE; i++) {
       // int num = rand() % 1000;
     //   m.addNum(num);
   // }
    
   // m.report(true);  // print Heaps
  //  char c; int size = 32;
    
    //for (int i = TEST_VALUE; i < 1028; i++) {
        //int num = rand()%1000;
      //  cout << num << " ";    m.addNum(num);
    //    if (i == size){
  //  m.report(false);    size*=2;
//}
//    }
    
//    cin >> c; return 0;
   
    return 0;
}
