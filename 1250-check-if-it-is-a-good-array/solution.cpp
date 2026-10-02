class Solution {
public:
    int gcd( int a, int b)
    {
        
        while( b >0)
        {
            int temp =  a;
             a = b;
             b = temp%b;

        }

        return a;
    }
    bool isGoodArray(vector<int>& nums) {

         int g = nums[0];
        for( int i = 1 ; i<nums.size(); i++)
        {
            g = gcd(g, nums[i]);
            if( g == 1) return true;
        }
        
        return g ==1;
    }
};