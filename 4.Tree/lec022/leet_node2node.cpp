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
class Solution
{
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode *root)
    {

        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int lt = dfs(root->left);
        int rt = dfs(root->right);

        int mx = max(lt, rt) + root->val;

        ans = max(max(max(mx, lt + rt + root->val), root->val), ans);

        return max(mx, root->val);
    }
};