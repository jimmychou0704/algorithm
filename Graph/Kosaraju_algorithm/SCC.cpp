

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
    
    /***************************
     * 
     *  Frirst example of a small graph printing out all the strong 
     *  connected component
     * 
    ****************************/
    
    graph g(5);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    
    //compute the finished time by the first round
    vector<int> finishedTime = first_DFS(g);
    vector<int> copy_finishedTime = finishedTime;
    
    //reverse the arrows of the original graph
    graph new_graph = reverse_graph(g);
    
    //second_DFS following the order of finishedTime
    cout<< "Stong connected components are"<< endl;
    second_DFS(new_graph,finishedTime);
    cout<< endl;
    
    
    /***************************
     * 
     *   print out the size of all strong connected components.
     * 
    ****************************/
    vector<int> size_of_SCC = count_SCC_size(new_graph,copy_finishedTime);
    
    for (auto k: size_of_SCC) cout<< k<< " ";
    
    return 0;
}