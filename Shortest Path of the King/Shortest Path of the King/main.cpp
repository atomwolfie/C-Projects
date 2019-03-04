//Aaron Adams
//Created in Xcode

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



int main() {
    
    string start, end,listOfMoves = "";
    int numMoves = 0;
    char startX, endX;
    int startY, endY;
    
    cout <<"Enter the starting coordinates: ";
    cin >> startX;
    cin >> startY;
    
    
    cout << "Enter the ending coordinantes: ";
    cin >> endX;
    cin >> endY;
    
    
    
    
    while (startX != endX || startY != endY){
        
        numMoves++;
        
        if (startX < endX){
            
            startX += 1;
            
            listOfMoves += "\r\nR";
            
        }
        
        else if (startX > endX){
            startX -= 1;
            
            listOfMoves += "\r\nL";
            
        }
        
        else {
            
            startX += 0;
        }
        
        if (startY < endY){
            
            startY += 1;
            
            listOfMoves += "D\r";
            
        }
        
        else if (startY > endY){
            
            startY -= 1;
            listOfMoves += "U\r";
        }
        
        else {
            
            startY += 0;
        }
        
        
        
        
        
        
        
        
        
    }
    
    cout << numMoves << endl;
    
    cout << listOfMoves << endl;
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}