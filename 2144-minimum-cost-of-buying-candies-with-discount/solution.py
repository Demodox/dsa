class Solution:
    def minimumCost(self, cost: list[int]) -> int:
        
        cost.sort()

        n = len(cost)
        totalCost =0

        j = n-1
        while j>=0 :
            totalCost +=cost[j]
            if j-1 >=0 and j-2 >=0 :
                totalCost +=cost[j-1]
                j = j -3
                continue
            elif j-1 >=0 :
                totalCost +=cost[j-1]
                j= j-2
                continue

            j =j-1

        return totalCost

