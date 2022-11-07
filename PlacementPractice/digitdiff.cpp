#include<bits/stdc++.h>

using namespace std;

//create a class solution
class Solution {
  
    public:

    //create a function to count distinct pairs i,j such that nums[i] and nums[j] have same number of digits
    // and only one digit is different
    int countPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(isValid(nums[i], nums[j])) {
                    count++;
                }
            }
        }
        return count;
    }

    // check if two numbers have same number of digits and only one digit is different
    bool isValid(int a, int b) {
        int count = 0;
        while(a > 0 || b > 0) {
            if(a % 10 != b % 10) {
                count++;
            }
            a /= 10;
            b /= 10;
        }
        return count == 1;
    }

};

int main(){
    vector<int> v{1,151,241,1,9,22,351};
    obj = Solution();
    return 0;
}