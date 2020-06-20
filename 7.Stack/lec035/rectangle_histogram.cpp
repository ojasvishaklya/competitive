class Solution
{
public:
    int largestRectangleArea(vector<int> &arr)
    {

        stack<int> st;
        st.push(-1);
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && arr[i] <= arr[st.top()])
            {
                int popped = st.top();
                st.pop();
                ans = max(ans, arr[popped] * (i - st.top() - 1));
            }
            st.push(i);
        }

        while (st.top() != -1)
        {
            int popped = st.top();
            st.pop();
            ans = max(ans, arr[popped] * (n - st.top() - 1));
        }
        return ans;
    }
};