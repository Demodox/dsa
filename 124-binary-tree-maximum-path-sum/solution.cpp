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
    int solve(TreeNode* root, int & sum)
    {
       if(root == NULL) return 0;

       int left=max(0 , solve(root->left, sum));
       int right = max(0,solve(root->right, sum));
       
       int currsum = left +right + root->val;
       sum = max( sum, currsum);
       return(max(0,max(left, right) + root->val));

    }
    int maxPathSum(TreeNode* root) {
        if( root ==NULL) return 0;
        
        int sum =0;
        solve( root , sum);
        return sum;
        
    }
};