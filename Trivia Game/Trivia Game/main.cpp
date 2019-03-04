//Trivia Game
//Aaron Adams on 3/20/15.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;




int main() {
   

    
    ifstream fin;
    ofstream fout;
    
    
    
    
    fin.open ("triviaQuestions.txt");
    
    
    
    while (!fin.eof()) {
        
        string line1, line2;
        
        
        
        
        
        getline (fin, line1);
        
        fin >> line1;
        cout << line1;
        
        
        
    }
    
    
    
    fin.close();
    fout.close();
    
    
    
    
    
    
    
    
    
    return 0;
    
}
