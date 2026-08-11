class Solution {
public:
    // Using DFS
    int n;
    void dfs(int node , vector<vector<int>>& isConnected, vector<int>& visited )
    {
        visited[node] = true;
        for(int i = 0;i<n;i++)
        {
            if(!visited[i] && isConnected[node][i] == 1 )
            {
                dfs(i, isConnected, visited);
            }
            
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<int>visited(n,false);
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(!visited[i] )
            {
                count++;
                dfs(i, isConnected, visited);       
            }      
        }
        

        return count;

    }
};