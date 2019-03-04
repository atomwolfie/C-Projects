//Aaron Adams
//Created in Xcode


#include <iostream>
#include <string>
#include <fstream>
#include <vector>




using namespace std;

vector <vector<char> > createVector();

void printMaze(vector <vector<char>> mazeVector);

void startLocation(int & startx, int & starty, vector <vector<char> > mazeVector );

bool solveMaze(vector <vector<char> > & mazeVector, int currentX, int currentY);


int main() {
    
    int startx, starty;
    
    
    vector <vector<char> > mazeVector = createVector();
    
    cout << "Original Maze" << endl;
    
    printMaze(mazeVector);
    
    
    
    startLocation(startx, starty, mazeVector);
    
    
    solveMaze(mazeVector, startx, starty);
    
    cout << "Solved Maze" << endl;
    
    printMaze(mazeVector);
    
    
    
    
    
    return 0;
    
    
}



//---------------function that turns the maze characters into a 2D Vector------------//

vector <vector<char> > createVector(){
    
    int numRows, numColumns, row;
    row = 0;
    vector <vector<char> > mazeVector;
    
    ifstream fin;
    ofstream fout;
    
    
    
    
    
    fin.open ("maze.txt");
    
    fin >> numRows;
    fin >> numColumns;
    
    
    while (!fin.eof()) {
        
        string currentLine;
        
        
        getline (fin, currentLine);
        
        
        
        vector<char> myLine;
        mazeVector.push_back(myLine);
        for (int i = 0; i < currentLine.length(); i++){
            
            mazeVector[row].push_back(currentLine[i]);
            
        }
        
        
        ++row; //goes to next row
    }
    
    
    
    
    return mazeVector;
    
}
//------------------------------------------------------------------------//
//---------------------function that prints maze----------------------------//

void printMaze(vector <vector<char>> mazeVector){
    
    
    
    for(unsigned int i = 0; i < mazeVector.size(); i++ ){
        
        
        
        for (unsigned int j = 0; j < mazeVector[i].size(); j++){
            
            
            
            cout << mazeVector[i][j];
            
        }
        
        cout << endl;
    }
    cout << endl;
    
    
    
    
}
//---------------------------------------------------------------------------------------//

//--------------------------finds start location------------------------------------------------//

void startLocation(int & startx, int & starty, vector <vector<char> > mazeVector ){
    
    
    
    for(unsigned int x = 0; x < mazeVector.size(); x++ ){
        
        
        
        for (unsigned int y = 0; y < mazeVector[x].size(); y++){
            
            
            if (mazeVector[x][y] == 's'){
                
                startx = x;
                starty = y;
                
                
                
                
                return;
                
            }
            
            
        }
        
        
    }
    
    
}

//--------------------------------------------------------------------------------------------//

//-----------------------------Recursive function solving maze-------------------------------------------//

bool solveMaze(vector <vector<char> > & mazeVector, int currentX, int currentY){
    
    
    
    if (mazeVector[currentX][currentY]== 'e'){
        
        
        return true;
    }
    
    
    
    
    if (mazeVector[currentX][currentY]== 'X' || mazeVector[currentX][currentY]== '*' ){
        
        return false;
        
        
    }
    
    mazeVector[currentX][currentY] = '*';
    
    bool correctPath = solveMaze(mazeVector, currentX, currentY - 1) || solveMaze(mazeVector, currentX, currentY + 1) || solveMaze(mazeVector, currentX -1, currentY) || solveMaze(mazeVector, currentX + 1, currentY);
    
    
    if (correctPath == false){
        
        mazeVector[currentX][currentY] = '.';
        
    }
    
    return correctPath;
    
    
    
    
}





//---------------------------------------------------------------------------------//
