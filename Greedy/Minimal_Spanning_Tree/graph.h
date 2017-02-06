#include <iostream>
#include <vector>


using namespace std;



struct node{
    int data;
    int cost;           //distance from a src node
    node* next = nullptr;
    
    
    //CAUTION: it compares the cost
    bool operator<(node v) const {
        return (this->cost < v.cost);
    }
    
    //CAUTION: it prints data
    friend ostream& operator<<(ostream& os, const node& v){
        os << v.data;  
        return os;  
    } 
};  
  

    
 
    
    


class graph{
public:    
    vector <node*> array;

    graph(int num_of_node):array(num_of_node+1){
        //make an array of node pointers, array[0] is dummy
        // the fisrt element  in each array[k] is itself, so cost = 0
                for (int k = 0; k< num_of_node+1; k++){
                    node* v = new node;
                    v->data = k;
                    v->next = nullptr;
                    v->cost = 0;
                    array[k] = v;
                }
    }
    

    
    ~graph(){
        for ( auto k: array ){
            node* curr = k;
            while (curr){
                node* temp = curr->next;
                delete curr;
                curr = temp;
            }
        }
        
        
    }
    

    
    void add_edge(int src, int dest, int cost_){
        //constructing a new node pointer
        
        node* v = new node;
        v->data = dest;
        v->cost = cost_;
        v->next = nullptr;
        
        //add this new node pointer into the edge link of src node
       
       
        
        node* curr = array[src];
        while(curr->next) curr = curr->next;
        
        curr->next = v;
        
    }
    
    void print(int src){
        node* curr = array[src];
        if (curr){
            cout<< "node " <<src <<" is connecting to "<< endl;
            while(curr){
                cout<< "node "<< curr->data<< " with cost "<< curr->cost<< endl;
                curr = curr->next;
            }
        }
        else cout<<" not going anywhere "<< endl;
        
    }
    
    int size(){ return array.size()-1;}
};