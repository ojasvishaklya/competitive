#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    string word;
    bool wordEnd;
    vector<node *> child;

    node()
    {
        this->child.assign(26, nullptr);
        this->word = "";
        this->wordEnd = false;
    }
};

void insert(string &word)
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
    cur->word = word;
    cur->wordEnd = true;
}
int n, m;
node *root = nullptr;
vector<int> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
vector<string> ans;
void dfs(int i, int j, node *cur, vector<vector<char>> &board)
{
    if (cur->wordEnd)
    {
        cur->wordEnd = false;
        ans.push_back(cur->word);
    }

    char c = board[i][j];
    board[i][j] = '#';

    for (int d = 0; d < dir.size(); d++)
    {

        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if (x >= 0 && y >= 0 && x < n && y < m && board[x][y] != '#' && cur->child[board[x][y] - 'a'] != nullptr)
        {
            dfs(x, y, cur->child[board[x][y] - 'a'], board);
        }
    }
    board[i][j] = c;
    return;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    n = board.size();
    m = board[0].size();
    if (n == 0 || m == 0)
        return {};
    root = new node();
    for (int i = 0; i < words.size(); i++)
    {
        insert(words[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (root->child[board[i][j] - 'a'] != nullptr)
            {
                dfs(i, j, root->child[board[i][j] - 'a'], board);
            }
        }
    return ans;
}