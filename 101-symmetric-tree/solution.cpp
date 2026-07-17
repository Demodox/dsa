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
    bool solve(TreeNode* l, TreeNode*r )
    {
        if(l == NULL && r == NULL ) return true;
        if(l == NULL || r == NULL ) return false;
       
        bool left = solve(l->left, r->right);
        bool right =solve(l->right, r->left);
        
        if(r->val == l->val && left && right )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return solve(root->left, root->right);
        
    }
};