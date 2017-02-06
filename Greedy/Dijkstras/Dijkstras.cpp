#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"
#include "heap.h"
#include <unordered_map>

using namespace std;

/*******************************************
Dijkstra algorithm
data.txt:  contains 200 nodes, start with the node number followed by many (endnode, cost)



********************************************/

int dijkstra(const graph& g, int src, int end){
    
    //we use this number to to represent the initial distance 
    //from the src to all other nodes
    long veryLargeNum = 100000;
    
    //array keeping track of min cost from src to all other nodes
    int sol[g.size()];
    for (int i = 1; i<= g.size(); i++){
        sol[i] = i==src? 0: veryLargeNum;
    }
    
    //first int: nodes been visited, second int: lin cost to achieve this node
    unordered_map<int, int> visited;
    
    //keep record of achivable nodes.
    minHeap<node> m;
    
        
    
    
    
    return sol[200];
    
    
    
    
}



int main(){
    
    //read data
    ifstream data("data.txt");
    string line;
    
    //construct a graph with 200 nodes
    graph g(200);
    //updating the cost according to data.txt
    while (getline(data, line)){
        vector <int> curr_line;
        
        
        stringstream ss(line);
        int i;
        while (ss >> i){
                        if (ss.peek() == ',')
                        ss.ignore();
                        curr_line.push_back(i);
                        
        }
        
        
        for (int i = 1; i< curr_line.size(); i += 2){
            g.add_edge(curr_line[0], curr_line[i], curr_line[i+1]);
        }
        
    }
    
    cout<< dijkstra(g,199,50);
    
    
    
    return 0;
}

