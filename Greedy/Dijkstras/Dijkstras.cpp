#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"
#include "heap.h"
#include <unordered_set>

using namespace std;

/*******************************************
Dijkstra algorithm
data.txt:  contains 200 nodes, start with the node number followed by many (endnode, cost)



********************************************/
/*
int dijkstra(const graph& g, int src, int end){
    
    unordered_set<int> visited;
    
    
    
    
}
*/


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
    
    cout<< g.size();
    
    
    return 0;
}

