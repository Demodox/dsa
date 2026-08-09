class Solution {
public:
    // Using BFS 
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>count(numCourses, 0);

        for(auto it : prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            count[u]++;
        }

        queue<int>q;

        for(int i =0; i<numCourses; i++)
        {
            if(count[i] == 0)
            {
                q.push(i);
            }
            
        }

        vector<int>result;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto it : adj[node])
            {
                count[it]--;
                if(count[it] == 0)
                {
                    q.push(it);
                }
            }

        }

        if(result.size()  == numCourses) return true;
        return false;
       
        
    }
};