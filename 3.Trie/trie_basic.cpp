#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    bool wordEnd;
    vector<node *> child;

    node()
    {
        this->child.assign(26, nullptr);
        this->wordEnd = false;
    }
};

node *root = nullptr;
void Trie()
{
    root = new node();
}

void insert(string word)
{
    node *cur = root;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        int idx = word[i] - 'a';
        if (cur->child[idx] == nullptr)
            cur->child[idx] = new node();
        cur = cur->child[idx];
    }
    cur->wordEnd = true;
}

bool search(string word)
{
    node *cur = root;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        int idx = word[i] - 'a';

        if (cur->child[idx] != nullptr)
            cur = cur->child[idx];
        else
            return false;
    }
    if (cur->wordEnd == true)
        return true;
    return false;
}

bool startsWith(string word)
{    node *cur = root;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        int idx = word[i] - 'a';

        if (cur->child[idx] != nullptr)
            cur = cur->child[idx];
        else
            return false;
    }
    return true;
}

vector<int> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int main()
{
    return 0;
}