//
//  UnionFind.h
//  Social Network
//
//  Created by Aaron Adams on 11/15/16.
//  Copyright © 2016 Aaron Adams. All rights reserved.
//

#ifndef UnionFind_h
#define UnionFind_h

#include<iostream>
#include <vector>

using namespace std;


class UnionFind {
    int *id, count, *sz;
  
public:
    int numUnions;
    int numFinds;
    
    UnionFind(int N) {
       
        count = N;
        
        id = new int[N];
        
        sz = new int[N];
        
        numUnions = 0;
        numFinds = 0;
        
        for (int i = 0; i<N; i++){
        
        id[i] = i, sz[i] = 1;
        
        }
        
    }
    ~UnionFind() {
        delete[] id; delete[] sz;
    }
    
    int find(int p) {
        int root = p;
        
        while (root != id[root]) {
            root = id[root];
        }
        
        while (p != root) {
            int newp = id[p]; id[p] = root; p = newp;
        }
        return root;
    }
   
    void merge(int x, int y) {
        numUnions++;
        int i = find(x);
        numFinds++;

        int j = find(y);
        numFinds++;

        if (i == j) return;
        
        // make smaller root point to larger one
        if (sz[i] < sz[j]) {
            id[i] = j, sz[j] += sz[i];
        }
        
        else {
            id[j] = i, sz[i] += sz[j];
        }
        count--;
    }
    
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    
    // Return the number of disjoint sets.
    int cnt() {
        return count;
    }
    
};
    



#endif /* UnionFind_h */
