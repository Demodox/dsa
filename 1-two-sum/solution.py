class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        mp ={}
        
        for i in range(0,n):
            
            dif =target - nums[i]
            if dif in mp:
                return [i, mp[dif]]
            
            mp[nums[i]]=i
         
        return []