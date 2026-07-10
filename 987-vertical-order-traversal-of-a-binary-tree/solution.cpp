/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>>result;
        map<int, map<int, multiset<int>>>mp; // col , row, val
        queue<pair<TreeNode*, pair<int,int>>>q; // node , col , row
        q.push({root,{0, 0}});
        while(!q.empty())
        {
            int n= q.size();
            while(n--)
            {
                auto temp =q.front();
                q.pop();

                TreeNode* node = temp.first;
                int col = temp.second.first;
                int row = temp.second.second;

                mp[col][row].insert(node->val);
                

                if(node->left)
                {
                    q.push({node->left, {col-1,row+1}});
                }
                if(node->right)
                {
                    q.push({node->right, {col+1 , row +1}});
                }

            
            }
        }

        for(auto col :mp)
        {
            vector<int>temp;
            for(auto row: col.second)
            {
                for(int val : row.second)
                {
                    temp.push_back(val);
                }

            }
            result.push_back(temp);
            
        }

        return result;
        
    }
};