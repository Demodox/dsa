class Solution {
public:
    // Useing DSU 
    vector<int>parent;
    vector<int>rank;
    int findParent(int i)
    {
        if(i == parent[i]) return i;

        return parent[i] = findParent(parent[i]);
    }
    void Union(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u == parent_v) return;
        if(rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else if(rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else
        {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);

        if(connections.size() <n-1) return -1;

       
        for(int i =0;i<n;i++)
        {
            parent[i]=i;
        }

        for(auto it :connections )
        {
            int u = findParent(it[0]);
            int v = findParent(it[1]);
            if(u !=v)
            {
                Union(u,v);
            }
        }

        // Count total no of sets or components

        int sets=0;
        for(int i =0;i<n;i++)
        {
            if(parent[i] == i) sets++;
        }
        
        return sets-1;
    }
};