#include<bits/stdc++.h>

using namespace std;

int longest_subsequence(vector<int> v){
    vector<int> seq(v.size());
    seq.assign(v.size(),1);
    int longest_subsequence = 1;
    for(int i = 1; i < v.size();i++){
        for (int j = 0 ; j < i; j++){
            if (v[j] < v[i]){
                seq[i]= max(seq[i], seq[j]+1);
                if (seq[i] > longest_subsequence) longest_subsequence = seq[i];
            }
        }
    }
    for (int i = 0; i < seq.size(); i++){
        cout << seq[i]<< " ";
    }
    cout << "\n";

    return longest_subsequence;
}

int main(){
    vector<int> v;
    int arr[] = {7,2,5,6,1, 4,3,8};//{6,2,5,1,7,4,8,3};
    int N = sizeof(arr)/sizeof(arr[0]);
    for (int i =0;i < N;i++) v.push_back(arr[i]);

    cout<< longest_subsequence(v)<<"\n";
}