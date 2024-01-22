class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        if (n==1) {
            if (citations[0]==0) return 0;
            else return 1;
        } 
        sort(citations.begin(), citations.end());

        for (int i =n;i>=1;i--)
            if (citations[n-i] >= i)
                return i;
            else 
                continue;
        return 0;
    }
};
