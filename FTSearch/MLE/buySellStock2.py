
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit, cur = 0, prices[0]
        
        for price in prices:
            if price < cur:
                cur = price
            if price - cur > 0:
                profit+= price - cur
                cur = price
        return profit
