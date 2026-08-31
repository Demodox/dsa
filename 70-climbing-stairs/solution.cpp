class Solution {
public:
    int result =0;
    void solve( int n , int steps)
    {
        if(steps == n)
        {
            result++;
            return;
        } 
        if(steps>n) return;

        solve(n,steps+1);
        solve(n,steps+2);

    }
    int climbStairs(int n) {
        solve(n,0);
        return result;
        
    }
};