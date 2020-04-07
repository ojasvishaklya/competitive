#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> dir =
    {
        {1, 0},
        {0, 1},
        {1, 1},
};
vector<string> name = {"H", "V", "D"};
bool isValid(int c, int r, int er, int ec)
{
    if (c > ec || r > er)
        return false;
    return true;
}
vector<string> maze(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }

    vector<string> myans;
    for (int i = 0; i < dir.size(); i++)
    {
        for (int mag = 1; mag < 4; mag++)
        {

            int r = sr + mag * dir[i][0];

            int c = sc + mag * dir[i][1];
            if (isValid(c, r, er, ec))
            {
                vector<string> smallans = maze(r, c, er, ec);
                for (string s : smallans)
                    myans.push_back(name[i] + to_string(mag) + s);
            }
        }
    }

    return myans;
}
string maxlength(vector<string> ans)
{string a;
    int max = 0;
    for (string s : ans)
    {
        if (s.size() >= max)
        {
            max = s.size();
            a = s;
        }
    }
    return a;
}
string minlength(vector<string> ans)
{string a;
    int min = 100;
    for (string s : ans)
    {
        if (s.size() <= min)
        {
            min = s.size();
            a = s;
        }
    }
    return a;
}

int main()
{

    int sr = 0, sc = 0, er = 3, ec = 3;
    vector<vector<int>> board(er + 1, vector<int>(ec + 1, 1));

    vector<string> ans = maze(sr, sc, er, ec);
    for (string s : ans)
    {
        cout << s << endl;
    }
   string p= maxlength(ans);
   cout<<"longest path "<<p<<endl<<"height of tree "<<p.size()/2<<endl;
      string q= minlength(ans);
   cout<<"Smallest "<<q;
    return 0;
}