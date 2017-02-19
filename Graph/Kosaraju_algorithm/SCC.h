#include <iostream>
#include <vector>
#include <unordered_set>

using namespace::std;


class graph{
  
        int V;      //number of nodes
        
  public:
  
        vector<vector<int>> adj;    //list of adjency edges 
        
        //constructor
        graph(int num_of_node):V(num_of_node), adj(num_of_node+1){};
        
        //add adjecy edge from v to w
        void addEdge(int v, int w);
        
        //print adjency edges of node v
        void printEdge(int v);
        
        //return graph size
        int size() const {return this->V;}
};

void graph::addEdge(int v, int w){
        adj[v].push_back(w);
}

void graph::printEdge(int v){
    for (auto k: adj[v]) cout<< k<< " ";
}

//utility functoin to revere the arrows of the graph

graph reverse_graph(const graph& original){
    graph g(original.size());
    for (int i = 1; i<= original.size(); i++){
        for (auto k: original.adj[i]){
            g.addEdge(k,i);
        }
    }
    
    return g;
}



//A utility functoin used by DFS
void DFS_local(const graph& g, int v, vector<int>& finishedTime, unordered_set<int>& visited){
    
    //mark visited
    visited.insert(v);
    
    
    //check if there is any adj nodes not visited yet
    //if no, push into the stack of finished time.
    //bool noWhereToGo = true;
    for (auto k: g.adj[v]){
        if (visited.find(k) == visited.end()){
            //noWhereToGo = false;
            DFS_local(g,k,finishedTime, visited);
        }
        
    }
    
    //if (noWhereToGo == true){
        finishedTime.push_back(v);
    //}
    
    
}


//First DFS 
//return:  stack of int, recording finifhing time in the fist round,
//with the last finished on the top



vector<int> first_DFS(const graph& g){
    
        //two containers
        vector<int> finishedTime;
        unordered_set<int> visited;
        
        for (int i = 1; i<= g.size(); i++){
            
            if (visited.find(i) == visited.end()){
                DFS_local(g,i, finishedTime, visited);
            }
        }
    
    
        return finishedTime;
}