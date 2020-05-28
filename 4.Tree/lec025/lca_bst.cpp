
// also do validate search tree from leetcode


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans= root;
        
        while(ans!=nullptr){
        
            if(ans->val > p->val && ans->val > q->val)
            ans=ans->left;
            
           else if(ans->val < p->val && ans->val < q->val)
            ans=ans->right;
            
            else return ans;
        }
        
        return nullptr;
    }

};