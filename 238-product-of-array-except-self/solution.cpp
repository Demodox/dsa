class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int>pre(n);
        vector<int>suff(n);
        pre[0]= nums[0];
        suff[n-1]= nums[n-1];
        for(int i =1;i<n;i++)
        {
            pre[i] = pre[i-1] * nums[i];
        }
        
        for(int i=n-2; i>=0;i--)
        {
            suff[i]= suff[i+1] *nums[i];
        }

        vector<int>result(n);
        for(int i=0;i<n;i++)
        {
           if(i-1 <0 )
           {
             result[i] = suff[i+1];
           }
           else if(i+1>=n)
           {
            result[i]= pre[i-1];
           }
           else
           {
             result[i] = suff[i+1] * pre[i-1];
           }
        }
        return result;
    }
};