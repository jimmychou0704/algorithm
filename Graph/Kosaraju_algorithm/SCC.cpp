

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
    
        graph g(2);
    g.addEdge(1, 2);
    
    first_DFS(g);
    //for (auto k: g.adj[2]) cout<< k<< endl;
    
    
    
    return 0;
}