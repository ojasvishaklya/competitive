#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode
{
public:
    int val;
    vector<TreeNode *> child;

    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode *create(vector<int> &preorder)
{
    stack<TreeNode *> st;
    for (int i = 0; i < preorder.size() - 1; i++)
    {
        if (preorder[i] != -1)
        {
            TreeNode *node = new TreeNode(preorder[i]);
            st.push(node);
        }
        else
        {
            TreeNode *node = st.top();
            st.pop();
            st.top()->child.push_back(node);
        }
    }

    return st.top();
}
void display(TreeNode *root)
{

    cout << root->val << " -> ";
    for (TreeNode *ele : root->child)
    {
        cout << " (" << ele->val << ")";
    }
    cout << endl;
    for (TreeNode *ele : root->child)
    {
        display(ele);
    }
}

bool isMirror(TreeNode *root1, TreeNode *root2)
{
    if (root1->child.size() != root2->child.size() || root1->val != root2->val)
    {
        return false;
    }
    bool res = true;

    int i = 0;
    int j = root1->child.size() - 1;
    while (j >= 0 && i < root1->child.size())
    {
        res = res && isMirror(root1->child[i], root2->child[j]);
        i++;
        j--;
    }

    return res;
}
TreeNode *tail(TreeNode *root)
{
    if (root->child.size() == 0)
        return root;
}

int main()
{
    vector<int> preorder = {10, 20, 40, -1, 50, -1, -1, 30, 60, -1, 70, -1, -1, 20, 50, -1, 40, -1, -1, -1};
    TreeNode *root = create(preorder);
    display(root);
    cout << isMirror(root, root);
    return 0;
}
