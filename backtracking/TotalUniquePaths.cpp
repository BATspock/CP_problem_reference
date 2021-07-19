#include<bits/stdc++.h>

using namespace std;

class uniquePaths{
    public:
        int uniqPaths(int m, int n){

            if (m == 1 && n == 1) return 1;

            vector<vector<int>> ans(m, vector<int>(n,0));

            for (int col = n-2; col >= 0; col--) ans[m-1][col] = 1;  //fill up cells at the bottom edge
            
            for (int row =  m-2; row>=0; row--) ans[row][n-1] = 1;  //fill up cells at the right edge
            
            for ( int i = m-2; i >= 0;i--){
                for (int j = n-2;j>=0;j--){
                    ans[i][j] = ans[i][j+1] + ans[i+1][j];
                }
            }

            return ans[0][0];
        
        }
};

int main(){

    uniquePaths *up = new uniquePaths();

    cout<<up->uniqPaths(3, 7)<<endl;

    return 0;
}