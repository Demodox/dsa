class Solution {
public:
    int solve( vector<int>& nums, int piv, int r )
   {
        int i = piv +1;
        int j = r;
        while(i<=j)
        {
            if(nums[i] < nums[piv] && nums[j]>nums[piv])
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            else
            {
                if( nums[i]>= nums[piv])
                {
                    i++;

                }
                if( nums[j]<= nums[piv])
                {
                    j--;
                }

            }
            
        }
        swap( nums[piv], nums[j]);
        return j;
   }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r =nums.size();

        int piv = 0; // Pivert index

        while(true)
        {
            piv = solve(nums, l,r);
            if(piv == k-1)
            {
                break;
            }
            else
            {
                if(piv > k-1)
                {
                    r = piv-1;
                }
                else
                {
                    l = piv +1;
                }
            }
        }


        return nums[piv];
        
    }
};