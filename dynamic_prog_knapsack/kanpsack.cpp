#include<bits/stdc++.h>
using namespace std;

void kanpsack(vector<int> a){

}

int main(){
    int arr[] = {1,3,3,5};
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<int> weights;
    for(int i = 0;i < N;i++) weights.push_back(arr[i]);

    kanpsack(weights);

    return 0;
}