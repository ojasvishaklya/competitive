#include <iostream>
#include <vector>
using namespace std;

vector<string> words = {
    ":;/",   //0
    "abc",   //1
    "def",   //2
    "ghi",   //3
    "jkl",   //4
    "mno",   //5
    "pqrs",  //6
    "tuv",   //7
    "wxyz",  //8
    "&*%",   //9
    "#@$",   //10
};

vector<string> keypad(string input)
{
    if (input.size() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    char ch = input[0];
    int idx=ch-'0';
    vector<string> smallans = keypad(input.substr(1));
    vector<string>  myans;
    for (string s : smallans)
        for (int i = 0; i < words[idx].size(); i++)
        {
            myans.push_back(words[idx][i] + s);
        }
    return myans;
}

int main()
{int i=0;
    vector<string> ans = keypad("102");
    for (string s : ans)
        cout << s <<" : "<<++i<< endl;
    return 0;
}