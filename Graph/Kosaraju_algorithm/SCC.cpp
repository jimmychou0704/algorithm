

/****************************************
 * 
 * 
 *          Kosaraju’s algorithm
 * 
 * 
******************************************/


//Compute the number of strong connecte component


#include <iostream>
#include <vector>
#include "SCC.h"

using namespace::std;


int main(){
    
    graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 5);
    //first_DFS(g);
    //for (auto k: g.adj[2]) cout<< k<< endl;
    graph newg = reverse_graph(g);
    for (int i = 1; i<= 5; i++){
        newg.printEdge(i);
        cout<< endl;
    }
    
    return 0;
}