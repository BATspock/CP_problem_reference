#include<bits/stdc++.h>

using namespace std;

int countsubgrids(vector<vector<int>> v, int n, int div){
    int subgrids = 0;
    for (int r1 =0;r1 < n;r1++){
        for (int r2 =r1+1;r2<n;r2++){
            int hit = 0;
            for (int i = 0; i<n; i++ ){
                if (v[r1][i] == 1 && v[r2][i] == 1) hit++;
            }        
            subgrids+=((hit*(hit-1))/2);
        } 
    }
    return subgrids;
}

int main(){

    vector<vector<int>> vec{{0,1,0,0,1}, {0,1,1,0,0},{1,0,0,0,0},{0,1,1,0,1},{0,0,0,0,0}};
    int N = 5, div = 2;
    cout<< countsubgrids(vec,N, div)<<endl;    

    return 0;
}