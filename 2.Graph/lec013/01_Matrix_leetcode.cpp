
int n, m;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    n = matrix.size();
    m = matrix[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                int res = bfs(matrix, i * m + j);
            }
        }

    return matrix;
}

int bfs(vector<vector<int>> &matrix, int src)
{
    queue<int> q;
    q.push(src);

    int level = 0;
    while (q.size() != 0)
    {
        int size = q.size();
        while (size-- > 0)
        {
            int vtx = q.front();
            q.pop();

            int i = vtx / m;
            int j = vtx % m;

            if (matrix[i][j] == 0)
                return level;

            for (int d = 0; d < 4; d++)
            {
                int x = i + dir[i][0];
                int y = j + dir[i][1];
                if (x >= 0 && y >= 0 && x < n && y < m)
                {
                    q.push(x * m + y);
                }
            }
        }

        level++;
    }
}