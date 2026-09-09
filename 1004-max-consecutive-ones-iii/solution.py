class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:

        n = len(nums)
        l = 0
        countZero = 0
        result = 0

        for r in range(0,n):
            if nums[r] == 0 :
                countZero +=1
            
            if countZero >k:
                while countZero>k and l<n:
                    if nums[l] == 0:
                        countZero -=1
                    
                    l+=1
            
            result = max(result,r-l+1)

        return result
    


        