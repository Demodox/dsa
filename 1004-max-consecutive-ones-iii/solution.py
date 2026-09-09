class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dq = deque()

        result = 0
        l = 0

        for r in range(0,n):
            if nums[r] == 0:
                dq.append(r)
                
            
            if len(dq) >k:
                l =dq[0] +1
                dq.popleft()
                
            result = max(result, r-l+1) 
        
        return result


        