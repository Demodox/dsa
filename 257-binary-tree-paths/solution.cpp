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
    vector<string>result;
    void solve(TreeNode* root, string st)
    {
        if(root == NULL)
        {
            return;
        }
        st+= to_string(root->val);
        // Leaf node
        if(root->left == NULL && root->right == NULL)
        {
            result.push_back(st);
            return;
        }
        st+="->";
        solve(root->left,st);
        solve(root->right,st);
       
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        solve(root,"");
        return result;
        
    }
};