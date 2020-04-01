#include <iostream>
#include <vector>
using namespace std ;

int substring (string input,string ans)
{
    if(input.length()==0)
    {
        ans.push_back("");
        return 1;
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

   
   substring("abc","");

    return 0;
}