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
        this->val=val;
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



Node* addData(Node* root,int data)
{
    if(!root)
    return new Node(data);

    if(data > root->val)
    root->left=addData(root->left,data);
    
    if(data < root->val)
    root->right=addData(root->right,data);

return root;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60,66,69, 70, 80, 90, 100, 110, 120, 130};

    Node *root = create(arr, 0, arr.size() - 1);
    display(root);


    addData(65);
    return 0;
}