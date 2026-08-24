class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums, int i)
    {
        if( i >nums.size()-1) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i]= max(nums[i] +solve( nums, i+2), solve(nums, i+1) );
    }
    int rob(vector<int>& nums) {

        dp.resize(nums.size(),-1); 
        int result = solve(nums, 0);
        return result;
        
    }
};