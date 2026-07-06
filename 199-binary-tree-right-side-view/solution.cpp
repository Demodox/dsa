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
    vector<int>result;
    void solve(TreeNode* root)
    {
        if(root == NULL ) return;
        queue<TreeNode*>q;
        q.push(root);
        while(! q.empty())
        {
            int n = q.size();
            TreeNode* curr;
            
            while(n--)
            {
                curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            result.push_back(curr->val);


        }
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root);
        return result;
        
    }
};