class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        st = set()
        n= len(s)
        result = 0
        count =0
        for c in s:
            if c not in st :
                st.add(c)
                count +=1
                result = max(result, count)
            else:
                result = max(result, count)
                count = 1
                st.clear()
                st.add(c)

        return result


        