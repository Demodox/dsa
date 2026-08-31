class Solution {
public:
    int totalsum =0;

    bool solve(vector<int>& nums, int idx, int sum)
    {
        if(idx>= nums.size()) return false;
        if(sum == totalsum/2) return true;

        bool take = solve(nums, idx+1, sum+nums[idx]);
        bool nottake = solve(nums, idx+1, sum);

        return take || nottake;

    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        for( auto it : nums)
        {
            totalsum += it;
        }

        if(totalsum  % 2 != 0) return false;

        return solve(nums, 0,0);
        
    }
};