class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0

        if len(prices) == 1:
            return 0

        minprice = prices[0]
        for i in range(0, len(prices)):
            if(prices[i] < minprice):
                minprice = prices[i]
            profit = max(profit, prices[i] - minprice)
    


        return profit