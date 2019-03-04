// uniform_int_distribution
#include <iostream>
#include <random>
#include <stdlib.h>     /* srand, rand */
#include<list>
#include<vector>
#include<chrono>
#include<iomanip>

using namespace std;

vector<int> mergeSort(vector<int> res);
vector<int> merge(vector<int>& a, vector<int>& b);
void bubbleSort(vector<int>& c);
void insertionSort(vector<int>& c);
int min(vector<int>& c,int start);
void selectionSort(vector<int>& c);
void print(vector<int>a, const int& N);

void quickSort(vector<int>&,int,int);

int partition(vector<int>&, int,int);




vector<int> randomVector(int size){

    
//----creates vector of random integers between 1-100---------------//
    vector<int>vector (size);
    
    srand (time(NULL));

    
    
    
    for (int i = 0; i < size; ++i) {
        
        vector[i] = rand() % 100;
    
    
}
 
    return vector;
}

//<------------------------------------------------------------>//

int main(){
  
    cout << setprecision(10) << fixed;
    
    chrono:: time_point<chrono::system_clock> start, end;
    
   vector<int> newVector= randomVector(10000);
    
    
    cout << "Random vector: " << endl;
    for (int i = 0; i < newVector.size(); ++i){
        
        
        cout << newVector[i] << endl;
        
    }
    
    //-----------------------merge sort------------------------------------------//
    
    start = chrono :: system_clock :: now();  //start chrono, gets time before
    
    vector <int> mergeAnswer = mergeSort(newVector);

    
    end = chrono :: system_clock :: now();  //end chrono, gets time after
    
    chrono:: duration<double> elapsed_seconds = end - start;
    
    time_t end_time = chrono::system_clock::to_time_t(end);
    
    
    cout << "\nSorted vector (using Merge sort): " << endl;
    
    for (int i = 0; i < mergeAnswer.size(); ++i){
        
        cout << mergeAnswer[i] << endl;
        
    }
    
    
    cout << "\nfinished merge sort at " << ctime(&end_time) << "elapsed time: "
    
    << elapsed_seconds.count() <<"s\n";
 //--------------------------------------------------------------------------//
    
    
  //-------------------------Bubble Sort-------------------------------------//
    
    vector<int> bubbleAnswer= newVector;
    
    start = chrono :: system_clock :: now();  //start chrono, gets time before

    
    bubbleSort(bubbleAnswer);
    
    
    end = chrono :: system_clock :: now();  //end chrono, gets time after

    end_time = chrono::system_clock::to_time_t(end);
    
    elapsed_seconds = end - start;

    cout << "\nSorted Vector (using Bubble sort): " << endl;

    
   for(int i = 0; i < bubbleAnswer.size(); i++){
        
        
       cout << bubbleAnswer[i] << endl;
    }
    
    cout << "\nFinished bubble sort at " << ctime(&end_time) << "elapsed time: "
    
    << elapsed_seconds.count() << "s\n";
//------------------------------------------------------------------------//
    
//----------------------Insertion Sort---------------------------------//
    
    vector<int> insertionAnswer = newVector;
    
    start = chrono :: system_clock :: now();  //start chrono, gets time before

    insertionSort(insertionAnswer);
    
    end = chrono :: system_clock :: now();  //end chrono, gets time after

    elapsed_seconds = end - start;
    
    cout << "\nSorted Vector (using Insertion sort): " << endl;
    
    for(int i = 0; i < insertionAnswer.size(); i++){
        
        
        cout << insertionAnswer[i] << endl;
    }
    
    cout << "\nFinished Insertion sort at " << ctime(&end_time) << "elapsed time: "
    
    << elapsed_seconds.count() << "s\n";
//------------------------------------------------------------------------//
    
//---------------------Selection Sort--------------------------------------//

    vector<int> selectionAnswer = newVector;
    
    start = chrono :: system_clock :: now();  //start chrono, gets time before

    selectionSort(selectionAnswer);
    
    end = chrono :: system_clock :: now();  //end chrono, gets time after

    elapsed_seconds = end - start;

    cout << "\nSorted Vector (using Selection sort): " << endl;
    
   for(int i = 0; i < selectionAnswer.size(); i++){
        
        
        cout << selectionAnswer[i] << endl;
    }
    
    cout << "\nFinished Selection sort at " << ctime(&end_time) << "elapsed time: "
    
    << elapsed_seconds.count() << "s\n";
//----------------------------------------------------------------------------//
    
//-------------------------Quick Sort---------------------------------------//
    
    vector<int>quickAnswer = newVector;
    
    int p=0;
    
    int q= quickAnswer.size();

    
    
    
    start = chrono :: system_clock :: now();  //start chrono, gets time before

    
    quickSort(quickAnswer,p,q);
    
    end = chrono :: system_clock :: now();  //end chrono, gets time after

    elapsed_seconds = end - start;

    
    cout << "\nSorted Vector (using Quick sort): \n" << endl;

    for(auto e: quickAnswer){
       
        cout<< e << endl;
    }
    
    cout << "\nFinished Quick sort at " << ctime(&end_time) << "elapsed time: "
    
    << elapsed_seconds.count() << "s\n";
    
    
    return 0;
}



//merge sort function, breaks down vector recursively

vector<int> mergeSort(vector<int> res){
   
    if (res.size() <= 1){
        return res;
    }
    
    int middle = res.size() / 2;

    vector<int> a, b;
    
    for (int i = 0; i < middle; ++i){
        
        a.push_back(res[i]);
    }
    
    for (int i = middle; i < res.size(); ++i){
        
        
        b.push_back(res[i]);
    }
    
    
    a = mergeSort(a);
    
    b = mergeSort(b);
    
    return merge(a,b);
    
}









//merge function, will combine 2 vectors, will be called in merge sort

vector <int> merge(vector<int>& a, vector<int>& b){
    
    auto i = 0; auto j = 0;
    vector<int> res;
    
    res. reserve(a.size() + b.size());
    
    while(i < a.size() ||  j <b.size()){
        
        
        if (a.size() == 0){
            
            res.push_back(b[i]);
            
            b.erase(b.begin());
            
        }
        
        else if (b.size() == 0){
            res.push_back(a[i]);
            
            a.erase(a.begin());
            
            
        }
        
        
        else if(a[i] < b[j]){
            res.push_back(a[i]);
            
            a.erase(a.begin()) ; //++i;
            
            
            
        }
        
        else{
            
            res.push_back(b[j]);
           
            b.erase(b.begin()); //++j;
            
        }
        
        
        
       
        
        
    }
    
    
    
    return res;
    
    
}

void bubbleSort(vector<int> &c) {
    
    auto done = false; while (! done){
        
        done = true;
        
        for(auto i=0u; i < c.size() - 1; ++i) {
           
            if ( c[ i ] > c[ i + 1]) {
                
                swap ( c[ i ] , c[ i + 1 ] ) ;
                
                done = false;
            }
        }
    }
}

void insertionSort(vector<int>& c) {
    
    for(auto i=1; i < c.size(); ++i) {
        
        for(auto j=0;j<i;++j) {
           
            if(c[j] < c[i]) {
                
            swap(c[j],c[i]);
        
            }
        }
    }
}


void selectionSort(vector<int>& c) {
    
    for(auto i = 0;i<c.size();++i) {
        
        auto smallest = min(c , i );
        
        swap ( c [ i ] , c [smallest] ) ;
    }
}

int min(vector<int>& c,int start) {
    
    auto min = numeric_limits<int >::max(); auto cur = - 1;
    
    for(auto i=start;i<c.size();++i){
        
        if(min > c[i]) {
            
            min = c[i];
            
            cur = i; }
    }
    
    return cur ;
}

void quickSort(vector<int>& A, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q);
        quickSort(A,p,r);
        quickSort(A,r+1,q);
    }
}


int partition(vector<int>& A, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;
    
    for(j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
        }
        
    }
    
    swap(A[i],A[p]);
    return i;
}



