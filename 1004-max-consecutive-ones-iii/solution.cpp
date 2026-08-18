class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        int left=0; 
        int right =0;
        deque<int>dq;
        while(right<nums.size())
        {
            if(nums[right] == 0)
            {
                dq.push_back(right);
            }

            if(dq.size()>k)
            {
                left = dq.front() + 1;
                dq.pop_front();
            }
            result = max(result,right - left +1);
            right++;
        }
        return result;
    }
};