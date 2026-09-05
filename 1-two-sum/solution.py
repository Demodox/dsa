class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        mp={}
        for i in range(n):
            sec= target - nums[i]
            if sec  in mp:
                return [mp[sec], i]
            mp[nums[i]] = i

        return []
                

        
        