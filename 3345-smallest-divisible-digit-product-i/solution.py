class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        
        p=n
        while p >= n :
            mul = 1
            org =p
            while p>0:
                rem = p%10
                mul *= rem
                p = p //10
            
            if mul % t == 0:
                return org
            
            p = org +1

        return 0

