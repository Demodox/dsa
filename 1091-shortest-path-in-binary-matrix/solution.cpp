class Solution {
public:
    // using BFS
    vector<vector<int>>dir{{-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] ==1) return -1;

        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int length = 1;

        while(!q.empty())
        {
            int p = q.size();
            while(p--)
            { 
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r == m-1 && c == n-1) return length;

                for( auto it :dir)
                {
                    int new_r = r +it[0];
                    int new_c = c +it[1];

                    if(new_r >= 0 && new_r <m  && new_c>=0 && new_c<n &&  grid[new_r][new_c] == 0)
                    {
                        q.push({new_r,new_c});
                        grid[new_r][new_c]=1;
                    }
                }
                
               
            }
            length++;
            
        }
        
        return -1;
    }
};