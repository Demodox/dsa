class Solution {
public:
    bool isCycle(int node ,vector<vector<int>>& adj, vector<bool> &visited,vector<bool> &inRecurtion )
    {
        visited[node] = true;
        inRecurtion[node] = true;

        for( auto &it:adj[node] )
        {
            if(!visited[it] && isCycle(it, adj, visited, inRecurtion))
            {
                return true;
            }
            else if(inRecurtion[it])
            {
                return true;
            }
        }

        inRecurtion[node]= false;
        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);


        vector<bool>visited(numCourses, false);
        vector<bool>inRecurtion(numCourses, false);

        for(auto it : prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        for(int i =0; i<numCourses; i++)
        {
            if(!visited[i] && isCycle(i, adj, visited, inRecurtion))
            {
                return false;
            }
        }
        return true;
        
    }
};