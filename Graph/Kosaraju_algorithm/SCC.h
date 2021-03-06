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



//utility functoin used by DFS
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

//second_DFS_local: a utility function used by the second DFS
//to compute number of nodes in a connected component

void second_DFS_local(int v,  unordered_set<int>& visited, const graph& g){
        
        visited.insert(v);      //marked current point visited
        cout<< v<< " ";
        
        for (auto k: g.adj[v]){
            if (visited.find(k) == visited.end()) {
                second_DFS_local(k, visited, g);
            }
        }
        
        
        
}



//Second DFS
//return size of each strong connect component


void second_DFS(const graph& g, vector<int>& finishedTime){
    
    unordered_set<int> visited;
    
    while (!finishedTime.empty()){
        int v = finishedTime.back();
        finishedTime.pop_back();
        if (visited.find(v) == visited.end()){
            
            second_DFS_local(v, visited, g);
            cout<< endl;
            //finishedTime.pop_back();
        }
        
        //else finishedTime.pop_back();
        
    }
}


int count_SCC_size_local(int v, unordered_set<int>& visited,\
                           const graph& g){
        visited.insert(v);      //mark viisted
        int size = 1;              //size of this component = 1, before adding other 
                                   //adj nodes    
        
                                
        for (auto k: g.adj[v]){
                if (visited.find(k) == visited.end()) 
                    size += count_SCC_size_local(k, visited,g);          
        }
        
        return size;                    
                            
}

//use DFS  method to compute the size of each strong connected component

vector <int> count_SCC_size(const graph& g, vector<int> finishedTime){
        vector<int> sizeOfSCC;
        unordered_set<int> visited;
        
        
        while (!finishedTime.empty()){
            
            //we start from the last finished node from the first round
            int v = finishedTime.back();
            finishedTime.pop_back();
            
            //we do something only whatn v has not been visited
            if (visited.find(v) == visited.end()){
                int size = count_SCC_size_local(v, visited, g);
                sizeOfSCC.push_back(size);
                
            }
            
            
            
        }
    return sizeOfSCC;
}