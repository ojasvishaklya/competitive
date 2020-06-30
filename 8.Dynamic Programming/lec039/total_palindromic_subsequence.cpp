https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1


#include <vector>
/*You are required to complete below method */

int dfs(string &str,vector<vector<int>> &dp,int si,int ei)
{
    if(si>ei)
     return 0;
    
    if(si==ei)
    return dp[si][ei] = 1;
    
    if(dp[si][ei]!=-1)
    return dp[si][ei];
    
    int count=0;
    
    if(str[si]==str[ei])
    {
        count=dfs(str,dp,si+1,ei) + dfs(str,dp,si,ei-1) +1; 
    }
    
    else{
        count = dfs(str,dp,si+1,ei) + dfs(str,dp,si,ei-1) - dfs(str,dp,si+1,ei-1); 
    }
    
    
    return dp[si][ei] = count;
}

int countPS(string str)
{
  int n=str.size();
  vector<vector<int>> dp(n,vector<int>(n,-1));
  return dfs(str,dp,0,n-1);  
}
 