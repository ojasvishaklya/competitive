#include <iostream>
#include <vector>
using namespace std;

int n;
int m;
int dir[3][2] = {{0, 1}, {1, 0}, {1, 1}};

void display(vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

int mazepath(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int r = 1; r < 3; r++)
        {
            int x = sr + dir[i][0] * r;
            int y = sc + dir[i][1] * r;
            if (x < n && y < m)
                count += mazepath(x, y, er, ec, dp);
        }
    return dp[sr][sc] = count;
}

int mazepath_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (int sr = er; sr >= 0; sr--)
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            for (int i = 0; i < 3; i++)
                for (int r = 1; r < 3; r++)
                {
                    int x = sr + dir[i][0] * r;
                    int y = sc + dir[i][1] * r;
                    if (x < n && y < m)
                        count += dp[x][y];
                }
            dp[sr][sc] = count;
        }
    return dp[0][0];
}

int main()
{
    n = 3;
    m = 3;
    vector<vector<int>> dp(n, vector<int>(m, 0));

    //cout << mazepath(0, 0, n - 1, m - 1, dp);
    cout << endl;
    display(dp);
    cout << mazepath_DP(0, 0, n - 1, m - 1, dp);
    cout << endl;
    display(dp);
    return 0;
}