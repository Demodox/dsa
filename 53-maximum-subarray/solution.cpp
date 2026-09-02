class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int result  = nums[0];
        for(int i =1;i<n;i++)
        {
            
            if(nums[i] + sum > nums[i])
            {
                sum += nums[i];
                result = max(result,sum);

            }
            else
            {
                sum = nums[i];
                result = max(result,sum);
            }
            
        }
        
        return result;
    }
};