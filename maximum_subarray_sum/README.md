Given an array of n numbers, our task is to calculate the maximum subarray sum, i.e., the largest possible sum of a sequence of consecutive values in the array. 
Surprisingly, it is possible to solve the problem in O(n) time, which means that just one loop is enough. The idea is to calculate, for each array position, the maximum sum of a subarray that ends at that position. After this, the answer for the problem is the maximum of those sums.
Consider the subproblem of finding the maximum-sum subarray that ends at position k. There are two possibilities:
1. The subarray only contains the element at position k.
2. The subarray consists of a subarray that ends at position k −1, followed by the element at position k.
In the latter case, since we want to find a subarray with maximum sum, the subarray that ends at position k −1 should also have the maximum sum. Thus, we can solve the problem  efficiently by calculating the maximum subarray sum for each ending position from left to right.