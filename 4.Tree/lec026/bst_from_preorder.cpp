#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};

Node *create(vector<int> &arr, int si, int ei)
{
    if (ei < si)
        return nullptr;

    int mid = (si + ei) / 2;

    Node *node = new Node(arr[mid]);

    node->left = create(arr, si, mid - 1);
    node->right = create(arr, mid + 1, ei);

    return node;
}

void display(Node *node)
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

int idx = 0;

Node *construct_from_pre(vector<int> &preorder, int lb, int rb)
{
    if (idx == preorder.size() || preorder[idx] < lb || preorder[idx] > rb)
        return nullptr;

    Node *root = new Node(preorder[idx]);
    idx++;
    root->left = construct_from_pre(preorder, lb, preorder[idx]);
    root->right = construct_from_pre(preorder, preorder[idx], rb);

    return root;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130};

    Node *root = create(arr, 0, arr.size() - 1);
    display(root);

    vector<int> preorder = {70, 30, 10, 20, 50, 40, 60, 100, 80, 90, 120, 110, 130};
    Node *root2 = construct_from_pre(preorder, INT_MIN, INT_MAX);
    display(root);

    return 0;
}