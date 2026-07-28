class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums, int idx)
    {
        if(idx == nums.size())
        {
            result.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for ( int i = idx;i<nums.size();i++)
        {
            if(st.find(nums[i]) != st.end())
            {
                continue;
            }
            st.insert(nums[i]);
            swap(nums[idx], nums[i]);
            solve( nums, idx+1);
            swap(nums[idx], nums[i]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        int idx = 0;
        solve( nums, idx);
        return result;
        

        
    }
};