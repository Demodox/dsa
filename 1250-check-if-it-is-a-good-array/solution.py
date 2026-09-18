class Solution:
    def gcd(self, a,b):

        while b!=0 :
            a,b = b , a%b
        
        return a


    def isGoodArray(self, nums: list[int]) -> bool:

        g = nums[0]
        for i in range(1, len(nums)):
            g = self.gcd(g, nums[i])
            if g ==1:
                return True

        return g == 1        