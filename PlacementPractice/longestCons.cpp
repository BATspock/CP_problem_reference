class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size()==0) return 0;
        
        unordered_set <int> s(nums.begin(), nums.end());
        int max_len = 1;
        
        for (int i =0;i<nums.size();i++){
            
            int count=1;
            
            if (s.find(nums[i]-1)!=s.end())
                continue;
            
            
            else{
                
                int check = nums[i];
                
                while(s.find(check+1)!=s.end()){
                    count++;
                    check++;
                }
            }
            
            max_len=max(max_len, count);
            
        }
        
        return max_len;
    }
};
