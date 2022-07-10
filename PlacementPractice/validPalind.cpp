class Solution {
public:
    bool isPalindrome(string str) {
        transform(str.begin(), str.end(), str.begin(),::tolower);
        str.erase(remove_if(str.begin(), str.end(), ::ispunct), str.end());
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        
        int i =0,j = str.size()-1;
        
        while(i<=j){
            if (str[i] == str[j]) { i++;j--;}
            else return false;
        }
        
        return true;
    }
};
