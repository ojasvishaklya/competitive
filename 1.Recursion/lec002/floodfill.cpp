#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> moves = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};

vector<string> dir = {"R", "E", "U", "N", "L", "W", "D", "S"};

int floodFill(int sr, int sc, int er, int ec, vector<vector<int>> &board, int rad, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    board[sr][sc] = 0;

    for (int d = 0; d < moves.size(); d++)
    {
        for (int mag = 1; mag <= rad; mag++)
        {
            int r = sr + mag * dir[d][0];
            int c = sc + mag * dir[d][1];
            if ((r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]==0))
            {
                count += floodFill(r, c, er, ec, board, rad, ans + dir[d] + to_string(mag));
            }
        }
    }

    board[sr][sc] = 1;
    return count;
}

int main()
{

    int sr = 0, sc = 0, er = 3, ec = 3,radius=max(er,ec);
    vector<vector<int>> board(er + 1, vector<int>(ec + 1, 1));
    for (int r = 0; r < board.size(); r++)
    {
        for (int c = 0; c < board[0].size(); c++)
        {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }

  cout<< floodFill(sr, sc, er, ec, board, radius,"");
  
    return 0;
}