class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> m;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        
        for (auto c: nums)
            m[c]++;
        
        
        for (auto it: m){
            pq.push({it.second, it.first});
        }
        
        while (k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
