#include <iostream>
#include <vector>
using namespace std;
int row;
int col;
int diag;
int anti_diag;

int queen(vector<vector<bool>> arr, int idx, int qpsf, int tnq, string ans)
{
    if (tnq == qpsf || idx == arr.size() * arr[0].size())
    {
        if (tnq == qpsf)
        {
            cout << ans << endl
                 << "--------------------" << endl;
            for (int p = 0; p < arr.size(); p++)
            {
                for (int j = 0; j < arr.size(); j++)
                    cout << arr[p][j] << " ";
                cout << endl;
            }
            cout << "--------------------" << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    int x = idx / arr[0].size();
    int y = idx % arr[0].size();
    if (!((row) & (1 << y)) && !((col) & (1 << x)) && !((diag) & (1 << x - y + arr.size() - 1)) && !((anti_diag) & (1 << x + y)))
    {
        row ^= (1 << y);
        col ^= (1 << x);
        diag ^= (1 << x - y + arr.size() - 1);
        anti_diag ^= (1 << x + y);
        arr[x][y]=1;

        count += queen(arr, idx + 1, qpsf + 1, tnq, ans + "(" + to_string(x) + "," + to_string(y) + ") ");

        row ^= (1 << y);
        col ^= (1 << x);
        diag ^= (1 << x - y + arr.size() - 1);
        anti_diag ^= (1 << x + y);
        arr[x][y]=0;

    }
    count += queen(arr, idx + 1, qpsf, tnq, ans);

    return count;
}

int main()
{

    vector<vector<bool>> arr(4, vector<bool>(4, 0));
    int tq = 4;
    cout << queen(arr, 0, 0, tq, "");

    return 0;
}