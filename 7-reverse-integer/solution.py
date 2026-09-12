class Solution:
    def reverse(self, x: int) -> int:
        result =0
        id = 1
        if x<0:
            id =-1
            x = id*x
        while x>0:
            rem = x%10
            x = x//10
            result = result *10 + rem

        return result *id
        