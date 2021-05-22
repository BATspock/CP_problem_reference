#include<bits/stdc++.h>

using namespace std;

string twoSum(vector<int> a, int target){

    sort(a.begin() , a.end());
    int i = 0, j=a.size()-1;
    while(i<=j){
        if (a[i]+a[j] == target) return "YES";
        if (a[i] + a[j] > target) j--;
        else i++;
    }
    return "NO";
}


int main(){
    int arr[] = {7,9,1,5,4,6,10,9};
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    for (int i =0;i < N;i++) v.push_back(arr[i]);
    int K = 1;
    cout<<twoSum(v,K)<<endl;

    return 0;
}