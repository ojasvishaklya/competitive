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

int size(node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return size(root->left) + size(root->right) + 1;
}

int depth(node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 0; //return -1 if height in terms of edges return 0 when height in terms of node
    if (root->left == nullptr || root->right == nullptr)
        return 1;
    return max(depth(root->left), depth(root->right)) + 1;
}
int maxElement(node *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return INT_MIN;

    return max(max(maxElement(root->left), maxElement(root->right)), root->val);
}

int minElement(node *root)
{
    if (!root)
        return INT_MAX;
    if (!root->left && !root->right)
        return root->val;

    return min(min(minElement(root->left), minElement(root->right)), root->val);
}

bool find(node *root, int ele)
{
    if (!root)
        return false;
    if (root->val == ele)
        return true;
    bool res = find(root->left, ele) || find(root->right, ele);

    return res;
}

bool path(node *root, vector<int> &ans, int ele)
{
    if (!root)
        return false;

    ans.push_back(root->val);
    if (root->val == ele)
        return true;

    bool res = path(root->left, ans, ele) || path(root->right, ans, ele);
    if (!res)
        ans.pop_back();
    return res;
}

int main()
{

    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node *root = nullptr;
    root = construct(arr);

    display(root);

    cout << "Number of nodes in the tree: " << size(root) << endl;
    cout << "Max depth of the tree: " << depth(root) << endl;
    cout << "Max element of the tree: " << maxElement(root) << endl;
    cout << "Min element of the tree: " << minElement(root) << endl;
    cout << "Find element 5 in the tree " << find(root, 5) << endl;
    vector<int> ans;
    bool found = path(root, ans, 5);
    if (found)
    {
        for (auto i : ans)
            cout << i << "->";
    }
    else cout<<"not-found";
    return 0;
}