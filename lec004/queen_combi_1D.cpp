#include <iostream>
#include <vector>

using namespace std;

int queen(vector<int> blocks, int q, int idx, string ans)
{
    if(q==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

for(int i=idx;i<blocks.size();i++)
{
    count += queen(blocks,q-1,i+1, ans + "Q"+to_string(i)+"B"+to_string(i)+" ");
}

  return count;
}

int main()
{
    vector<int> blocks(5, 0);
    int q = 3;

    cout << endl
         << queen(blocks, q, 0, "");
    return 0;
}