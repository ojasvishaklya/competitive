#include <iostream>
#include <vector>

using namespace std;
vector<string> words = {
    "0", //0
    "a", //1
    "b", //2
    "c", //3
    "d", //4
    "e", //5
    "f", //6
    "g", //7
    "h", //8
    "i", //9
    "j", //10
    "k", //11
    "l", //12
    "m", //13
    "n", //14
    "o", //15
    "p", //16
    "q", //17
    "r", //18
    "s", //19
    "t", //20
    "u", //21
    "v", //22
    "w", //23
    "x", //24
    "y", //25
    "z", //26
};

int keypad(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int idx = str[0] - '0';
    string word = words[idx];
    int count = 0;

    for (int i = 0; i < word.length(); i++)
    {
        count += keypad(str.substr(1), ans + word[i]);
    }

    if (str.length() > 1)
    {
        int idx1 = str[1] - '0';
        int num = idx * 10 + idx1;
        if (num >= 10 && num <= 26)
        {
            word = words[num];
            for (int i = 0; i < word.length(); i++)
            {
                count += keypad(str.substr(2), ans + word[i]);
            }
        }
    }
    return count;
}

int main()
{
    cout << endl
         << keypad("1510", "");
    return 0;
}

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> freq(69, {0, 0});
        for (char c : s)
        {
            if (c == " ")
            {
                freq[68].first++;
                freq[68].second = (char)c;
            }
            else if (c - '0' >= 0 && c - '0' <= 9)
            {

                freq[c - '0' + 58].first++;
                freq[c - '0' + 58].second = (char)c;
            }
            else
            {
                freq[c - 'A'].first++;
                freq[c - 'A'].second = (char)c;
            }
        }

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        s = "";
        for (int i = 0; i < 68; i++)
            for (int j = 0; j < freq[i].first; j++)
            {
                if (i == 68)
                    s += " ";
                else
                    s += freq[i].second;
            }
        return s;
    }
};
