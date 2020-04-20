#include <iostream>
#include <vector>
using namespace std ;

vector<string> substring (string input)
{
    if(input.length()==0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    char ch=input[0];
    vector<string> smallans=substring(input.substr(1));
    vector<string> myans;
    for(string s :smallans)
  
    {
        myans.push_back(s);
        myans.push_back(s+ch);
    }
    return myans;
}

int main()
{

   vector<string> ans= substring("abc");
   for(string s: ans)
   cout<<s<<endl;
    return 0;
}