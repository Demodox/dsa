class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();

        int result =0;

        for(int i =0;i<n;i++)
        {
            unordered_map<int, int>mp;
            unordered_map<int, int>rank;
            int balance =0; // keep track of frequency staircase

            for(int j =i ;j<n; j++)
            {
               if( mp.find(nums[j]) == mp.end())
               {
                    int r = mp.size() +1;
                    mp[nums[j]] =1;
                    rank[nums[j]] =r;

                    if(mp[nums[j]] != r)
                    {
                        balance ++;
                    }

               }
               else
               {
                    int r = rank[nums[j]];
                    if (mp[nums[j]] != r) balance--;
                    mp[nums[j]]++;
                    if (mp[nums[j]] != r) balance++;
                
               }

               if( balance ==0) result++;
            }
        }
        return result;

        
    }
};