class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)

        sum = 0
        count =0
        result = nums[0]
        for num  in nums :
            if num + count >num :
                count += num
                result = max(result , count) 
                 
            else:
                count = num
                result = max(result , count) 
                 
        return result         
        