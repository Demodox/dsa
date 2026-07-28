class Solution {
public:
    vector<vector<int>>result;
    int n;
    void solve(vector<int>& nums, int idx)
    {
        if(idx == n)
        {
            result.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for ( int i = idx; i<n ;i++)
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
        n= nums.size();
        solve( nums, 0);
        return result;
        

        
    }
};