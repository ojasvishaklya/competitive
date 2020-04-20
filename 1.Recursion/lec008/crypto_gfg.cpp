#include <iostream>
#include <vector>

using namespace std;
string str1 = "send";
string str2 = "more";
string str3 = "money";
vector<int> mapping(26, 0);
int numused = 0;

int stringToNumber(string &str)
{
    int res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int idx = str[i] - 'a';
        res = res * 10 + mapping[idx];
    }
    return res;
}

int crypto_(string str, int idx)
{
    if (idx == str.length())
    {
        int a = stringToNumber(str1);
        int b = stringToNumber(str2);
        int c = stringToNumber(str3);

        if ((a + b == c) && mapping[str1[0] - 'a'] != 0 && mapping[str2[0] - 'a'] != 0 && mapping[str3[0] - 'a'] != 0)
        {
            cout << a << endl
                 << "+" << b << endl
                 << "------" << endl
                 << c << endl
                 << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    for (int num = 0; num <= 9; num++)
    {
        int mask = (1 << num);
        if ((numused & mask) == 0)
        {
            numused ^= mask;
            mapping[str[idx] - 'a'] = num;
            count += crypto_(str, idx + 1);
            numused ^= mask;
            mapping[str[idx] - 'a'] = 0;
        }
    }
    return count;
}
int main()
{

    string str = str1 + str2 + str3;
    int freq = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int idx = 1 << (str[i] - 'a');
        freq |= idx;
    }

    str = "";
    for (int i = 0; i < 26; i++)
    {
        int mask = (1 << i);
        if ((freq & mask) != 0)
        {
            str += (char)(i + 'a');
        }
    }

    if (str.length() > 10)
        return 0;

    // cout << str<< endl;
    cout << crypto_(str, 0) << endl;
    return 0;
}