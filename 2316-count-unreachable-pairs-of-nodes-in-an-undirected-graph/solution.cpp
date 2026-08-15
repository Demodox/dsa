class Solution {
public:
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
    long long countPairs(int n, vector<vector<int>>& edges) {

        rank.resize(n,0);
        parent.resize(n);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        

        for(auto it :edges )
        {
            if(findParent(it[0]) != findParent(it[1]))
            {
                Union(it[0], it[1]);
            }

        }

        // Create map to calculate no of elements inside of a set
        unordered_map<int, int>mp;

        for(int i =0;i<n;i++)
        {
            int p  = findParent(i);
        
            mp[p]++;
        }

        long long result=0;
        // calculate pairs 
        long long  remainingNode = n;
        for(auto it : mp)
        {
            long long c = it.second;
            result += (remainingNode -c) * (c) ;
            remainingNode -= c;
            
        }

        return result;

        
    }
};