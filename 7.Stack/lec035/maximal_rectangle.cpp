class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
     
        if(!matrix.size())return 0;
        int ans=0;
        vector<int>arr(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
               { if(matrix[i][j]=='1')
                    arr[j]++;
                 else arr[j]=0;
                }
            ans=max(ans,histogram(arr));
        }
    
    return ans;
    }
    
    int histogram(vector<int>&arr)
    {
            int ans=0;
        stack<int>st;
        st.push(-1);
        
        for(int i=0;i<arr.size();i++)
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
                int area=arr[popped] * (arr.size() - st.top() - 1);
                ans = max(ans,area);
            }
        return ans;
    }
        
};