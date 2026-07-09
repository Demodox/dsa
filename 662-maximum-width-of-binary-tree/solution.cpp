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

 // Hint : index of left child of a node = 2*idx+1  &  index of right child = 2*udx+2
class Solution {
public:
    typedef long long ll;
    int widthOfBinaryTree(TreeNode* root){

        queue<pair<TreeNode* , ll>>q;
        int ans =0;

        q.push({root,0});
        while(!q.empty())
        {
            int n= q.size();
            ll s = q.front().second;
            ll e = q.back().second;
            ans = max(ans , int(e-s+1));

            while(n--)
            {
                TreeNode* node= q.front().first;
                ll idx = q.front().second;
                q.pop();

                if(node->left)
                {
                    q.push({node->left, 2*idx+1});
                }
                if(node->right)
                {
                    q.push({node->right, 2*idx+2});
                }
                    
            }


        }

        return ans;
        
        
    }
};