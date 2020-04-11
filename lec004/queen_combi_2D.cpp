#include <iostream>
#include <vector>

using namespace std;

int queen(vector<vector<bool>> &boxes, int idx, int qpsf, int tnq, string ans)
{ //qpsf : queen place so far, tnq: total no of queen
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)

    {
        int x = i / boxes[0].size();

        int y = i % boxes[0].size();

        count += queen(boxes, i + 1, qpsf + 1, tnq, ans + "Q" + to_string(qpsf) + "B" + to_string(x) + to_string(y) + " ");
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