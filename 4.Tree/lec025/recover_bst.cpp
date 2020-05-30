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
        if (a != nullptr)
        {
            int temp = a->val;
            a->val = b->val;
            b->val = temp;
        }
        return;
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);

        if(prev && prev->val > root->val)
        {
            if(a==nullptr)
            {
                a=prev;
                b=root;
            }
            else
            {
                b=root;
            }
        }
        prev=root;
        inorder(root->right);
        return;
    }
};