#include<bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> arr){
    int best = arr[0];
    int sum = arr[0];
    for (int i = 0 ; i < arr.size(); i++){
        sum = max(arr[i], sum+ arr[i]);
        best = max(sum, best);
    }
    return best;
}

int main(){
    vector<int> array; 
    int a[]= { -1, 2, 4, -3, 5, 2, -5, 2 };
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++ ) array.push_back(a[i]);
    cout<<max_subarray_sum(array);
    return 0;
}