#include<bits/stdc++.h>

using namespace std;

int convertonumber(valarray<int> a){
    int num = 0;

    for (int i = 0;i<a.size();i++) num+= pow(2, a.size()-i-1)*a[i];
    //cout<<num << endl;
    return num;

}

int countsubgrids(vector<vector<int>> v, int n){
    int subgrids = 0;
    int val;
    for (int r1 =0;r1 < n;r1++){
        vector<int> x = vector<int>(v[r1].begin(), v[r1].begin() + n);
        int hit = 0;

        for (int r2 =r1+1;r2<n;r2++){
            
            vector<int> y = vector<int>(v[r2].begin(), v[r2].begin() + n);

            valarray<int> test1(x.data(), x.size());
            valarray<int> test2(y.data(), y.size());
            //valarray<int> test3 = test1 & test2;
            val = convertonumber(test1 & test2);
            hit = __builtin_popcount(val);
            //cout<<" hit: "<<hit<< " with val: "<<val;
            subgrids+=((hit*(hit-1))/2);
            }        
            
            //cout<<" --> value of subgrid: "<<subgrids<<endl;
        } 
    return subgrids;
}

int main(){

    vector<vector<int>> vec{{0,1,0,0,1}, {0,1,1,0,0},{1,0,0,0,0},{0,1,1,0,1},{0,0,0,0,0}};
    int N = 5;
    //int s = 2;
    cout<< countsubgrids(vec,N)<<endl;    
    //for ( auto e: x) cout<<e;
    //vector<int> x = vector<int>(vec[0].begin() + 1, vec[0].begin() + 4);
    //vector<int> y = vector<int>(vec[1].begin() + 1, vec[1].begin() + 4);
    //valarray<int> test1(x.data(), x.size());
    //valarray<int> test2(y.data(), y.size());
    //valarray<int> c = test1&test2;

    //for (auto e : c) cout<<e<<endl;
    return 0;
}