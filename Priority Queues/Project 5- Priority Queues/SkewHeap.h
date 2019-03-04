//
//  SkewHeap.h
//  Project 5- Priority Queues
//
//  Created by Aaron Adams on 11/3/16.
//  Copyright © 2016 Aaron Adams. All rights reserved.
//

#ifndef SkewHeap_h
#define SkewHeap_h

#include <iostream>
#include <vector>
#include <iomanip>      // std::setw
#include <assert.h>



using namespace std;


class SkewHeap{

public:
    int numMerges;
    //~SkewHeap();
    SkewHeap(){
        root = NULL;
        numMerges = 0;
    }
    
    void minInsert(int x);
    void maxInsert(int x);
    void makeEmpty();
    void merge(SkewHeap & rhs);
    void toString(){
        toString(root, 0);
    }
    int heapSize(){
        return heapSize(root);
    }

    int removeMin(){
        LeftistNode * min = findMin(root);
        assert(min != NULL);
        return min->x;
    }
    
    int removeMax(){
        LeftistNode * max = findMax(root);
        assert(max != NULL);
        return max->x;
    }
    
    int deleteMax(){
        return deleteMax(root);
    }
    int deleteMin(){
        return deleteMin(root);

    }

    
    
private:
    
    struct LeftistNode{
        
        int x;
        LeftistNode *left;
        LeftistNode *right;
        
        LeftistNode(const int& theElement, LeftistNode *lt = NULL, LeftistNode *rt = NULL):
        x(theElement), left(lt), right(rt){}
        
    };
    
    LeftistNode *root;
    

    int deleteMax(LeftistNode *&root)
    {
        if (root == NULL)
        {
            cout << "The heap is empty"<<endl;
            return NULL;
        }
        LeftistNode *temp1, *temp2;
        temp1 = root->left;
        temp2 = root->right;
        int tempVar = root->x;

        root = maxMerge(temp1, temp2);
        return tempVar;
    }
    
    int deleteMin(LeftistNode *&root)
    {
        if (root == NULL)
        {
            cout << "The heap is empty"<<endl;
            return NULL;
        }
        LeftistNode *temp1, *temp2;
        temp1 = root->left;
        temp2 = root->right;
       int tempVar = root->x;
        root = merge(temp1, temp2);
        return tempVar;
    }
    
    
    LeftistNode * findMax(LeftistNode *t)
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr){
            return t;
        }
        
        LeftistNode* temp = findMax(t->left);
        if(temp == t->left){
            t->left = temp->right;
        }
        
        return temp;
    }
    
    
    
    LeftistNode * findMin(LeftistNode *t)
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr){
            return t;
        }
        
        LeftistNode* temp = findMin(t->left);
        if(temp == t->left){
            t->left = temp->right;
        }
        
        return temp;
    }
    
    
    
    int heapSize(LeftistNode* heap){
      
        if (heap==NULL)
            return 0;
        else
            return(heapSize(heap->left) + 1 + heapSize(heap->right));
        
    }
    
    
    
    void toString(LeftistNode* tree, int indent){
        if(tree != NULL) {
            if(tree->right) {
                toString(tree->right, indent+4);
            }
            if (indent) {
                cout << setw(indent) << ' ';
            }
            if (tree->right) cout<<" /\n" << setw(indent) << ' ';
            cout << "[";
                cout << tree->x << ", ";
            cout <<"]";
            cout << "\n";
            if(tree->left) {
                cout << setw(indent) << ' ' <<" \\\n";
                toString(tree->left, indent+4);
            }
        }
    }
    
    
    
    
    LeftistNode * merge(LeftistNode* h1, LeftistNode * h2){
        numMerges++;
        
        if(h1 == NULL)
            return h2;
        
        if(h2 == NULL)
            return h1;
        
        if(h1->x < h2->x)
           return merge1(h1, h2);
        else
            return merge1(h2,h1);
    }

    
    LeftistNode*  merge1(LeftistNode* h1, LeftistNode * h2){
        
        h1->right = merge(h1->right, h2);
        
        //swapping
        LeftistNode* temp = h1-> left;
        h1->left = h1->right;
           // temp = h1->right;
         h1->right = temp;


        return h1;
    }
    
    
    LeftistNode * maxMerge(LeftistNode* h1, LeftistNode * h2){
        numMerges++;
        if(h1 == NULL)
            return h2;
        
        if(h2 == NULL)
            return h1;
        
        if(h1->x > h2->x)
            return maxMerge1(h1, h2);
        else
            return maxMerge1(h2,h1);
    }
    
    LeftistNode*  maxMerge1(LeftistNode* h1, LeftistNode * h2){
        
        h1->right = merge(h1->right, h2);
       
        
                LeftistNode* temp = h1-> left;
                h1->left = h1->right;
                h1->right = temp;
        
                return h1;
    }
    
    
    
 
    
};




void SkewHeap:: merge(SkewHeap & rightHeap){
    
    if(this == &rightHeap){
        return;
    }

    root = merge(root, rightHeap.root);
    rightHeap.root = NULL;

}

void SkewHeap:: minInsert(int x){
    
    root = merge(new LeftistNode(x), root);
    
}



void SkewHeap:: maxInsert(int x){
    
    root = maxMerge(new LeftistNode(x), root);
    
}



#endif /* SkewHeap_h */
