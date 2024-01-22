class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int first = 0;
        int last = nums.size()-1;
        int operations = 0;

        if (nums.size()==1){
           return 0;
        }

        while(first<last){

            int sum = nums[first]+nums[last];

            if ( sum == k) {
                operations++;
                first++;
                last--;
            }
            else if (sum > k){
                last--;
            }
            else {
                first++;
            }
        }

        return operations;
    }
};
