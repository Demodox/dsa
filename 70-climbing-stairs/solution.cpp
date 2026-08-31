class Solution {
public:
   
    vector<int>dp;
    int solve( int n , int steps)
    {
        if(steps == n) return 1;
        if(steps>n) return 0;

        if(dp[steps] != -1)
        {
            
            return dp[steps];
        }

         return dp[steps] = solve(n,steps+1) +solve(n,steps+2);

    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        int result = solve(n,0);
        return result;
        
    }
};