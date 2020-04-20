#include <iostream>
#include <vector>

using namespace std;

vector<int> row(9, 0);
vector<int> col(9, 0);
vector<vector<int>> mat(3, vector<int>(3, 0));

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
            int mask = 1 << num;
            if ((row[r] & mask) == 0 && (col[c] & mask) == 0 && (mat[r / 3][c / 3] & mask) == 0 )
            {
                board[r][c] = num;
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;

                res = res || sudoku(board, idx + 1);

                board[r][c] = 0;
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
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

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != 0)
            {
                int mask = 1 << board[i][j];
                row[i] ^= mask;
                col[j] ^= mask;
                mat[i / 3][j / 3] ^= mask;
            }
        }

    cout << sudoku(board, 0);

    return 0;
}