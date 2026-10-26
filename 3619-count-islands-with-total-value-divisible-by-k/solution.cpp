class Solution {
public:
    vector<vector<int>>dir = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
    long long bfs(vector<vector<int>>& grid, int r, int c,vector<vector<bool>>& visited ) 
    {

        
        visited[r][c] = true;
        long long sum = grid[r][c];

        for( int i =0; i<4; i++)
        {
            int rx =r+ dir[i][0];
            int cx = c+ dir[i][1];
            if(rx  >=0 && rx  < grid.size() && cx >=0 && cx < grid[0].size() && !visited[rx][cx] && grid[rx][cx] !=0)
            {
                sum += bfs(grid, rx, cx, visited);
            }
        }    

        return sum;
        
    }


    int countIslands(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int result = 0;

        for(int i = 0; i<m;i++)
        {
            for( int j =0; j<n ; j++)
            {   
                if( grid[i][j] !=0 && !visited[i][j])
                {
                    long long sum = bfs(grid, i, j , visited);
                    if(sum %k == 0) result++;

                }
               
            }
        }

        return result;

    }
};