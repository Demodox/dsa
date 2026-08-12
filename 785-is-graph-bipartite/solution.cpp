class Solution {
public:
    bool isbipartiteDFS(int node, vector<vector<int>>& graph,vector<int> &visited , int set )
    {
        visited[node] = set;

        for(auto it : graph[node])
        {
            if(visited[it] == set) // both adjacent node belongs to same set
            {
                return false;
            }

            if(visited[it] == -1)
            {
                int s = 1-set;
                if(isbipartiteDFS(it, graph, visited, s) == false)
                {
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,-1);

        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                if(isbipartiteDFS(i, graph, visited, 1) == false) return false;
            }
        }
        return true;
    }
};