class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int t = 0;
        int d= m-1;
        int l =0; // left 
        int r = n-1;

        int step = 0;

        vector<int>result;

        while(t<=d && l<=r)
        {

            if(step == 0)
            {
                for(int i =l; i<=r; i++)
                {
                    result.push_back(matrix[t][i]);
                }
                    t++;
                   
            }

            if(step == 1)
            {
                for(int i =t; i<=d; i++)
                {
                    result.push_back(matrix[i][r]);
                    
                }
                r--;
                
            }

            if(step == 2)
            {
                for(int i =r; i>=l; i--)
                {
                    result.push_back(matrix[d][i]);
                }
                    d--;
                    
            }
            if(step == 3)
            {
                for(int i =d; i>=t; i--)
                {
                    result.push_back(matrix[i][l]);
                }
                    l++;
                    
            }

            step = (step+1)%4;
            
        }

        return result;
        
    }
};