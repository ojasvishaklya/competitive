class Solution
{
public:
    int memo(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return dp[n] = 1;

        if (dp[n] != 0)
            return dp[n];

        int count = 0;
        for (int i = 1; i <= n; i++)
            count += memo(i - 1, dp) * memo(n - i, dp);

        return dp[n] = count;
    }
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        return memo(n, dp);
    }
};

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
    vector<TreeNode *> generateTrees(int n)
    {

        if (n == 0)
            return {};
        return dfs(1, n);
    }

    vector<TreeNode *> dfs(int si, int ei)
    {
        if (si > ei)
            return {nullptr};

        vector<TreeNode *> ans;

        for (int i = si; i <= ei; i++)
        {
            vector<TreeNode *> left = dfs(si, i - 1);
            vector<TreeNode *> right = dfs(i + 1, ei);

            for (auto l : left)
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;

                    ans.push_back(root);
                }
        }

        return ans;
    }
};