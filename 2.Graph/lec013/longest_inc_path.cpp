
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> indegree(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n && matrix[i + 1][j] > matrix[i][j])
                indegree[i + 1][j]++;
            if (j + 1 < m && matrix[i][j + 1] > matrix[i][j])
                indegree[i][j + 1]++;
            if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
                indegree[i - 1][j]++;
            if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
                indegree[i][j - 1]++;
        }
    queue<int> que;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (indegree[i][j] == 0)
                que.push(i * m + j);
        }
    }
    int len = 0;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();
            int i = rvtx / m;
            int j = rvtx % m;

            {
                if (i + 1 < n && matrix[i + 1][j] > matrix[i][j] && --indegree[i + 1][j] == 0)
                    que.push((i + 1) * m + (j));
                if (j + 1 < m && matrix[i][j + 1] > matrix[i][j] && --indegree[i][j + 1] == 0)
                    que.push((i)*m + (j + 1));
                if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j] && --indegree[i - 1][j] == 0)
                    que.push((i - 1) * m + (j));
                if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j] && --indegree[i][j - 1] == 0)
                    que.push((i)*m + (j - 1));
            }
        }
        len++;
    }
    return len;
}