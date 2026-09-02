class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftMax =0;
        int rightMax =0;
         int result =0;

        while(left<=right)
        {
            if(height[left] >=height[right])
            {
                if(height[right] < rightMax)
                {
                    result +=rightMax - height[right];
                    
                }
                else
                {
                    rightMax = height[right];
                }

                right --;

            }
            else
            {

                if(height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    result += leftMax - height[left];
                }
                
                left++;
            }
            
        }

        return result;
        
    }
};