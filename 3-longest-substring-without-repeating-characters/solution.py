class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        n= len(s)
        result = 0
        count =0
        mp ={}
        for i in range(0,n):
            if s[i] not in mp:
                mp[s[i]] = i
                count +=1
                result = max(result, count)
            else:
                result = max(result, i - mp[s[i]])
                count =i - mp[s[i]]
                mp[s[i]] = i
                result = max(result, count)
            

        return result


        