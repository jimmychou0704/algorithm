
/**********************************************
 * Given a n by m matrix, compute the number of paths
 * from (0,0) to (n, m)
 * ********************************************/

#include <iostream>
#include <vector>

using namespace std;

int num_of_path(int n, int m){
    
    //represent the matrix by vector
    vector<vector<int>> matrix(n, vector<int>(m,0));
    
    //fill up the first row and column by one
    for (int i = 0; i< m; i++) matrix[0][i] = 1;
    for (int j = 0; j< n; j++) matrix[j][0] = 1;
    
    for (int i = 1; i< m; i++) {
        for (int j = 1; j< n; j++){
            matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        }
    }
    
    return matrix[n-1][m-1];
}



int main(){
    cout<< num_of_path(5, 5)<<endl;
    
    return 0;
}