#include <iostream>
#include <vector>
using namespace std;

int permutation(string input, string ans)
{
    if (input.size() == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    bool arr[26]={false};
    for (int i = 0; i < input.size(); i++)
    {char ch = input[i];
        if (!arr[ch-'a'])
        {
            arr[ch-'a'] == true;

            string nstr = input.substr(0, i) + input.substr(i + 1);
            count += permutation(nstr, ans + ch);
        }
    }

    return count;
}

int main()
{
    int ans = permutation("aba", "");

    return 0;
}