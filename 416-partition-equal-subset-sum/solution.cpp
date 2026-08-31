class Solution {
public:
    int totalsum =0;
    vector<vector<int>>dp;
    bool solve(vector<int>& nums, int idx, int sum)
    {
        if(idx>= nums.size() ) return false;
        if(sum == totalsum/2) return true;

        if(dp[idx][sum] !=-1) return dp[idx][sum];
        bool take = solve(nums, idx+1, sum+nums[idx]);
        bool nottake = solve(nums, idx+1, sum);

        return dp[idx][sum] = take || nottake;

    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        for( auto it : nums)
        {
            totalsum += it;
        }

        if(totalsum  % 2 != 0) return false;

        dp.resize(n+1, vector<int>(totalsum, -1));

        return solve(nums, 0,0);
        
    }
};