#include <iostream>
#include <vector>

using namespace std;

vector<int> row(9, 0);
vector<int> col(9, 0);
vector<vector<int>> mat(3, vector<int>(3, 0));

int sudoku(vector<vector<char>> board, int idx)
{
    if (idx == 81)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
                cout << board[row][col] << " ";
            cout << endl;
        }
        return 1;
    }
    int count = 0;
    int r = idx / 9;
    int c = idx % 9;
    if (board[r][c] == '.')
    {
        for (int num = 1; num <= 9; num++)
        {
            int mask = 1 << num;
            if ((row[r] & mask) == 0 && (col[c] & mask) == 0 && (mat[r / 3][c / 3] & mask) == 0)
            {
                board[r][c] = char(num + '0');
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;

                count += sudoku(board, idx + 1);
                if (count != 0)
                    return 1;
                board[r][c] = '.';
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
            }
        }
    }
    else
        count += sudoku(board, idx + 1);
    return count;
}

int main()
{
    vector<vector<char>> board = {{'3', '.', '6', '5', '.', '8', '4', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '3', '1'},
                                  {'.', '.', '3', '.', '1', '.', '.', '8', '.'},
                                  {'.', '.', '.', '8', '6', '3', '.', '.', '.'},
                                  {'.', '.', '.', '.', '9', '.', '6', '.', '.'},
                                  {'1', '3', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '7', '4'},
                                  {'.', '.', '5', '2', '.', '6', '3', '.', '.'}};

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != '.')
            {
                int mask = 1 << (board[i][j] - '0');
                row[i] ^= mask;
                col[j] ^= mask;
                mat[i / 3][j / 3] ^= mask;
            }
        }

    cout << sudoku(board, 0);

    return 0;
}