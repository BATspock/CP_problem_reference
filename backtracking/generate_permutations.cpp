#include<bits/stdc++.h>

using namespace std;

class Permutations{
    public:

        vector<vector<int>> permute(vector<int> &nums);
};

vector<vector<int>> Permutations ::  permute(vector<int> &nums){
    vector<vector<int>> r;
    sort(nums.begin(), nums.end());
    do {
        r.push_back(nums);

    }while(next_permutation(nums.begin(), nums.end()));

    return r;
}

int main(){

    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans;

    Permutations obj;
    ans = obj.permute(nums);
    cout<<"[";
    for (int i = 0; i<ans.size();i++){
        cout<<"[";
        for (int j = 0; j<ans[0].size();j++){
            cout<< ans[i][j]<<" ";
        }
        cout<<"]";
    } 
    cout<<"]";

    return 0;
}