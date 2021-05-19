#include<bits/stdc++.h>
using namespace std;

void kanpsack(vector<int> a){
    int totalwt = accumulate(a.begin(), a.end(),0);
    vector<int> possible;
    possible.assign(totalwt+1,0);
    possible[0] = 1;
    for (int k = 0;k<a.size();k++){
        for (int i = totalwt; i >=0;i--){
            if (possible[i]) possible[i + a[k]] = 1;
        }
    }
    for (int i =0;i < possible.size();i++){
        if (possible[i] == 1) cout<<i<<endl;
    }
}

int main(){
    int arr[] = {1,3,3,5};
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<int> weights;
    for(int i = 0;i < N;i++) weights.push_back(arr[i]);

    kanpsack(weights);

    return 0;
}