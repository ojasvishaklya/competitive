#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return -1;
    int dir[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n = grid.size();
    int m = grid[0].size();

    queue<int> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 2)
                q.push(i * m + j);

    int level = 0;
    while (q.size() != 0)
    {
        int size = q.size();
        while (size-- > 0)
        {
            int vtx = q.front();
            q.pop();

            int r = vtx / m;
            int c = vtx % m;

            for (int i = 0; i < 4; i++)
            {
                int x = r + dir[i][0];
                int y = c + dir[i][1];

                if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                {
                    grid[x][y] = 2;
                    q.push(x * m + y);
                }
            }
        }
        level++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                return -1;
    if (n == 1 && m == 1)
        return 0;
    return level - 1;
}