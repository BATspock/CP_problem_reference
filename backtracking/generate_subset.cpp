#include<bits/stdc++.h>

using namespace std;

class Solution {
    
    void helper(int index, int N, vector<int>& subset, vector<vector<int>>& res, vector<int> &arr){
        res.push_back(subset);
        
        for (int i = index;i<N;i++){
            subset.push_back(arr[i]);
            helper(i+1, N, subset, res, arr);
            subset.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        helper(0, nums.size(), subset, res, nums);
        
        return res;
    }
};

int main(){

    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans;

    Solution obj;
    ans = obj.subsets(nums);
    cout<<"[";
    for (int i = 0; i<ans.size();i++){
        cout<<"[ ";
        for (int j = 0; j<ans[i].size();j++){
            cout<< ans[i][j]<<" ";
        }
        cout<<"]";
    } 
    cout<<"]";

    return 0;
}