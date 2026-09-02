class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = 0
        right = n-1
        leftMax =0
        rightMax=0
        result=0

        while left <=right:
            if height[left] <= height[right]:
                if height[left] < leftMax:
                    result = result + (leftMax-height[left])
                else:
                    leftMax=height[left]

                left=left+1
            else:
                if height[right] <rightMax:
                    result= result + (rightMax - height[right])
                else:
                    rightMax = height[right]

                right = right-1
        
        return result
        