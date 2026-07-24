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
    struct Node
    {
        int sum;
        bool bst;
        int minNode;
        int maxNode;
    };

    int ans =0;
    Node solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return {0,true,INT_MAX, INT_MIN};
        }
        Node left = solve(root->left);
        Node right = solve(root->right);

        // Check Bst Property
        if(left.bst && right.bst && root->val >left.maxNode && root->val < right.minNode)
        {
            int currSum = root->val + left.sum +right.sum;
            ans = max(ans, currSum);
            return {currSum, true, min(root->val, left.minNode),max(root->val, right.maxNode)};
        }

        return{0,false, INT_MAX,INT_MIN};

    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};