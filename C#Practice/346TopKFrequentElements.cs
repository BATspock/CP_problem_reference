public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        PriorityQueue<int, int> heap = new();
        Dictionary<int, int> sums = new();
        var ret = new int[k];
        foreach (var num in nums) {
            sums[num] = sums.GetValueOrDefault(num, 0) + 1;
        }

        foreach (var (key, value) in sums) {
            heap.Enqueue(key, value);
            if (heap.Count > k) heap.Dequeue();
        }

        for (var i = 0; i < k; i++) {
            ret[i] = heap.Dequeue();
        }

        return ret;
    }
}
