// https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

#include <iostream>
#include <vector>

using namespace std;

void helper()
{
    string s;
    cin >> s;

    int aCount = 0;
    int bCount = 0;
    int cCount = 0;

    for (char &c : s)
    {
        if (c == 'a')
        {
            aCount = 2 * aCount + 1;
        }

        else if (c == 'b')
        {
            bCount = 2 * bCount + aCount;
        }

        else if (c == 'c')
        {
            cCount = 2 * cCount + bCount;
        }
    }

    cout << cCount << endl;
}

int main()
{

    int t;
    cin >> t;

    while (t-- > 0)
    {
        helper();
    }
    return 0;
}