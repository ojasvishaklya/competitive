
    #include <bits/stdc++.h>

    using namespace std;


    
    int dir[8][2] = {{1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {1, -1}};
    
     void updateBoard(vector<vector<char>> &board, vector<int> &click)
    {

        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return ;
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << "------------------------------------" << endl;
        dfs(board, click[0], click[1]);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                cout << board[i][j] << " ";
            cout << endl;
        }

        return ;
    }

    void dfs(vector<vector<char>> &board, int r, int c)
    {
        int mineCount = 0;
        for (int i = 0; i < 8; i++)
        {
            int x = r + dir[i][0];
            int y = c + dir[i][1];

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == 'M')
                mineCount++;
        }
        if (mineCount != 0)
        {
            board[r][c] = (char)(mineCount + '0');
            return;
        }

        board[r][c] = 'B';
        for (int i = 0; i < 8; i++)
        {
            int x = r + dir[i][0];
            int y = c + dir[i][1];

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == 'E')
                dfs(board, x, y);
        }

        return;
    }

void display(vector<vector<char>>& board)
{
    
}

    int main()
    {



return 0;

    }