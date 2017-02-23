#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/****************************************
 * Given a string, find the length of 
 * the longest substring without repeating characters.
 * 
 * **************************************/



int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<char, int> visited;
        
        //keep record of the strat of the longest string ending at i
        int start = 0;
        
        for (int i = 0; i< s.size(); i++){
            
            //if found s[i], may need to update start 
            //two cases, s[i] appears before start or in the the longest string ending at i
            //note that "visited[s[i]] +1"
            if (visited.find(s[i]) != visited.end()){
                
                start = max(start, visited[s[i]] +1);
            }
            
            longest = max(longest, i-start+1);
            visited[s[i]] = i;
        }
            
        return longest;    
        
    }
    
int main(){
    
    cout<< lengthOfLongestSubstring("abcabcbb")<< endl;
    
    cout<< lengthOfLongestSubstring("bbbbbbbb")<< endl;
    
    
    
    return 0;
}