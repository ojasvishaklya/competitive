#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    queue<int> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 1)
                q.push(i * m + j);
}