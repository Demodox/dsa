class Solution:
    def reverse(self, x: int) -> int:
        result =0
        INT_MAX = 2** 32 -1
        INT_MIN = - 2**32
        id = 1
        if x<0:
            id =-1
            x = id*x
        while x>0:
            rem = x%10
            x = x//10
            result = result *10 + rem

        if result * id <INT_MIN or result *id > INT_MAX:
            return 0
        return result *id
        