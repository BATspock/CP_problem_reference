class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for (int i =0;i<strs.size();i++){
            string temp = strs[i];
            
             sort(temp.begin(), temp.end());
            
//             cout<<temp<<" "<<strs[i];
//             cout<<'\n';
            
            if (m.find(temp)==m.end()) {
                m[temp].push_back(strs[i]);
            }
            
            else{
                m[temp].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> v;
        
        for (auto it: m){
            v.push_back(it.second);
        }
        
        return v;
    }
    
};
