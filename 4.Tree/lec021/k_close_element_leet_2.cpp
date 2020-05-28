#include <iostream>
#include <vector>

using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution
{

public:
    vector<int> ans;
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {

        path_(root, target->val, k);
        return ans;
    }

    int path_(TreeNode *root, int data, int k)
    {
        if (root == nullptr)
            return -1;
        if (root->val == data)
        {
            cout << " ( " << root->val << " from path ) ";
            ans.push_back(root->val);
            return 1;
        }

        int leftPath = path_(root->left, data, k);

        if (leftPath != -1)
        {
            if (k - leftPath >= 0)
            {
                helper(root, k - leftPath, root->left);
            }
            return leftPath + 1;
        }
        int rightPath = path_(root->right, data, k);

        if (rightPath != -1)
        {
            if (k - rightPath >= 0)
            {
                helper(root, k - rightPath, root->right);
            }
            return leftPath + 1;
        }

        return -1;
    }

    void helper(TreeNode *root, int level, TreeNode *block)
    {
        if (!root || root == block)
            return;

        if (level == 0)
        {
            cout << " ( " << root->val << " from path ) ";
            ans.push_back(root->val);
            return;
        }

        helper(root->left, level - 1, block);
        helper(root->right, level - 1, block);
    }
};