#include <iostream>
#include <vector>

using namespace std;
bool isSafe(int x, int y, vector<vector<bool>> &boxes)
{
    // vector<vector<int>> dir = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
    vector<vector<int>> dir = {{-1, 0}, {-1, -1}, {0, -1}, {-1, 1}};

    for (int d = 0; d < dir.size(); d++)
        for (int mag = 1; mag < boxes.size(); mag++)
        {
            int r = x + mag * dir[d][0];
            int c = y + mag * dir[d][1];

            if (r >= 0 && c >= 0 && r < boxes.size() && r < boxes.size())
            {
                if (boxes[r][c] == true)
                {
                    return false;
                }
            }
            break;
        }
    return true;
}
vector<int> rowA(4, false);
vector<int> colA(4, false);
vector<int> diag(7, false);
vector<int> Adiag(7, false);

int queen(vector<vector<bool>> &boxes, int idx, int qpsf, int tnq, string ans)
{
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
        // if (!rowA[y] && !colA[x] && !diag[x - y + boxes.size() - 1] && !Adiag[x + y])
        if (isSafe(x, y, boxes) && boxes[x][y] == false)
        {
            // rowA[y] = true;
            //colA[x] = true;
            // diag[x - y + boxes.size() - 1] = true;
            // Adiag[x + y] = true;
            boxes[x][y] = true;
            count += queen(boxes, i + 1, qpsf + 1, tnq, ans + "Q" + to_string(qpsf) + "B" + to_string(x) + to_string(y) + " ");
            boxes[x][y] = false;

            // rowA[y] = false;
            //colA[x] = false;
            //diag[x - y + boxes.size() - 1] = false;
            //Adiag[x + y] = false;
        }
    }
    return count;
}
int main()
{
    vector<vector<bool>> boxes(4, vector<bool>(4, false));

    int q = 4;

    cout << endl
         //   << combinationQueen2D(boxes, 0, q, 0, "") << endl;
         << queen(boxes, 0, 0, q, "") << endl;
    return 0;
}