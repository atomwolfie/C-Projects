//Aaron Adams
//Created in Xcode


#include <iostream>
#include <string>
#include <fstream>





using namespace std;

int main() {
    

    ifstream fin;
    ofstream fout;
    
    
    
    
    fin.open ("triviQuestions.txt");
    
    
    
        while (!fin.eof()) {
            
            string line1, line2;
           
            
     
           
            
            getline (fin, line1);
        
            cout << line1 << endl;
            
        

        
        }
    
        
       
    fin.close();
    fout.close();
        
    
    


    
    
        
       
        return 0;

    }
