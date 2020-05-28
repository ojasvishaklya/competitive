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
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
       vector<int>ans;
        
        queue<TreeNode * >q;
        
        q.push(root);
        
        while(q.size())
        {
            int size=q.size();
            int a;
            
            while(size-->0)
            {
             TreeNode* vtx=q.front();q.pop();
                a = vtx->val;
                
                if(vtx->left)
                    q.push(vtx->left);
                if(vtx->right)
                    q.push(vtx->right);

            }
            
            ans.push_back(a);
        }
        
        return ans;
    }
};