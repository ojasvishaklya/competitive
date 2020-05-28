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
    TreeNode *a = nullptr;
    TreeNode *b = nullptr;
    TreeNode *prev = nullptr;
    void recoverTree(TreeNode *root)
    {

        inorder(root);

        return;
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
        return;
    }
};