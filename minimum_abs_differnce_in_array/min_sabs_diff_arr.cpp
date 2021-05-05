#include<bits/stdc++.h>
using namespace std;


int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int val = 999999999;
    for (int i = 0 ;i < arr.size() -1; i++){
        int temp = abs(arr[i] - arr[i+1]);
        val = min (val, temp);
    }
    return val;
}

int main(){
	vector<int> array;
	int a[] = {1, -3, 71, 68, 17};
	int n = sizeof(a)/sizeof(a[0]);
	for(int i = 0; i < n;i++) array.push_back(a[i]);
	cout<<  minimumAbsoluteDifference(array);
	return 0;
}
