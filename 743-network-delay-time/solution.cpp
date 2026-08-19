class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }

        vector<int>result(n+1);

        for(int i =0;i<=n;i++)
        {
            result[i] = INT_MAX;
        }
        result[k]=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int w = it.second;

                if(d+w <result[adjnode])
                {
                    result[adjnode] = d+w;
                    pq.push({d+w, adjnode});
                }
            }
        }

        int ans =0;
        for( int i =1; i<=n;i++)
        {
            if(result[i] == INT_MAX) return -1;
            ans = max(ans, result[i]);
        }
        
        return ans;
    }
};