#include <iostream>
#include <vector>
using namespace std;

vector<string> words = {
    ":;/",  //0
    "abc",  //1
    "def",  //2
    "ghi",  //3
    "jkl",  //4
    "mno",  //5
    "pqrs", //6
    "tuv",  //7
    "wxyz", //8
    "&*%",  //9
    "#@$",  //10
};

vector<string> keypad(string input)
{
    if (input.size() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    char ch1 = input[0];
    char ch2 = input[1];
    int idx1 = ch1 - '0';
    int idx2 = ch2 - '0';
    int num = idx1 * 10 + idx2;
    cout<<num<<endl;
    vector<string> myans;

    if (num == 10 || num == 11)
    {
        vector<string> smallans2 = keypad(input.substr(2));

        for (string s : smallans2)
            for (int i = 0; i < words[idx2].size(); i++)
            {
                myans.push_back(words[idx2][i] + s+"  this");
            }
    }
    vector<string> smallans = keypad(input.substr(1));
    for (string s : smallans)
        for (int i = 0; i < words[idx1].size(); i++)
        {
            myans.push_back(words[idx1][i] + s);
        }

    return myans;
}

int main()
{
    int i = 0;
    vector<string> ans = keypad("1010");
    for (string s : ans)
        cout << s << " : " << ++i << endl;
    return 0;
}