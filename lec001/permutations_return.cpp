#include <iostream>
#include <vector>
using namespace std ;

vector<string> permutations (string input)
{if(input.length()==0)
{
    vector<string> base;
    base.push_back("");
    return base;
}

char ch=input[0];
vector<string>small=permutations(input.substr(1));

vector<string>myans;
for(string s:small)
for(int i=0;i<=s.size();i++)
{
    myans.push_back(s.substr(0,i)+ch+s.substr(i));

}
return myans;
}

int main()
{

   vector<string> ans= permutations("abc");
   for(string s: ans)
   cout<<s<<endl;
    return 0;
}