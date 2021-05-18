#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    
    unordered_set<char> in_q;
    
    int max_length = 0, i=0, j=0;
    
    while(j < s.length()){
        cout<<"i : "<<i<<" j : "<<j<<endl;
        if (in_q.empty() || in_q.find(s[j]) == in_q.end()){
            //cout<<"inserting: " << s[i] << " value of i:" << i << endl;
            cout<<"in if block\n";
            in_q.insert(s[j]);
            if (j-i + 1 > max_length) max_length = j-i+1;
            j++;
        }

        else{
            while(s[i]!=s[j]){
                //cout<< " value of i: " << i <<" front: " <<q.front()<<" s[i]: " << s[i]<< endl;
                in_q.erase(in_q.find(s[i]));
                i++;                                
            }
            cout<<"in else block\n";
            j++;i++;
        }
    } 
    return max_length;  
}

int main(){
    string str = "a";
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}
