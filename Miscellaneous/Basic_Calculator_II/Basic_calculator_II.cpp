#include <iostream>

#include <string>

using namespace std;


/*******************************
 * 
 * 
 * A calculator taking string of operations and then compute its vals
 * 
 * ******************************/



    int calculate(string s) {
        
        int sol = 0;        //final sol;
        int temp = 0;       //used to save "local" int, say 256
        int curr_sol = 0;   //used to save chunk, say 25*10. Will be reset to zero once added to sol
        
                  //index
        
        char op = '+';
        for (int i = 0; i< s.size() ; i++){
            //ignore spaces
            if (s[i] ==' ') continue;
            
            //if s[i] is a number, we keep computing loc int until we meet +-*/
            while (isdigit(s[i])){
                temp = temp*10 + (s[i] -'0');
                i += 1;
                
            }
            
            //put the temp into current "chunk". then reset temp into 0
            if ( op == '+') curr_sol += temp;
            else if (op == '-') curr_sol -= temp;
            else if (op == '*') curr_sol *= temp;
            else curr_sol /= temp;
            temp = 0;
            
            //see if we need to put the current chunk into sol, and reset current into 0
            //note that now s[i] is not digit
            while (s[i] == ' ') i += 1;
            if (s[i] == '+' || s[i] == '-'){
                
                sol += curr_sol;
                curr_sol = 0;
            }
            
            op = s[i];
            
            
            
            
            
        }
        
        //need to add the last chunk
        sol += curr_sol;
        
        return sol;
        
    }
    
    
    
    int main(){
        
        cout<< calculate("2+30/15-6")<<endl;
        
        return 0;
    }