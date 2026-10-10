class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int b)
    {
        int count =0;
        for( int i =0;i< piles.size(); i++)
        {
            if(piles[i] <= b)
            {
                count++;
            }
            else if(piles[i] % b ==0 )
            {
                count += (piles[i] / b);
            }
            else
            {
                count += ((piles[i] / b) +1);
            }
            
        }

        return count <= h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l =1;
        int hi =0; 

        for(int i =0; i<n;i++)
        {
            hi = max(hi, piles[i]);
        }

        while(l < hi)
        {
            int mid = l+(hi-l)/2;

            if(isPossible(piles,h,mid))
            {
                hi = mid;
            }
            else
            {
                l = mid+1;
            }
        }

        return l;

        
    }
};