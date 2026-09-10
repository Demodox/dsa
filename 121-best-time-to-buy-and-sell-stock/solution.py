class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        p =(float('inf'), -1)
        q = (float('-inf'), -1)
        result = 0

        for i in range(0,n):
        
            if prices[i] < p[0] :
                p =(prices[i], i)

                if p[1] <q[1]:
                    result = max(result , q[0] - p[0])
            
            elif  prices[i] - p[0] >result :
                q =(prices[i], i)
                result = max(result , prices[i] - p[0])
        
        return result



            

        