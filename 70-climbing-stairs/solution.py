class Solution:
    def climbStairs(self, n: int) -> int:

        dp = [-1]* (n+1)
        def solve( n: int, steps :int)->int:

            if steps >n :
                return 0
            if  steps == n :
                return 1

            if dp[steps] !=-1 :
                return dp[steps]
            
            ways = solve(n, steps +2) + solve(n, steps +1)
            dp[steps]= ways
            return ways

        result = solve(n, 0)
        return result
        