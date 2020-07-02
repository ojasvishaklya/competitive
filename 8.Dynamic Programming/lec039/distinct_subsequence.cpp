// https://leetcode.com/problems/distinct-subsequences/submissions/

class Solution {
public:
    
    int n;
    int m;
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
      return  dfs(s,t,0,0,dp);
    }
    
    
    int dfs(string &s, string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(n-i < m-j)
            return 0;
        if(i==n || j==m)
            return dp[i][j]=1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int count=0;
        if(s[i]==t[j])
        {
            count=dfs(s,t,i+1,j+1,dp)+dfs(s,t,i+1,j,dp);
        }
        
        else count=dfs(s,t,i+1,j,dp);
        
        return dp[i][j]=count;
    }
};