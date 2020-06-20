#include <iostream>
#include <vector>

using namespace std;

class Node
{
    int val = 0;
    Node *next = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};

Node *head = nullptr;
Node *tail = nullptr;
int size = 0;

int Size()
{
    return size;
}

int main()
{
    return 0;
}