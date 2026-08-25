class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size(); 

        vector<vector<int>> adj(n);
        vector<int>count(n,0); // to calculate no of nodes connected to a node

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            count[u]++;
            count[v]++;
        }

        // Delete leaves nodes with no coins

        queue<int>q;
        for(int i =0;i<n;i++)
        {
            if(count[i] == 1 && coins[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count[node] =0;

            for(auto it :adj[node])
            {
                if(count[it] == 0) continue;
                count[it]--;

                if( count[it] == 1 && coins[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // delete two leaves with coinp resent
        

        for(int j =0;j<2;j++)
        {

            queue<int>leaves;
            for(int i =0;i<n;i++)
            {
                if(count[i] == 1 ) leaves.push(i);
            }

            while(!leaves.empty())
            {
                int node = leaves.front();
                leaves.pop();
                count[node]=0;

                for(auto it :adj[node])
                {
                    if(count[it] == 0) continue;
                    count[it]--;
                }
            }

        } 


        // Cal available nodes
        int totalNodes=0; 
        for(auto it : count)
        {
            totalNodes+= it;

        }

        totalNodes /=2;

        return totalNodes*2;




    }
};