class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>s(nums.begin(), nums.end());
         int length =0;
         int result = 0;

        for( int n:nums)
        {
            if(s.find(n-1) == s.end())
            {
                int curr = n;
                length=1;
                while(s.find(curr +1) != s.end())
                {
                    curr++;
                    length++;

                }
                result = max(result, length);
            }

        }
        return result;
        
    }
};