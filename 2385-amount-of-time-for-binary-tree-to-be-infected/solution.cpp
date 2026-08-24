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

 // using dfs
class Solution {
public:
    int result = INT_MAX;

    int solve(TreeNode* root, int start)
    {
        if( root == NULL) return 0;
        int lr = solve(root->left, start);
        int rr = solve(root->right, start);

        // calculate hight
        if(root ->val == start)
        {
            result = max(lr, rr);
            return -1;
        }
        else if( lr>=0 && rr>=0)
        {
            return max(lr, rr)+1;
        }
        else
        {
            int d = abs(lr) + abs(rr);
            result = max(result , d);
            return min(lr, rr)-1;
        }

    
    }
    
    int amountOfTime(TreeNode* root, int start) {

        solve( root, start);
        return result;
        
    }
};