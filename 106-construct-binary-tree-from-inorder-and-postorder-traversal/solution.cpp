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
    unordered_map<int, int> mp;
    TreeNode* solve( vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx)
    {
        if( start > end) return NULL;

        int i = mp[postorder[idx]];
        
        TreeNode* root = new TreeNode(postorder[idx]);
        idx--;
        root->right = solve(inorder, postorder, i+1, end, idx);
        root->left = solve(inorder, postorder, start, i-1, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n= inorder.size();
        
        for( int i=0;i<n; i++)
        {
            mp[inorder[i]]=i;
        }

        int idx = n-1;
        TreeNode *root = solve(inorder, postorder, 0, n-1, idx);
        return root;
        
    }
};