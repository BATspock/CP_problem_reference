#include<bits/stdc++.h>

using namespace std;

int convertonumber(valarray<int> a){
    int num = 0;
    for (int i = 0;i<a.size();i++) num+= pow(2, a.size()-i-1)*a[i];
    return num;
}

int countsubgrids(vector<vector<int>> v, int n, int N){
    int subgrids = 0, steps = n/N, flag = n%N, val;

    for (int r1 =0;r1 < n; r1++){        
        for (int r2 =r1+1;r2<n;r2++){
            
            int hit = 0;
            
            for (int i=0;i<n;i+=N){
                
                vector<int> x(N, 0);
                vector<int> y(N, 0);

                x.assign(v[r1].begin()+i ,v[r1].begin()+i+N);                
                y.assign(v[r2].begin()+i ,v[r2].begin()+i+N);
                
                valarray<int> test1(x.data(), x.size()); 
                valarray<int> test2(y.data(), y.size()); 
                
                val = convertonumber(test1 & test2);
                
                hit +=__builtin_popcount(val); 
            }
            subgrids+=((hit*(hit-1))/2);         
        }        
            
    } 
    return subgrids;
}

int main(){

    vector<vector<int>> vec{{0,1,0,0,1}, {0,1,1,0,0},{1,0,0,0,0},{0,1,1,0,1},{0,0,0,0,0}};
    int N = 5;
    int s = 3;
    cout<< countsubgrids(vec,N, s)<<endl;    
    return 0;
}