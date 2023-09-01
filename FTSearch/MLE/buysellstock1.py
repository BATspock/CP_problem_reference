class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n, maxPrice = len(prices), -1
        maxUntil = [-1 for _ in range(n)]

        for i in range(n):
            maxPrice = max(prices[n-i-1], maxPrice)
            maxUntil[n-i-1] = maxPrice
        
        maxProfit = -1

        for i in range(n):
            maxProfit = max(maxProfit, maxUntil[i] - prices[i])
        
        return 0 if maxProfit < 0 else maxProfit
