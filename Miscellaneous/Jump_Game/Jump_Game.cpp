#include <iostream>
#include <vector>
using namespace std;

/*******************************
 * Given an array of non-negative integers, you are initially positioned 
 * at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
********************************/    
   
   
    //Use backward method
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        
        //the index in the succes_list gurantee a true
        //we want to see if 0 will eventually in this list
        vector<int> success_list = {n};
        for (int i = n-1; i >= 0; i--){
            if (nums[i] >= (success_list.back() - i) ){
                success_list.push_back(i);
            }
            
        }
        return ( success_list.back() == 0);
        
    }
    
    
    
    int main(){
        
        vector<int> a = {2,3,1,1,4};
        vector<int> b = {3,2,1,0,4};
        
        cout<< canJump(a)<< endl;
        cout<< canJump(b)<< endl;
        return 0;
    }