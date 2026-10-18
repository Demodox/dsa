class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count =0

        for i in range(n):
            j =i
            sum =0
            while j<n:
                sum = sum+nums[j]
                if sum == k:
                    count +=1
                j +=1
        
        return count
        