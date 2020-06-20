
//https://leetcode.com/problems/binary-search-tree-iterator/submissions/


class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        
        pushAllLeftOfRight(root);
    }
    
    void pushAllLeftOfRight(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        return;
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* root=st.top();
        st.pop();
        
        if(root->right);
        pushAllLeftOfRight(root->right);
        
        return root->val;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return st.size()!=0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */