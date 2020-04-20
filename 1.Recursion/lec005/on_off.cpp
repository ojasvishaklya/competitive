#include <vector>
#include <iostream>

using namespace std;





void on_off()
{
       int n=6,k=2;
    int z=1;
    z=z<<k;
    int a=n&z;
    cout<<a;
    ~z;
    int b=(n&z);
    cout<<" "<<b;
    cout<<" "<<z;
}


int count_set_bit(unsigned int n)
{int count=0;
    while(n!=0)
    {
        if((n&1)==1)
        count++;
        n=n>>1;
    }
    return count;
}

int main()
{   unsigned int n=8;
    cout<<count_set_bit(n);
    return 0;
}