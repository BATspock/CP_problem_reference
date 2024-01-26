class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int longestSeq = 0;
        while(end < n){
            //if it is a 0 flip if k is >0
            if (nums[end] == 0 && k>0){
                end++;
                k--;
                longestSeq = max(longestSeq, end - start);
            }
            else if (nums[end] == 1){
                end++;
                longestSeq = max(longestSeq, end - start); 
            }
            else if (nums[end] == 0 && k==0){
                while(start < n && nums[start]!=0){
                    start++;
                }
                start++;
                k++;
            }
        }

        return longestSeq;
    }
};
