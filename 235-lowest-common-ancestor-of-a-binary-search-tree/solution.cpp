/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* Solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root ==NULL) return NULL;
        if(root == p || root ==q) return root;

        TreeNode* left = Solve(root->left, p,q);
        TreeNode* right = Solve(root->right, p,q);

        if(left && right)
            return root;

        if(left)
            return left;

        return right;

        

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Solve(root, p,q);
        
    }
};