#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int arr[4] = {11, 13, 21, 3};
    int ans[4];
    stack<int> st;

    for (int i = 0; i < 4; i++)
    {
        while (st.size() && arr[st.top()] < arr[i])
        {
            ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }

    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<"->"<<ans[i]<<endl;
    }

    return 0;
}