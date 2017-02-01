#include <iostream>
#include <vector>
#include <fstream>

#include <unordered_set>


#include "graph.h"
#include "heap.h"

using namespace std;

//MST algorithm, return the minimal weight of a spanning tree of a given graph




long MST(int src, const graph& g){
    
    unordered_set<int> visited;
    
    //min heap structure to keep record of min cost path from points of visited list
    minHeap<node> m;
    
    long cost = 0;
    
    //current vertex
    node* curr;
    curr = g.array[src];
    
 
    
    
    while (curr){
        visited.insert(curr->data);
        //vertex we can go from current vertex
        node* vertex_to_go = curr->next;
       
        //if the vertex_to_go is not visited yet, add it to the heap
        //do this to all possible vertex_to_go
        while(vertex_to_go){
                
                if(visited.find(vertex_to_go->data)==visited.end()){
                          m.addNode(vertex_to_go);
                    
                }
                       
                vertex_to_go = vertex_to_go->next;       
        }

        //delete visited node from the min heap
        while(!m.empty() && visited.find(m.getMin()->data)!= visited.end()) m.deleteMin();
        
        //if there is node not visited yet
        if (m.empty()==0){
                     
                     
                     curr = g.array[m.getMin()->data];
                     
                     cost += m.getMin()->cost;
                     m.deleteMin();
                }
                
        
        else curr = nullptr;
        
    }
    
    
    return cost;
}



int main(){
    
    //data.txt has 500 nodes
    graph g(500);
    
    ifstream infile("data.txt");
    int a,b,c;
    while(infile >> a >> b >> c){
           
           g.add_edge(a,b,c);
           g.add_edge(b,a,c);
    }
    
   
    
    
 
   cout<< MST(1, g)<<endl;
  
   return 0;
}
