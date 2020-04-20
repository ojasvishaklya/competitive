#include <iostream>
#include <vector>

using namespace std;

bool  sum (string s,int t)
{int res;
    for(int i=0;i<s.size();i++)
    {char c=s[i];
    int a='c';
        res=res+a;
    }
    cout<<res<<endl;
    if(res==t)
    return true;
    return false;
}

vector<string> permutation_inf(string arr, int t)

{
    if (arr.size() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    char ch = arr[0];
    vector<string> ans;
    vector<string> smallans = permutation_inf(arr.substr(1), 10);
    for (string s : smallans)
    {
        ans.push_back(s);
        ans.push_back(ch + s);
    }

    return ans;
}

int main()
{
    string arr = {"2357"};
    int t = 10;
    vector<string> ans;
    ans = permutation_inf(arr, t);
    for (string s : ans)
        {cout<<s<<" "<<" ";
            if(sum(s,t))
            cout<<s;
        }
    return 0;
}