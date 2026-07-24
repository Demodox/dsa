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
    void solve(TreeNode* root, int k, set<int>& st, bool& ans )
    {
        if(root == NULL) return;
        if(k- root->val == 0)
        {
            ans =true;
            return;
        }

        if(st.find(k- root->val) != st.end())
        {
            ans = true;
            return;
        }
        solve(root->left, k, st,ans);
        st.insert(root->val);

        solve(root->right, k, st,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>st;
        bool ans = false;
        solve( root, k, st,ans);
        return ans;

    }
};