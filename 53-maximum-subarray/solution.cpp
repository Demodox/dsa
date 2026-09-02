class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int result  = sum;
        for(int i =1;i<n;i++)
        {
            if(nums[i] + sum >=0)
            {
                sum += nums[i];
                result = max(sum,  result);

            }
            else
            {
                result = max(sum,  result);
                sum = 0;
            }
        }
        
        return result;
    }
};