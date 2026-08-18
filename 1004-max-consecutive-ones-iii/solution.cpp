class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result =0;
        int left =0;
        
        int countZero=0;

        for(int right=0;right<nums.size();right++)
        {
            if(nums[right] ==0) countZero++;

            if(countZero > k)
            {
                while(countZero>k && left<nums.size())
                {
                    if(nums[left] ==0) countZero--;
                    left++;
                }
            }

            result = max(result , right-left+1);


        }
        return result;
        
    }
};