class Solution {
public:

    int  solve(vector<vector<int>> &adj, vector<bool>& hasApple, int node , int parent )
    {
        int total =0;
        for(auto it : adj[node])
        {
            if(it == parent) continue;

            int time = solve( adj, hasApple, it, node);

            // node has the apple
            if(hasApple[it] || time >0)
            {
                
                total += time +2;
            }
            
        }

        return total;

    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        
        vector<vector<int>> adj(n);
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

         return solve(adj, hasApple, 0,-1);
        
        
    }
};