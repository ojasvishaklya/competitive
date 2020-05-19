#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<string> result;
    vector<string> removeInvalidParentheses(string s)
    {
        int leftExtra = 0; //  ( -> left

        int rightExtra = 0; // ) ->right
        int balance = 0;    //balance goes +1 for right and -1 for left

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                leftExtra++;
            }

            if (s[i] == ')')
            {
                if (leftExtra > 0)
                    leftExtra--;
                else
                    rightExtra++;
            }
        }
        unordered_set<string> set;
        dfs(s, "", 0, leftExtra, rightExtra, balance, set);
        return vector<string>(set.begin(), set.end());
    }

    void dfs(string s, string ans, int idx, int leftExtra, int rightExtra, int balance, unordered_ser<string> &set)
    {

        if (idx == s.size())
        {
            if (balance == 0)
            {
                set.insert(ans);
                return;
            }
            return;
        }
        if (s[idx] == '(')
        {
            if (leftExtra)
                dfs(s, ans, idx + 1, leftExtra - 1, rightExtra, balance, set);

            dfs(s, ans + s[idx], idx + 1, leftExtra, rightExtra, balance + 1, set);
        }
        else if (s[idx] == ')')
        {
            if (rightExtra)
                dfs(s, ans, idx + 1, leftExtra, rightExtra - 1, balance, set);
            if (balance)
                dfs(s, ans + s[idx], idx + 1, leftExtra, rightExtra, balance - 1, set);
        }

        else
        {
            dfs(s, ans + s[idx], idx + 1, leftExtra, rightExtra, balance, set);
        }

        return;
    }
};