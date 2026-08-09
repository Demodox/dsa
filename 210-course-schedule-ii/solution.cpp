class Solution {
public:
    // Topolocical sorting  using dfs

    void dfs(int node, vector<vector<int>>& adj, vector<bool> &visited, stack<int> &st )
    {
        visited[node] = true;

        for(auto &it : adj[node])
        {
            if(!visited[it])
            {
                dfs(it, adj, visited, st);
            }
        }
        st.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<bool>visited(numCourses, false);

        stack<int>st;

        for(auto it :prerequisites )
        {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        for(int i =0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int>ans;
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        

    }
};