#include <iostream>

using namespace std;

void lexi(int st, int end)
{
    if (st > end)
        return;
    cout << st << endl;
    for (int i = 0; i <= 9; i++)
    {
        if (st * 10 + i < end)
            lexi(st * 10 + i, end);
        else
            break;
    }

    if (st < 9)
        lexi(st + 1, end);
}

int main()
{
    int end = 20;
    lexi(1, end);
    return 0;
}