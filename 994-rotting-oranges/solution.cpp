class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();

        queue<pair<int, int>>q;
        int freshCount=0;

        for( int i =0;i<m;i++)
        {
            for( int j =0; j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    freshCount ++;
                }
            }
        }
        int time =0;
        vector<vector<int>> dir{{-1, 0}, {0, 1}, {1,0},{0,-1}};
        while(!q.empty())
        {
            int p = q.size();
            if(freshCount == 0) return time;
            time++;
            while(p--)
            {
                int r = q.front().first; 
                int c = q.front().second; 
                q.pop();
                for(auto it : dir)
                {
                    int new_r =it[0]+r;
                    int new_c =it[1]+c;
                    if(new_r >=0 && new_r<m && new_c>=0 && new_c<n && grid[new_r][new_c] ==1)
                    {
                        grid[new_r][new_c] = 2;
                        freshCount --;
                        q.push({new_r, new_c});
                    }
                }

            }
            
        }
        return freshCount >0 ? -1 :time;
    }
};