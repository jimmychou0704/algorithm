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

int dijkstra(const graph& g, int src, int end){
    
    //we use this number to to represent the initial distance 
    //from the src to all other nodes
    long veryLargeNum = 100000;
    
    //array keeping track of min cost from src to all other nodes
    int sol[g.size()+1];
    for (int i = 1; i<= g.size(); i++){
        sol[i] = i==src? 0: veryLargeNum;
    }
    
    //int: nodes been visited
    unordered_set<int> visited;
    //visited.insert(src);
    
    
    //keep record of achivable nodes.
    minHeap<node> m;
    
    node* curr = g.array[src];
    
    int t = 0;
    
    while ( t< 200){
        visited.insert(curr->data);
        //add all neighbors of curr node into the heap m
        //the cost will be the sum of "cost to curr" + "curr to neighbor"
        //these two datas are contained in the node* "neighbor_new_cost"
        node* neighbor;
        if (curr->next)  neighbor = curr->next;
        else neighbor = nullptr;
        while(neighbor){
            if (visited.find(neighbor->data) == visited.end()){
                node* neighbor_new_cost = new node;
                neighbor_new_cost->data = neighbor->data;
                neighbor_new_cost->cost = sol[curr->data] + neighbor->cost;
                m.addNode(neighbor_new_cost);
                neighbor= neighbor->next;
                
            }
            else neighbor= neighbor->next;
        }
        
        //extract the min one, if we have visited it, ignore and delete from the heap
        while (visited.find(m.getMin()->data) != visited.end())  m.deleteMin();
        
        //extract the min one, it is the local greedy choice of the next step
        
        if (!m.empty()){
        
        node* next_to_go = m.getMin();
        sol[next_to_go->data] = next_to_go->cost;
        curr = g.array[next_to_go->data];
        t += 1;
        }
        
        //else  curr = nullptr;
    }
        
    
    
    
    return visited.size();
    
    
    
    
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

