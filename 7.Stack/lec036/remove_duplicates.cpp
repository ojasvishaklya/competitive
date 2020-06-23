// https://leetcode.com/problems/remove-duplicate-letters/

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<bool> vis(26, false);
        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++;
        }
        string ans;

        for (char c : s)
        {
            freq[c - 'a']--;
            if (!vis[c - 'a'])
            {

                while (ans.size() && ans.back() > c && freq[ans.back() - 'a'] > 0)
                {
                    vis[ans.back() - 'a'] = false;
                    ans.pop_back();
                }

                ans += c;
                vis[c - 'a'] = true;
            }
        }

        return ans;
    }
};