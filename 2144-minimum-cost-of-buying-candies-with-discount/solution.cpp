class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int i =n-1;
        int totalcost =0;

        while(i>=0)
        {
            if(i-2 >=0)
            {
                totalcost += cost[i]+cost[i-1];
                i=i-3;
            }
            else
            {
                break;
            }
        }
        while(i>=0)
        {
           
            totalcost += cost[i];
            i--;
        }
            
        return totalcost;


        
    }
};