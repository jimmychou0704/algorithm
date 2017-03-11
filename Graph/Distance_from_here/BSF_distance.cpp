#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>


/**************************************************
 * Consider an undirected graph consisting of  nodes where each node is labeled from 1  
 * to n and the edge between any two nodes is always of length 6.
 * We define node  s to be the starting position for a BFS.
 * Given  some starting node, ,calculate the shortest distance from starting node s
 * to all the other nodes in the graph. 
 * Then print a single line of space-separated integers listing node 's shortest 
 * distance to each of the  other nodes (ordered sequentially by node number); 
 * if  is disconnected from a node, print -1 as the distance to that node.
 ***********************************************************/






using namespace std;

class Graph {
    private:
        vector<vector<int>> edges;
        int size;    
    
    public:
        Graph(int n): edges(n+1), size(n) {
            
        }
    
        void add_edge(int u, int v) {
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            //record the distance from start to curr node
            vector<int> distance(size+1, 0);
            
            //keep record of which nodes are in the same level
            //at the beginning, only start in the the curr_queue
            queue<int> curr_queue;
            curr_queue.push(start);
            
            queue<int> next_queue;
            
            //keep record of visited points
            unordered_set<int> visited;
            int level = 1;
            
            while (!curr_queue.empty()){
                int curr = curr_queue.front();
                curr_queue.pop();
                
                for (auto k: edges[curr]){
                    //for nodes achieveable from curr node, if not visited yet, we go to visited it.
                    //we do: 1. add to next level (next queue), 2. label visited 3. distance updated
                    if (visited.find(k) == visited.end()){
                        next_queue.push(k);
                        visited.insert(k);
                        distance[k] += level*6;
                        
                    }
                    
                    
                }
                
                //once we done with the curr node, we check if the current level still has points
                //if yes, then repeated. If not, we move on to next level by replacing curr_queue by next_queue
                
                if (curr_queue.empty()){
                    level += 1;
                    curr_queue = next_queue;
                    while (!next_queue.empty()) next_queue.pop();
                }
                
            }
            
            
            return distance;
        }
    
};


int main(){
    
    
    return 0;
}