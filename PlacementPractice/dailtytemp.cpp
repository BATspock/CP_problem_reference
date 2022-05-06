class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> s;
        vector<int> ans(temp.size());
        
        s.push({0,temp[0]});

    
        for (int i = 1;i<temp.size();i++){
            
            pair<int,int> t(i, temp[i]);
            
            
            while(!s.empty()&&t.second>s.top().second){
                ans[s.top().first] = t.first-s.top().first;
                s.pop();
            }
            
            s.push(t);
        }
        
    return ans;
    }
};
