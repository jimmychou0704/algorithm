#include <iostream>
#include <vector>
#include <unordered_map>




using namespace std;

template <typename T>
class minHeap{
  
  //first int: node data, second int: it's position in the array
  unordered_map<int, int> positionOfNode;
  
  
  public:
        
        
        
        vector <T*> array;
        
        minHeap(){};
        
        ~minHeap(){
            for (auto k: array) delete k;
            
        }
    
        // return the position of left child
        int left(int i){ return 2*i+1;}
        
        //return the position of right child
        int right(int i ){ return 2*i+2;}
        
        //return the positoin of parent
        int parent(int i ){ return (i-1)/2;}
        
        //swap array[i] and array[j] where i, j are positions in array
        void swap(int i, int j);
        
        
        void addNode(T* newNode);       //add a node to the end, and will keep move to 
                                        //parent if it it smaller
        
        
        void heapfy(int curr_index);    //start from curr_index, we compare its cost with 
                                        //cost of its kids, then push the one with min cost 
                                        // to the top.
                                        
        void deleteMin();               //delete the min node, i.e. the first of the array
        
        void print();                   //print all nodes data int the array
                                        //note that we have overload << in struct node
                                        
        bool empty(){
            return (array.size() == 0);
        }                    
                                        
        T* getMin(){return array[0];}
};






template <typename T> 
void minHeap <T>::swap(int i, int j){
            T* temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            
        }

template <typename T>
void minHeap <T>::addNode(T* newNode){
            array.push_back(newNode);
            int curr_index = array.size()-1;
            while(*array[curr_index] < *array[parent(curr_index)]){
                swap(curr_index, parent(curr_index));
                curr_index = parent(curr_index);
            }
            
        }
        

template <typename T> 
void minHeap <T> ::heapfy(int curr_index){
    //assume the min happens at the curr index
    int min = curr_index;
    
    
    
    //compare the COST with left kid, if there is
    if (left(curr_index)< array.size() && ((*array[left(curr_index)]) < (*array[curr_index]) ) ){
    
        min = left(curr_index);
       
        
    }
    
    //compare COST with right kid, if there is
    if (right(curr_index)< array.size() && (*array[right(curr_index)] < *array[min])){
        min = right(curr_index);
    }
    
    if (min != curr_index){
        swap(curr_index, min);
        heapfy(min);
    }
    
}
        


template <typename T>
void minHeap<T>::deleteMin(){
    swap(0, array.size()-1);
    array.pop_back();
    heapfy(0);
    
}
 
        
template <typename T>
void minHeap<T>::print(){
            for (auto k : array) cout<< *k<< endl;
        }