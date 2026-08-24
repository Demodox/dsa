class Solution {
public:
    vector<vector<int>>dp;
    int  isPalindrome(string s, int i , int j)
    {
        if(i>=j) return 1;
        if(dp[i][j] !=-1) return dp[i][j];

        if(s[i] == s[j])
        {
            return dp[i][j]= isPalindrome(s, i+1,j-1);
        }

        return dp[i][j] =0;
        
    }
    string longestPalindrome(string s) {

        int n = s.length();
        
        dp.resize(n, vector<int>(n, -1));
        int length = 0;
        string ans=s.substr(0,1);

        for(int i =0;i<n;i++)
        {
            for(int j =i+1; j<n;j++)
            {
                if(isPalindrome(s, i , j))
                {
                    if( length < j-i+1)
                    {
                        length = j-i+1;
                        ans=s.substr(i, j-i+1);
                    }
                }
            }
        }
    
        return ans;

    }
};