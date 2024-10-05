public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        
        // HashSet<int> seen = new HashSet<int>();

        // foreach(int num in nums){
        //     if (seen.Contains(num)){
        //         return true;
        //     } else {
        //         seen.Add(num);
        //     }
        // }

        // return false;

        return (nums.Length > nums.Distinct().ToArray().Length);
    }
}
