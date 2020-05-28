#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    int val;
    node *left = nullptr;
    node *right = nullptr;

    node()
    {
       }
};

node *create( vector<int> &arr, int si, int ei)
{
    if (ei<si)
        return nullptr;

    int mid = (si + ei) / 2;

    node *nd = new node();

    nd->val = arr[mid];
    create( arr, si, mid - 1);
    create( arr, mid + 1, ei);

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


int main()
{
    vector<int> bst = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130};

    node * root=new node();
    root=create(bst,0,bst.size()-1);
    display(root);
    return 0;
}