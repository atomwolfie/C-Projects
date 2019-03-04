#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <iostream> 
#include <assert.h>
#include <sstream>
#include <vector>
#include <iomanip>      // std::setw

using namespace std;

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x  
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// string toString(string msg )      --> Print tree in sorted order
// Comparable  removeMin  -->  You are not allowed simply to do a find Min and then a remove on that value.  
//                            That would require that you traverse the tree twice  (once to find and once to delete).  We want a true removeMin that 
//                            only traverses in order to delete.
// ******************ERRORS********************************


//HINT:   The class you use as Comparable must have overloaded operators for > == and <.
//        nullptr is another way of saying NULL.  It has some interesting properties for implicit conversions.
//        && is an "rvalue reference".  They are beyond the scope of this class.  A good explanation is at http://thbecker.net/articles/rvalue_references/section_01.html

template <typename Comparable>
class AvlTree
{
public:
	AvlTree() : root{ nullptr }
	{
		size = 0;
	}

    
    
    void toString(){
        
        toString(root, 0);
    }
    
    
    
    
    bool isItDone(string endWord){
       return isItDone(root, endWord);
    }
    
    
    
    
    
    
    void theWork(vector<string>& dictionary, string finalWord){
        theWork(dictionary, root, finalWord);
    }
    
    void compare(vector<string>& dictionary, string word, vector<string> ladder, AvlTree& tree, string endingWord, vector<bool>& usedWords){
    
        vector<string> dictionaryCopy = dictionary;
        string tempWord = ladder.back();
        vector<string> newWordLadder = ladder;
        vector<char> aZ = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
        for(int i = 0; i< word.size(); ++i){
            for(int j = 0; j < aZ.size(); ++j){      //changing letter by letter all combos
                tempWord[i] = aZ[j];
        
                int low = 0;
                int high = dictionary.size() - 1;
                while(low <= high){
    
                    int mid = (low + high)/2;
        
                    if(tempWord == dictionaryCopy[mid]){
    
                        if(tempWord != word && usedWords[mid] == false){
                            newWordLadder.push_back(tempWord);
                            tree.insert(newWordLadder);
                            usedWords[mid] = true;
                            newWordLadder = ladder;
                        }
    
                        break;
                    }
                    if(tempWord < dictionaryCopy[mid]){
    
                        high = mid -1;
                    }
    
                    else{
                        low = mid + 1;
                    }
                }
            }
            
            
            
            tempWord = word;
        }
        return;
    }
    
    
    
	int getSize(){ return size; }
	AvlTree(const AvlTree & rhs) : root{ nullptr }
	{
		size = rhs.size;
		root = clone(rhs.root);
	}

	AvlTree(AvlTree && rhs) : root{ rhs.root }
	{
		rhs.root = nullptr;
	}

	~AvlTree()
	{
		makeEmpty();
	}

	/* Deep copy. */
	AvlTree & operator=(const AvlTree & rhs)
	{
		AvlTree copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	/* Move. */
	AvlTree & operator=(AvlTree && rhs)
	{
		std::swap(root, rhs.root);

		return *this;
	}


	/* Returns true if x is found in the tree. */
	bool contains(const Comparable & x) const
	{
		return contains(x, root);
	}

	/* Test if the tree is logically empty.	 */
	bool isEmpty() const
	{
		return root == nullptr;
	}

	/* String contaings the tree contents in sorted order. */
	string toString(string msg) const
	{
		ostringstream oss;
		oss << msg << endl;
		if (isEmpty())
			oss << "Empty tree" << endl;
		else
			oss << toString(root);
		oss << "END " << msg << endl;
		return oss.str();
	}

	/* Make the tree logically empty. */
	void makeEmpty()
	{
		makeEmpty(root);
	}

	/*	Insert x into the tree; 	 */
	void insert(vector<string> ladder, string endWord)
	{
		size++;
		insert(ladder, root, endWord);
	}

	/**
	 * Insert x into the tree; 
	 * && is termed an rvalue reference.
	 * a good explanation is at http://thbecker.net/articles/rvalue_references/section_01.html
	 */
	void insert(Comparable && x)
	{
		size++;
		insert(std::move(x), root);
	}

	/* Remove x from the tree. Nothing is done if x is not found.	 */
	void remove(const Comparable & x)
	{
		size--;
		remove(x, root);
	}
	/* remove smallest element from the tree.  Return the value found there*/
	
    
    vector<string> removeMin(){
		size--;
		AvlNode * min = findMin(root);
		assert(min != NULL);
        
		return min->ladder;
	}
    
    

private:
	struct AvlNode
	{
		vector<string> ladder;
		AvlNode   *left;
		AvlNode   *right;
		int       height;
        int       score;
		AvlNode(vector<string> & ld, AvlNode *lt, AvlNode *rt, int h = 0, int s = 0)
        : ladder{ ld }, left{ lt }, right{ rt }, height{ h }, score {s} { }

		AvlNode(vector<string> && ld, AvlNode *lt, AvlNode *rt, int h = 0, int s = 0)
        : ladder{ std::move(ld) }, left{ lt }, right{ rt }, height{ h }, score{s} { }
	};

	AvlNode *root;
	int size;

    

    void toString(AvlNode* tree, int indent){
        if(tree != NULL) {
            if(tree->right) {
                toString(tree->right, indent+4);
            }
            if (indent) {
                cout << setw(indent) << ' ';
            }
            if (tree->right) cout<<" /\n" << setw(indent) << ' ';
            cout << "[";
            for(int i = 0; i < tree->ladder.size(); ++i){
                cout << tree->ladder[i] << ", ";
            }
            cout <<"]";
            cout << "\n";
            if(tree->left) {
                cout << setw(indent) << ' ' <<" \\\n";
                toString(tree->left, indent+4);
            }
        }
    }
    
    

    
 //gets score of a certain vector
    int score(vector<string> ladder, string endWord){
        int score = 0;
        for(int i = 0; i < ladder[0].size(); ++i){
            score++;
        }
        for(int i = 0; i< ladder[0].size(); ++i){
            if(ladder.back()[i] == endWord[i]){
                score--;
            }
        }
        
        return score;
    }
    
    
    
    void theWork(vector<string>& dictionary, AvlNode* & tree, string finalWord){
        
        vector<bool> usedWords;
        
        for(int i = 0; i < dictionary.size(); ++i){
            usedWords.push_back(false);
            
        }
        
        
        bool amIDone = false;
        int check = 0;
        AvlNode* min = tree;
        int enqueued = 0;

        while(min->ladder.back() != finalWord){
            
                compare(dictionary, min->ladder.back(), min->ladder,  tree, finalWord, usedWords, enqueued);
                
                min->ladder = removeMin();
                
                amIDone = isItDone(root, finalWord, check);
        }
        cout << endl << "finished"  << endl << endl;
        cout << "Method: AVL Tree" << endl << endl;
        cout << "[";

        for(int i = 0; i < min->ladder.size(); ++i){
            cout << min->ladder[i] << ", ";
        }
        cout << "]";
        
        cout << endl << "size of ladder: " << min->ladder.size() << endl;

        //number enqueued
        cout << "Number of ladders enqueued: " << enqueued << endl;
        
        //number dequeued
        cout << "Number of ladders dequeued: "  << enqueued - totalNodes(root) << endl;
        
        cout << endl << endl << endl;


    }
    
    
    
    int totalNodes(AvlNode* t){
                
        if(t == nullptr){
            return 0;
        }
        
        return totalNodes(t->left) + totalNodes(t->right) + 1;
    }
    
    
    void compare(vector<string>& dictionary, string word, vector<string> ladder, AvlNode*& tree, string endingWord, vector<bool>& usedWords, int & enqueud){
        
        vector<string> dictionaryCopy = dictionary;
        string tempWord = ladder.back();
        vector<string> newWordLadder = ladder;
        vector<char> aZ = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        
        for(int i = 0; i< word.size(); ++i){
            for(int j = 0; j < aZ.size(); ++j){      //changing letter by letter all combos
                tempWord[i] = aZ[j];
                
                int low = 0;
                int high = dictionary.size() - 1;
                while(low <= high){
                    
                    int mid = (low + high)/2;
                    
                    if(tempWord == dictionaryCopy[mid]){
                        
                        if(tempWord != word && usedWords[mid] == false){
                            newWordLadder.push_back(tempWord);
                            insert(newWordLadder, endingWord);
                            enqueud++;
                            usedWords[mid] = true;
                            newWordLadder = ladder;
                        }
                        
                        break;
                    }
                    if(tempWord < dictionaryCopy[mid]){
                        
                        high = mid -1;
                    }
                    
                    else{
                        low = mid + 1;
                    }
                }
            }
            tempWord = word;
        }
        return;
    }

    
    bool isItDone(AvlNode*& tree, string endWord, int &check){
        if(tree == nullptr){
            return true;
            check = 5;
        }
        
        if(tree->ladder.back() == endWord){
            cout << "finished" << endl;
            cout << "[";
            for(int i = 0; i < tree->ladder.size(); ++i){
                cout << tree->ladder[i] << ", ";
            }
        cout << "]";
            cout << endl << endl << endl << endl;
            check = 5;
            return true;
        }
        
        
        isItDone(tree->left, endWord, check);
        isItDone(tree->right, endWord, check);
        
        return false;
    }
    
    
    
    
    
	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert(vector <string>& ladder, AvlNode* & t, string endWord)
	{
        int tScore;
        
        int ladderScore = score(ladder, endWord);
        
        if (t == nullptr){
			t = new AvlNode{ ladder, nullptr, nullptr };
        }
        else if (t != nullptr){
			
            tScore = score(t->ladder, endWord);
            t->score = tScore;
            if(ladderScore <= tScore){
            insert(ladder, t->left, endWord);
            }
            else{
                insert(ladder, t->right, endWord);

            }
        }
		balance(t);
	}

	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert(vector<string> && ladder, AvlNode* & t, string endWord)
	{
        int ladderScore = score(ladder, endWord);
        
        int tScore = 0;
        t->score = tScore;
        
        if (t == nullptr){
			t = new AvlNode{ std::move(ladder), nullptr, nullptr };
        }
    
        
        else if (ladderScore < tScore){
			insert(std::move(ladder), t->left, endWord);
        }
        else{
			insert(std::move(ladder), t->right, endWord);
        }
		balance(t);
	}

	/**
	 * Internal method to remove from a subtree.
	 * x is the item to remove.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
    void remove(AvlNode* & x, AvlNode * & t){
        
        
        if (t == nullptr){
            cout << endl << "deleted nothing" << endl;
            return;   // Item not found; do nothing
        }
        if (x->score < t->score)
            remove(x, t->left);
        else if (t->score < x->score)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t->ladder = findMin(t->right)->ladder;
            remove(x, t->right);
        }
        else
        {
            AvlNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            cout << endl << endl << "deleting" << endl;
            cout << "[";
            for(int i =0; i < oldNode->ladder.size(); ++i){
                cout << oldNode->ladder[i] << ", ";
            }
            cout << "]";
            
            delete oldNode;
            
            cout << endl << endl << "NEW TREE AFTER DELETION" << endl << endl;
            toString();
        }
        
        balance(t);
        
    }
    
    
    
    
    AvlNode*  removeMin(AvlNode * & tree){
        AvlNode* min = findMin(tree);
        cout << "found key: " << endl;
        cout << "[";
        for(int i = 0; i< min->ladder.size(); ++i){
            cout << min->ladder[i] << ", ";
        }
        cout << "]";
        cout << " key score: " << min->score << endl;
        
        AvlNode *oldNode;
		return oldNode;
	}
    
    
    
    
	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance(AvlNode * & t)
	{
		if (t == nullptr)
			return;

		if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
			if (height(t->left->left) >= height(t->left->right))
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
		else
			if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
				if (height(t->right->right) >= height(t->right->left))
					rotateWithRightChild(t);
				else
					doubleWithRightChild(t);

		t->height = max(height(t->left), height(t->right)) + 1;
	}

	/**
	 * Internal method to find the smallest item in a subtree t.
	 * Return node containing the smallest item.
	 */
	AvlNode * findMin(AvlNode *t) 
	{
		if (t == nullptr)
			return nullptr;
        if (t->left == nullptr){
			return t;
        }
        
        AvlNode* temp = findMin(t->left);
        if(temp == t->left){
            t->left = temp->right;
        }
        
        balance(t);
		return temp;
	}

	/**
	 * Internal method to find the largest item in a subtree t.
	 * Return node containing the largest item.
	 */
	AvlNode * findMax(AvlNode *t) const
	{
		if (t != nullptr)
			while (t->right != nullptr)
				t = t->right;
		return t;
	}


	/**
	 * Internal method to test if an item is in a subtree.
	 * x is item to search for.
	 * t is the node that roots the tree.
	 */
	bool contains(const Comparable & x, AvlNode *t) const
	{
		if (t == nullptr)
			return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return true;    // Match
	}

	/**
	 * Internal method to make subtree empty.
	 */
	void makeEmpty(AvlNode * & t)
	{
		if (t != nullptr)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	/**
	 * Internal method to clone subtree.
	 */
	AvlNode * clone(AvlNode *t) const
	{
		if (t == nullptr)
			return nullptr;
		else
			return new AvlNode{ t->element, clone(t->left), clone(t->right), t->height };
	}
	// Avl manipulations
	/**
	 * Return the height of node t or -1 if nullptr.
	 */
	int height(AvlNode *t) const
	{
		return t == nullptr ? -1 : t->height;
	}

	int max(int lhs, int rhs) const
	{
		return lhs > rhs ? lhs : rhs;
	}

	/**
	 * Rotate binary tree node with left child.
	 * For AVL trees, this is a single rotation for case 1.
	 * Update heights, then set new root.
	 */
	void rotateWithLeftChild(AvlNode * & k2)
	{
		AvlNode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		k1->height = max(height(k1->left), k2->height) + 1;
		k2 = k1;
	}

	/**
	 * Rotate binary tree node with right child.
	 * For AVL trees, this is a single rotation for case 4.
	 * Update heights, then set new root.
	 */
	void rotateWithRightChild(AvlNode * & k1)
	{
		AvlNode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->right), k1->height) + 1;
		k1 = k2;
	}

	/**
	 * Double rotate binary tree node: first left child.
	 * with its right child; then node k3 with new left child.
	 * For AVL trees, this is a double rotation for case 2.
	 * Update heights, then set new root.
	 */
	void doubleWithLeftChild(AvlNode * & k3)
	{
		rotateWithRightChild(k3->left);
		rotateWithLeftChild(k3);
	}

	/**
	 * Double rotate binary tree node: first right child.
	 * with its left child; then node k1 with new right child.
	 * For AVL trees, this is a double rotation for case 3.
	 * Update heights, then set new root.
	 */
	void doubleWithRightChild(AvlNode * & k1)
	{
		rotateWithLeftChild(k1->right);
		rotateWithRightChild(k1);
	}
};






#endif
