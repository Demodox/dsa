class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        m = len(text1)
        n = len(text2)
        #Define dp
        dp = [[-1] * (n+1) for _ in range(m+1)]

        def solve(i, j):
            if i>=m or j>=n:
                return 0

            if dp[i][j] != -1 :
                return dp[i][j]

            if text1[i] == text2[j] :
                 dp[i][j]= 1 + solve( i + 1, j + 1)
                 return dp[i][j]
            else:
                dp[i][j] =max(solve(i,j+1), solve(i+1, j))
                return dp[i][j]
            

        return solve(0,0)
        