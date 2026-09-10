class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        result = 0
        prefixMin = prices[0]
        for i in range (0, n):
            diff = prices[i] - prefixMin
            result = max(result,diff )
            prefixMin = min(prefixMin, prices[i])

        return result



            

        