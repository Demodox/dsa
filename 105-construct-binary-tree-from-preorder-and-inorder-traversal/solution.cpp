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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int left, int right, int &idx)
    {
        if(left > right) return NULL;
        int i = left;
        for( ; i<=right; i++)
        {
            if(preorder[idx] == inorder[i]) break;
        }
        idx++;
        TreeNode* root = new TreeNode(preorder[idx -1]);
        root->left = solve(preorder,inorder, left, i-1, idx );
        root->right = solve(preorder,inorder, i+1, right, idx);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int n = inorder.size();
         int idx =0;
        TreeNode* root =  solve(preorder,inorder, 0,n-1,idx);
        return root;
        
    }
};