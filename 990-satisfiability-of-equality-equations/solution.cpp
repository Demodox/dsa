class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findParent(int i)
    {
        if(parent[i] == i) return i;

        return parent[i] = findParent(parent[i]);
    }
    void Union(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u == parent_v ) return;

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

    bool equationsPossible(vector<string>& equations) {
        

        parent.resize(26);
        rank.resize(26,0);
        for(int i =0;i<26;i++)
        {
            parent[i] = i;
        }

        for(auto it : equations)
        {
            int u = it[0] -'a';
            int v = it[3] -'a';
            if(it[1] == '=')
            {
                Union(u,v);
            }

        }

        for(auto it : equations)
        {
            int u = it[0] -'a';
            int v = it[3] -'a';

            if(it[1] == '!')
            {
                int parent_u = findParent(u);
                int parent_v = findParent(v);
                if(parent_u == parent_v) return false;
            }

        }

        return true;
        
    }
};