class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count =0
        mp={}
        mp[0]=1
        prefix = 0
        for i in range(n):
            prefix +=nums[i]
            
            num = prefix -k
            if num in mp:
                count +=mp[num]
            
            mp[prefix] = mp.get( prefix, 0) +1

        return count
            



        