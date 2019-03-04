#include "edge1.h"
#include <array>
#include<vector>
#include<fstream>





class Graph {
    
    
    
    
    
    
    //GraphNode *G;  // Array of nodes of graph – will be given space once the size is known
public:
    int size;
    
    //2D vector simply for printing purposes
    vector <vector<int>> matrix;
    
    //2D vector of Egdes
    vector <vector<Edge>> adjacencyMatrix;
    
    //vector of vectors containing my cycles
    vector<vector<char>> cycles;
    
    //will contain one complete tour of graph after combining cycles
    vector<char> tour;
    
    
    //used for the joing cycles part, need to know if we have visted the place
    vector<vector<bool>> usedItems;

    
    
   
    //Contructor if given a size, intialzes Matrix to zero
    Graph(int size1){
        
        cout << "creating graph..." << endl;
        
        size = size1;
        
        //1) first creates graph with no edges
        vector<int> row;
        for(int j = 0; j < size; ++j){
        for(int i =0; i < size; ++i){
            row.push_back(0);
        }
            matrix.push_back(row);
        }
        
        
        
        vector<bool> usedRow;
        
        for(int j = 0; j < size; ++j){
            for(int i =0; i < size; ++i){
                usedRow.push_back(false);
            }
            usedItems.push_back(usedRow);
        }
        
        
        
    
        }
    
    
    
    //prints graph
    void print(Graph graph){
       
        char alaphabet[] = {'A', 'B','C','D','E','F','G','H','I','J','K','L','M',
                           'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        cout << "  ";
        for(int i = 0; i < graph.size; ++i){
            cout <<  alaphabet[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < graph.size; i++)
        {
            cout << alaphabet[i] << " ";
            for (int j = 0; j < graph.size; j++)
            {
                cout << graph.matrix[i][j] << ' ';
            }
            cout<< endl;            
        }
        cout << endl;
    }
    
    
  
    
    //prints graph but with cycle ID's
    void printCycles(Graph graph){
        cout << "graph with cycle numbers" << endl;
        
        char alaphabet[] = {'A', 'B','C','D','E','F','G','H','I','J','K','L','M',
            'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        cout << "  ";
        for(int i = 0; i < graph.size; ++i){
            cout <<  alaphabet[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < graph.size; i++)
        {
            cout << alaphabet[i] << " ";
            for (int j = 0; j < graph.size; j++){
                cout << graph.adjacencyMatrix[i][j].cycleID << ' ';
            }
            cout<< endl;
        }
        cout << endl;
    }
    
    
    //creates matrixes for use
    void findEdges(Graph & graph){
        
        
        cout << "finding edges....." << endl << endl;
        
        ifstream fin;
        ofstream fout;
        
        char edge1;
        char edge2;
        
        int numEdges;
        int characters;
        
        //CHANGE AS NEEDED
        fin.open ("prog7B.txt");

        fin >> characters;
        fin >> numEdges;
        
        
        while(!fin.eof()){
            
            Edge edge;
            
            fin >> edge1;
            fin >> edge2;
            
            
            edge = Edge();
            
            //creating initial graph with bogues value
            vector<Edge> edgeRow;
            for(int j = 0; j < size; ++j){
                for(int i =0; i < size; ++i){
                    edgeRow.push_back(edge);
                }
                graph.adjacencyMatrix.push_back(edgeRow);
            }
            
            edge.set(edge1, edge2);
            
            //marks on matrix where there are edges between two nodes
            graph.matrix[edge.toNode][edge.fromNode] = 1;
            graph.matrix[edge.fromNode][edge.toNode] = 1;
            
            //actually adding the graph nodes here
            graph.adjacencyMatrix[edge.toNode][edge.fromNode] = edge;
            graph.adjacencyMatrix[edge.fromNode][edge.toNode] = edge;
        }
        
        cout << endl << "New graph with edges" << endl;
        graph.print(graph);
    }
    
    
    
    void  markCycles1(Graph & graph, int cycleNumber){
        
        bool isThisThingDone = false;
        //MAYBE NEEDS TO BE REMOVED, putting it here to mark the diagonal line
         isThisThingDone = graph.amIDone(graph);
        
        if(isThisThingDone == true){
            return;
        }
        
        cout << "finding cycles..." << endl;
        
        bool doneStart = false;
        bool done = false;
        int xCoordinate = 0;
        int yCoordinate = 0;
        vector<char> myCycle;
        int cycleNum = cycleNumber;
        
        while(doneStart == false){
            
            
            if(xCoordinate > graph.size){
                xCoordinate = 0;
                yCoordinate++;
            }
            
            if(graph.adjacencyMatrix[xCoordinate][yCoordinate].isVisited == false &&
               graph.adjacencyMatrix[xCoordinate][yCoordinate].toNode != -1 &&
               graph.adjacencyMatrix[xCoordinate][yCoordinate].fromNode != -1){
                
                if(cycleNum == 1){
                myCycle.push_back(getChar(graph.adjacencyMatrix[xCoordinate][yCoordinate].fromNode));
                doneStart = true;
                }
                else{
                    myCycle.push_back(getChar(graph.adjacencyMatrix[xCoordinate][yCoordinate].toNode));
                    doneStart = true;
                }
            }
            else{
                
                xCoordinate++;
            }
            
        }
        
        
        while(doneStart == false){
            
            if(amIDone(graph) == true){
                graph.cycles.push_back(myCycle);
                doneStart = true;
            }
            
            
            if(graph.adjacencyMatrix[xCoordinate][yCoordinate].isVisited == false &&
               graph.adjacencyMatrix[xCoordinate][yCoordinate].toNode != -1 &&
               graph.adjacencyMatrix[xCoordinate][yCoordinate].fromNode != -1){
                
                graph.adjacencyMatrix[xCoordinate][yCoordinate].isVisited = true;
                graph.adjacencyMatrix[xCoordinate][yCoordinate].isVisited = true;
                
                
                myCycle.push_back(getChar(xCoordinate));
                doneStart = true;
            }
            
            else{
                xCoordinate++;
            }
        }
        
        while(done == false){
            
            for(int i = 0; i < graph.size; ++i){
                
                //making sure it doesn't go out of scope of the matrix
                if(xCoordinate >= graph.size){
                    xCoordinate = 0;
                }
                
                //the diagonal line through the matrix is pointless and ruins the code, add 1 to xStart to move on
                if(xCoordinate == yCoordinate){
                    ++xCoordinate;
                }
                
                
                char letter;
                
                letter = getChar(i);
                
                if(graph.adjacencyMatrix[xCoordinate][yCoordinate].isVisited == false &&
                   graph.adjacencyMatrix[xCoordinate][yCoordinate].toNode != -1 &&
                   graph.adjacencyMatrix[xCoordinate][yCoordinate].fromNode != -1){
                    
                    //visited
                    graph.adjacencyMatrix[xCoordinate][yCoordinate].isVisited = true;
                    graph.adjacencyMatrix[yCoordinate][xCoordinate].isVisited = true;
                    
                    //marking their cycle
                    graph.adjacencyMatrix[xCoordinate][yCoordinate].cycleID = cycleNum;
                    graph.adjacencyMatrix[yCoordinate][xCoordinate].cycleID = cycleNum;
                    
                    yCoordinate = xCoordinate;
                    
                    myCycle.push_back(getChar(xCoordinate));
                }
                
                else{
                    ++xCoordinate;
                }
                
                
                //Checking to see if I have found the end of the cycle;
                if(myCycle[0] == myCycle[myCycle.size() - 1] && myCycle.size() > 1){
                    
                   // myCycle.pop_back();
                    
                    cout << endl << "Cycle: " << cycleNum << endl;
                    for(int i = 0; i < myCycle.size(); ++i){
                        cout << myCycle[i] << " --> ";
                    }
                    
                    cout << " end" << endl << endl;
                    graph.printCycles(graph);
                    graph.cycles.push_back(myCycle);
                    
                    if(amIDone(graph) == true){
                        return;
                    }
                    else{
                        markCycles1(graph, cycleNum + 1);
                    }
                }
                
                isThisThingDone = amIDone(graph);
                
                if(isThisThingDone == true){
                    graph.cycles.push_back(myCycle);
                    graph.printCycles(graph);

                    
                    if(cycles[0][0] == cycles[cycles.size()-1][0]){
                        cycles.pop_back();
                    }
                    return;
                }
            }
        }
        graph.printCycles(graph);
        
        
    }
    
    
    
    
    void joinCycles(Graph & graph, int start){
        
        cout << "finding tour..." << endl << endl;
        
        int j = 0;
        bool done = false;
        
    
        
        if((graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 2]) || (graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 1])){
           
            done = true;
            
            
            for(int i = 0; i < graph.cycles.size(); ++i){
                for(int j = 0; j < graph.cycles.size(); ++j){
                    if(graph.usedItems[i][j] == false){
                        done = false;
                    }
                }
            }
            
        }
        
        while(done == false){
            
            
            //checking to see if at the end of cycle list
            if(start + 1 < graph.cycles.size()){
            
            //compares current spot in cycle with all spots in next cycle, if there's a match then jump down to next cycle
            for(int i = 0; i < graph.cycles[start].size(); ++i){
                
                if(graph.cycles[start][j] == graph.cycles[start + 1][i] && graph.usedItems[start][j] == false){
                    graph.tour.push_back(graph.cycles[start][j]);
                    graph.usedItems[start][j] = true;
                   
                    graph.usedItems[start + 1][i] =  true;
                    
                    
                    cout << "Tour: ";
                    
                    for(int i = 0; i < graph.tour.size(); ++i){
                        
                        cout << graph.tour[i] << " --> ";
                        
                    }
                    cout << endl;
                    
                    joinCycles(graph, start + 1);

                    if((graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 2]) || (graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 1])){
                        
                        done = true;
                        
                        
                        for(int i = 0; i < graph.cycles.size(); ++i){
                            for(int j = 0; j < graph.cycles.size(); ++j){
                                if(graph.usedItems[i][j] == false){
                                    done = false;
                                }
                            }
                        }
                        
                        // done = true;
                        return;
                    }
                    if((graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 2]) || (graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 1])){
                        
                        done = true;
                        
                        
                        for(int i = 0; i < graph.cycles.size(); ++i){
                            for(int j = 0; j < graph.cycles.size(); ++j){
                                if(graph.usedItems[i][j] == false){
                                    done = false;
                                }
                            }
                        }
                        
                        // done = true;
                        return;
                    }
                    
                }
                
            }
                if(graph.usedItems[start][j] == false){
            graph.tour.push_back(graph.cycles[start][j]);
            graph.usedItems[start][j] = true;
                }
                
                if(j < graph.cycles[0].size() - 1){
            j++;
                }
                else{
                    done = true;
                    return;
                }
                
            }
            
            
            //if at the end to the cycle list just add everything then jump up a level
            else{
                
                for(int i = 0; i < graph.cycles[start].size(); ++i){
                    if(graph.usedItems[start][j] == false){
                    graph.tour.push_back(graph.cycles[start][j]);
                        graph.usedItems[start][j] = true;
                    }
                    j++;
                }
                
                //Resume back on lower level where you were at
                joinCycles(graph, start + - 1);
                if((graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 2]) || (graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 1])){
                    
                    done = true;
                    
                    
                    for(int i = 0; i < graph.cycles.size(); ++i){
                        for(int j = 0; j < graph.cycles.size(); ++j){
                            if(graph.usedItems[i][j] == false){
                                done = false;
                            }
                        }
                    }
                    
                    // done = true;
                    return;
                }


            }
        }
        
        if((graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 2]) || (graph.tour.size() > 1 && graph.tour[0]  == graph.tour[graph.tour.size() - 1])){
            
            done = true;

            
            for(int i = 0; i < graph.cycles.size(); ++i){
                for(int j = 0; j < graph.cycles.size(); ++j){
                    if(graph.usedItems[i][j] == false){
                        done = false;
                    }
                }
            }
            
           // done = true;
            return;
        }
        
        
        
        
        
        cout << "Tour: ";
        
        for(int i = 0; i < graph.tour.size(); ++i){
            
            cout << graph.tour[i] << " --> ";
            
        }
        cout << endl;
        return;
    }
    
    
    //takes number and gives back it's corresponding letter
    char getChar(int node){
        
        char nodeLetter = '\0';
        
        char alaphabet[] = {'A', 'B','C','D','E','F','G','H','I','J','K','L','M',
            'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        
        for(int i = 0; i <= node; ++i){
            
            nodeLetter = alaphabet[i];
        }
        
        
        return nodeLetter;
    }
    
    
    
    
    bool amIDone(Graph & graph){
       
        //marking all the spots in middle as visited so it doesn't throw off my algorithm
        for(int i =0; i < graph.size; ++i){
            for(int j = 0; j < graph.size; ++j){
                if(i == j){
                graph.adjacencyMatrix[i][j].isVisited = true;
                }
                if(graph.adjacencyMatrix[i][j].toNode == -1 && graph.adjacencyMatrix[i][j].fromNode == -1){
                    graph.adjacencyMatrix[i][j].isVisited = true;
                }
            }
        }
            
            
            for(int i =0; i < graph.size; ++i){
                for(int j = 0; j < graph.size; ++j){

                    if(graph.adjacencyMatrix[i][j].isVisited == false){

                        return false;
                }
                   
            
        }
        
    }
        return true;
    }
            
}; // Graph
