#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>> &board, int n, int r, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[r][i] == n)
            return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] == n)
            return false;
    }
    int x = (r / 3) * 3;
    int y = (c / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + x][j + y] == n)
                return false;
    return true;
}

bool sudoku(vector<vector<int>> board, int idx)
{
    if (idx == 81)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
                cout << board[row][col] << " ";
            cout << endl;
        }
        return true;
    }
    bool res = false;
    int r = idx / 9;
    int c = idx % 9;
    if (board[r][c] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isValid(board, num, r, c))
            {
                board[r][c] = num;
                res = res || sudoku(board, idx + 1);
                board[r][c] == 0;
            }
        }
    }
    else
        res = res || sudoku(board, idx + 1);
    return res;
}

int main()
{
    vector<vector<int>> board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    cout << sudoku(board, 0);

    return 0;
}