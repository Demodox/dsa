class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s ) != len(t)):
            return False
        
        mp={}
        for ch in s:
            mp[ch] = mp.get(ch, 0) + 1

        for ch in t:
            mp[ch] = mp.get(ch, 0) -1

        for key , val in mp.items():
            x = key
            y= val
            if( y !=0):
                return False

        return True
        
            
        