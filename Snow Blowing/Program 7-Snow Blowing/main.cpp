#include <iostream>
#include <iomanip>
#include "graph.h"
#include <assert.h>


using namespace std;

int main (){
    
    ifstream fin;
    ofstream fout;
    
    int characters;
    
    //IMPORTANT
    //For further testing, change the document to prog7B.txt or prog7C.txt, go to graph.h and change the file name in the function findEdges as well, OR PROGRAM WON'T WORK
    
    fin.open ("prog7B.txt");
    fin >> characters;

    Graph graph(characters);
    
    graph.print(graph);
    
    graph.findEdges(graph);
    
    
    graph.markCycles1(graph, 1);

    graph.joinCycles(graph, 0);

    
    cout << "Tour Final: " << endl;
    for(int i = 0; i < graph.tour.size(); ++i){
        cout << graph.tour[i] << "-->";
    }
    
    cout << endl << "Thanks :D" << endl;
    
    
    return 0;
}
