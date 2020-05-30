#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;

    Node()
    {
    }
};

Node *create(vector<int> &arr, int si, int ei)
{
    if (ei < si)
        return nullptr;

    int mid = (si + ei) / 2;

    Node *node = new Node();

    node->val = arr[mid];
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

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130};

    Node *root = create(arr, 0, arr.size() - 1);
    display(root);

    int data = 50;
    Node *pred = nullptr;
    Node *succ = nullptr;

    while (root != nullptr)
    {
       
        if (root->val == data)
        {

            if (root->left)
            {
                pred = root->left;

                while (pred->right != nullptr)
                {
                    pred = pred->right;
                }
            }
            if (root->right)
            {
                succ = root->right;

                while (succ->left != nullptr)
                {
                    succ = succ->left;
                }
            }
            break;
        }

        else if (root->val > data)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            pred = root;
            root = root->right;
        }
    }
    cout << "Predecessor : " << pred->val << endl;
    cout << "Successor : " << succ->val << endl;
    return 0;
}