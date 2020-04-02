#include <iostream>
#include <vector>
using namespace std ;

int substring (string input,string ans)
{
    if(input.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count =0;
    char ch=input[0];
     
     count+=substring(input.substr(1),ans);
     count+=substring(input.substr(1),ans+ch);
     
    return count;
}

int main()
{

   
   cout<<substring("abc","");
   cout<<endl<<endl<<"HRM Assignment:"<<endl<<endl;
   for (int i = 0; i < 250; i++)
   {cout<<"yes ";
       /* code */
   }
   
    return 0;
}