class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
            
        vector<vector<int>> OPT(m+1,vector<int>(n+1));
        
        for(int i = 1;i<m+1;i++){
            for (int j = 1; j<n+1;j++){
                if (text1[i-1] == text2[j-1]){
                    OPT[i][j] = 1 + OPT[i-1][j-1];
                }
                    
                else {
                  OPT[i][j] = max(OPT[i-1][j], OPT[i][j-1]);  
                }
                    
            }
        }
        
        
//         for (int i = 0;i<m+1;i++){
//             for (int j = 0;j<n+1;j++){
//                 cout<<OPT[i][j]<<" ";
//             }
//             cout<<"\n";
//         }
        
        return OPT[m][n];
    }
};
