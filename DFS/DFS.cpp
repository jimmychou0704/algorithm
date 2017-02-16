#include <iostream>
#include <vector>



using namespace::std;

class graph{
  
        int V;      //number of nodes
        vector<vector<int>> adj;    //list of adjency edges 
        void DFS_curr(int v, vector<bool>& visited);  //a utility functoin used by DFS
  public:
        //constructor
        graph(int num_of_node):V(num_of_node), adj(num_of_node+1){};
        
        //add adjecy edge from v to w
        void addEdge(int v, int w);
        
        //print adjency edges of node v
        void printEdge(int v);
        
        //DFS algorithm
        void DFS(int v);
};

void graph::addEdge(int v, int w){
        adj[v].push_back(w);
}

void graph::printEdge(int v){
    for (auto k: adj[v]) cout<< k<< endl;
}

void graph::DFS_curr(int v, vector<bool>& visited){
    visited[v] = true;
    cout<< v<< " ";
    for (auto k: adj[v]) {
        if (!visited[k])  DFS_curr(k, visited);
    }
}


void graph::DFS(int v){
            vector<bool> visited(V, false);
            DFS_curr(v, visited);
            
        }

int main(){
    
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.DFS(2);
    return 0;
}