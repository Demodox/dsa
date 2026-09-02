class Solution:
    def isPalindrome(self, s:str, i:int, j:int, dp : list)->int:

        if i>=j : return 1
        
        if dp[i][j] !=-1:
            return dp[i][j]

        if s[i] == s[j]:
            dp[i][j] = self.isPalindrome(s, i+1, j-1, dp)
            return dp[i][j]
        
        dp[i][j] =0
        return dp[i][j]




    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[-1] * (n+1) for _ in range(n+1)]
        length = 0
        result = s[0]
        for i in range (n):
            for j in range(i,n):
                if self.isPalindrome(s, i, j, dp):
                    if j-i+1 > length :
                        length = j-i+1
                        result = s[i:j+1]

        return result
        