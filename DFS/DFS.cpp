#include <iostream>
#include <vector>



using namespace::std;

class graph{
  
        int V;      //number of nodes
        vector<vector<int>> adj;    //list of adjency edges 
  public:
        //constructor
        graph(int num_of_node):V(num_of_node), adj(num_of_node+1){};
        
        //add adjecy edge from v to w
        void addEdge(int v, int w);
        
        //print adjency edges of node v
        void printEdge(int v);
};

void graph::addEdge(int v, int w){
        adj[v].push_back(w);
}

void graph::printEdge(int v){
    for (auto k: adj[v]) cout<< k<< endl;
}

int main(){
    
    graph g(5);
    g.addEdge(1,3);
    g.addEdge(1, 5);
    g.printEdge(1);
    return 0;
}