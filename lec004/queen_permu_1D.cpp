#include <iostream>
#include <vector>

using namespace std;

int queen(vector<bool> boxes, int tq, int pq, string ans)
{
    if (pq == tq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;

    for (int i = 0; i < boxes.size(); i++)
    {
        if (!boxes[i])
        {
            boxes[i] = true;
            count += queen(boxes, tq, pq + 1, ans + "Q" + to_string(pq) + "B" + to_string(i) + " ");
            boxes[i] = false;
        }
    }

    return count;
}

int main()
{
    vector<bool> boxes(5, false);

    int queens = 3;

    cout << queen(boxes, queens, 0, "");
    return 0;
}