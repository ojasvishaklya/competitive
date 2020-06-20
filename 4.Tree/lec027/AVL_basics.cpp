#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    int height;
    int balance;

    Node(int val)

    {
        this->val = val;
        this->height = 0;
        this->balance = 0;
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
        s += to_string(node->left->val) + "[" + to_string(node->left->balance) + "," + to_string(node->left->height) + "]";
    }
    s += " <- " + to_string(node->val) + "[" + to_string(node->balance) + "," + to_string(node->height) + "]" + " -> ";
    if (node->right != nullptr)
    {
        s += to_string(node->right->val) + "[" + to_string(node->right->balance) + "," + to_string(node->right->height) + "]";
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

void update_balance_height(Node *root)
{
    int lh = -1;
    int rh = -1;

    if (root->left)
        lh = root->left->height;
    if (root->right)
        lh = root->right->height;

    root->height = max(lh, rh) + 1;
    root->balance = lh - rh;
}

Node *rotateLL(Node *A)
{
    Node *B = A->left;
    Node *BR = B->right;

    B->right = A;
    A->left = BR;

    update_balance_height(A);
    update_balance_height(B);

    return B;
}
Node *rotateRR(Node *A)
{
    Node *B = A->right;
    Node *BL = B->left;

    B->left = A;
    A->right = BL;

    update_balance_height(A);
    update_balance_height(B);

    return B;
}

Node *decide_rotation(Node *root)
{
    update_balance_height(root);
    if (root->balance == 2)
    {
        if (root->left->balance == 1)
            return rotateLL(root);

        else if (root->left->balance == -1)
        {
            root->left = rotateRR(root->left);
            return rotateLL(root);
        }
    }

    else if (root->balance == -2)
    {
        if (root->right->balance == 1)
        {
            root->right = rotateLL(root->right);
            return rotateRR(root);
        }
        else if (root->right->balance == -1)
            return rotateRR(root);
    }
    return root;
}
Node *addNode(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->val)
        root->left = addNode(root->left, val);
    if (val > root->val)
        root->right = addNode(root->right, val);

    
    return decide_rotation(root);
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130};

    Node *root = create(arr, 0, arr.size() - 1);
    display(root);

    addNode(root, 65);
    addNode(root, 66);
    addNode(root, 67);
    addNode(root, 68);

    display(root);
    return 0;
}