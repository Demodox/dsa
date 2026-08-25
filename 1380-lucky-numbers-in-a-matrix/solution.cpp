class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        vector<int>RowMin(r,INT_MAX);
        vector<int>ColMax(c,INT_MIN);

        for(int i =0;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                RowMin[i]= min(RowMin[i], matrix[i][j]);
                ColMax[j]= max(ColMax[j], matrix[i][j]);

            }
        }
        vector<int>result;

        for(int i =0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(RowMin[i] == ColMax[j] ) result.push_back(ColMax[j]);
            }
        }

        return result;

       

        
    }
};