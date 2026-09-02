class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        n = len(nums)
        pref = [0]*n
        suff = [0]*n
        pref[0] = nums[0]
        suff[n-1] = nums[n-1]

        for i in range (1,n):
            pref[i] = pref[i-1]*nums[i]
        for i in range (n-2, -1, -1):
            suff[i] = suff[i+1]* nums[i]

        result =[0]* n
        for i in range (0,n):
            if i-1<0:
                result[i]= suff[i+1]
            elif i+1 >= n:
                result[i]=pref[i-1]
            else:
                result[i] = suff[i+1] * pref[i-1]

        return result