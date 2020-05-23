#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class node
{
public:
    int val;
    node *left = nullptr;
    node *right = nullptr;

    node(int val)
    {
        this->val = val;
    }
};

node *ans = nullptr;
int idx = 0;
node *construct(vector<int> &arr)
{
    if (idx >= arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    // cout << idx << " -> " << arr[idx] << " ";
    node *nd = new node(arr[idx++]);

    nd->left = construct(arr);
    nd->right = construct(arr);

    return nd;
}

void display(node *node)
{
    string s = "";
    if (node->left != nullptr)
    {
        s += to_string(node->left->val);
    }
    s += " <- " + to_string(node->val) + " -> ";
    if (node->right != nullptr)
    {
        s += to_string(node->right->val);
    }
    cout << s << endl;
    if (node->left != nullptr)
    {
        display(node->left);
    }
    if (node->right != nullptr)
    {
        display(node->right);
    }

    return;
}

bool lca(node *root, int a, int b)
{
    if (!root)
        return false;

    bool resSelf = false;
    if (root->val == a || root->val == b)
        resSelf = true;
    bool resLeft = lca(root->left, a, b);
    if (ans)
        return true;
    bool resRight = lca(root->right, a, b);
    if (ans)
        return true;

    if ((resSelf && resLeft) || (resSelf && resRight) || (resRight && resLeft))
    {
        ans = root;
        return true;
    }

    return resSelf || resRight || resLeft;
}

int main()
{

    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node *root = nullptr;
    root = construct(arr);

    display(root);
    lca(root, 7, 4);

    if (ans)
        cout << "LCA of 4 ans 5 : " << ans->val;
    else
        cout << "one node invalid";
    return 0;
}
