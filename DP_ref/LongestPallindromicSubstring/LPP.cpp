class Solution {
public:
    
    pair<int, int> pallindrome(string s, int i, int j){
        pair<int, int> ans(-1,-1);
        
        if (i<0 || j>s.size()-1) return ans;
        
        if (s[i] != s[j]) return ans;
        
        
        
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        
        ans.first = i+1;
        ans.second = j-1;
        
        return ans;
    }
    
    
    
    
    string longestPalindrome(string s) {
        
        int curr_max = 1;
        string ans = s.substr(0,0);
        
        for (int i = 0;i<s.size();i++){
            pair<int, int> diff,same;
            
            diff = pallindrome(s, i, i+1);
            same = pallindrome(s, i, i);
            
            
             int l_diff = diff.second - diff.first + 1;
             int s_same = same.second - same.first + 1;
            
            
            
            if (l_diff > curr_max || s_same > curr_max){
                
                
                if (l_diff>s_same){
                    
                    ans = s.substr(diff.first, l_diff);
                    curr_max  = l_diff;
                }
            
            
                else{
                    
                    
                    ans = s.substr(same.first, s_same);
                    curr_max = s_same;
                }
            
             
            
            }
           //cout<<curr_max; 
            
        }
        
        if (curr_max == 1) return s.substr(0,1);
        
        return ans;
        
        
        
    }
};
