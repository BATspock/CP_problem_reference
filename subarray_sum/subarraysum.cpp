#include<bits/stdc++.h>

using namespace std;


int subarraysum(vector<int> v, int n){
    int i =0,j = 0;
    int wt = 0;

    while (i< v.size() || j < v.size()){

        if (i == j){
            if (v[i] == n) return 1; 
            else { wt+=v[j];}
        }
        
        if (wt == n){
            return 1;
        }
        
        else if (wt < n){
            j++;
            wt+=v[j];
        }
        
        else{
            wt=wt-v[i];
            i++;
        }
    }

    return 0;
}

int main(){
    int arr[] = {1,3,2,5,1,1,2,3};
    int d; //= 24;
    cin>> d;
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<int> a;
    for(int i =0; i < N;i++) a.push_back(arr[i]);
    cout<<subarraysum(a, d)<<endl;
    return 0;
}