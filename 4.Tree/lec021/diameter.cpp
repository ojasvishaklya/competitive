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
int ans = 0;

int dfs(node *root)
{
    if (!root)
        return 0;

    int l = dfs(root->left);
    int r = dfs(root->right);

    ans = max(ans, l + r);

    return max(l, r) + 1;
}

int main()
{

    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node *root = nullptr;
    root = construct(arr);

    display(root);

    return 0;
}
