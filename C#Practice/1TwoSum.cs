public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var arrayIndex = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++){
            arrayIndex[nums[i]] = i;
        }

        for (int i = 0; i < nums.Length; i++){
            int k = target - nums[i];
            if (arrayIndex.ContainsKey(k) && arrayIndex[k]!= i){
                return new int[]{i, arrayIndex[k]};
            }
        }

        return new int[] {};
    }
}
