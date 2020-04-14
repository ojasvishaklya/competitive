#include <iostream>
#include <vector>
using namespace std;

int permutationQueen1D_sub(vector<bool> &boxes, int idx, int qpsf, int tnq, string ans)
{
    if (tnq == qpsf || idx == boxes.size())
    {
        if (tnq == qpsf)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (!boxes[idx])
    {
        boxes[idx] = true;
        count += permutationQueen1D_sub(boxes, idx, qpsf + 1, tnq, ans + "B" + to_string(idx) + "Q" + to_string(qpsf) + " ");
        boxes[idx] = false;
    }
    count += permutationQueen1D_sub(boxes, idx + 1, qpsf, tnq, ans);

    return count;
}

int main()
{

    vector<bool> arr(5, 0);
    int tq = 3;
    cout << permutationQueen1D_sub(arr, 0, 0, tq, "");

    return 0;
}