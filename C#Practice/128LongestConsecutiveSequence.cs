public class Solution {
    public int LongestConsecutive(int[] nums) {
        
        HashSet<int> set = new HashSet<int>(nums);
        // create set of elements
        int longest = 0;
        foreach(int num in nums){
            if (set.Contains(num - 1)){
                continue;
            } else {
                int cur = num;
                int curLen = 1;
                while(set.Contains(cur)){
                    longest = Math.Max(longest, curLen);
                    cur++;
                    curLen++;
                }
            }
        }

        return longest;

        // for each elements in the set, check if element-1 is present
        // if element -1 is present, continue
        // else start iterating and find for element + 1
    }
}
