class Solution {
public:
    // Topolocical sorting  using dfs

    bool isCycle(int node, vector<vector<int>>& adj, vector<bool> &visited, vector<bool> &inRecurtion, stack<int> &st )
    {
        visited[node] = true;
        inRecurtion[node] = true;

        for(auto &it : adj[node])
        {
            if(!visited[it] && isCycle(it, adj, visited, inRecurtion, st))
            {
                return true;
            }
            else if(inRecurtion[it] == true)
            {
                return true;
            }
        }
        st.push(node);
        inRecurtion[node] = false;

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<bool>visited(numCourses, false);
        vector<bool>inRecurtion(numCourses, false);

        stack<int>st;

        for(auto it :prerequisites )
        {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        for(int i =0; i<numCourses; i++)
        {
            if(!visited[i] && isCycle(i, adj, visited,inRecurtion, st) )
            {
                return {};
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