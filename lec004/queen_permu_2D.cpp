#include <iostream>
#include <vector>

using namespace std;

int queen(vector<vector<bool>> &boxes, int idx, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < boxes.size() * boxes[0].size(); i++)

    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        if (!boxes[x][y])
        {
            boxes[x][y] = true;
            count += queen(boxes, 0, qpsf + 1, tnq, ans + "Q" + to_string(qpsf) + "B" + to_string(x) + to_string(y) + " ");
            boxes[x][y] = false;
        }
    }
    return count;
}
int main()
{
    vector<vector<bool>> boxes(5, vector<bool>(5, false));

    int q = 3;

    cout << endl
         //   << combinationQueen2D(boxes, 0, q, 0, "") << endl;
         << queen(boxes, 0, 0, q, "") << endl;
    return 0;
}