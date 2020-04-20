#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> set;

int break_(string word, string ans)
{
    if (word.size() == 0)
    {
        cout << ans<<endl;
        return 1;
    }

    int count = 0;

    for (int i = 1; i <=word.size(); i++)
    {
        string s = word.substr(0, i);
        if (set.find(s) != set.end())
        {
            count += break_(word.substr(i), ans + s + " ");
        }
    }

    return count;
}

int main()
{
    vector<string> words{"like", "samsung", "i", "ilike", "sam", "sung", "and", "man", "go", "mango"};
    string word = "ilikesamsungandmango";
    for (auto s : words)
    {
        set.insert(s);
    }

    cout << break_(word, "");

    return 0;
}