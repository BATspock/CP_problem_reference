#include<bits/stdc++.h>

using namespace std;

bool isInterleaving(string s1, string s2, string s3){

    if (s1.length() + s2.length() != s3.length()) return false;

    int n = s1.length() + 1, m = s2.length() + 1;

    vector<vector<int>>dp(n+1, vector<int>(m+1,false));

    dp[0][1] = true;

    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            
            bool up = dp[i-1][j] && (i<2 || s1[i-2] == s3[i+j -3]), left = dp[i][j-1] && (j<2 || s2[j-2] == s3[i+j-3]);

            dp[i][j] = up || left;
            
        }
    }
    return (dp[n][m]);

}

int main(){
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

    cout<<isInterleaving(s1, s2, s3);
    return 0;
}