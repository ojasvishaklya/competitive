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
    vector<TreeNode *> path;
    vector<int> ans;
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {

        path_(root, target->val);
        TreeNode *block = nullptr;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i]->val;
            if (k - i >= 0)
            {
                helper(path[i], k - i, block);

                block = path[i];
            }
            else
                break;
        }
        return ans;
    }

    bool path_(TreeNode *root, int data)
    {
        if (root == nullptr)
            return false;
        if (root->val == data)
        {
            path.push_back(root);
            return true;
        }
        bool res = path_(root->left, data) || path_(root->right, data);
        if (res)
            path.push_back(root);
        return res;
    }

    void helper(TreeNode *root, int level, TreeNode *block)
    {
        if (!root || root == block)
            return;
        //cout<<root->val<<"at"<<level<<" ";
        if (level == 0)
        {
            ans.push_back(root->val);
            return;
        }

        helper(root->left, level - 1, block);
        helper(root->right, level - 1, block);
    }
};