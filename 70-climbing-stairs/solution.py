class Solution:
    def climbStairs(self, n: int) -> int:
        def solve( n: int, steps :int)->int:

            if steps >n :
                return 0
            if  steps == n :
                return 1
            
            ways = solve(n, steps +2) + solve(n, steps +1)
            return ways

        result = solve(n, 0)
        return result
        