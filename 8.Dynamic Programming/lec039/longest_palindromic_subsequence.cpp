https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
    
    int n = s.size();
        
    vector<vector<int>> dp(n,vector<int>(n,-1));    
    return dfs(0,n-1,s,dp);   
    }
    
    int dfs(int si,int ei, string &s,vector<vector<int>> & dp)
    {
        if(si>ei)
            return 0;
        if(si == ei)
            return dp[si][ei] = 1;
        
        if(dp[si][ei]!=-1)
            return dp[si][ei];
        
        int len=0;
        if(s[si] == s[ei])
        {
            len =dfs(si+1,ei-1,s,dp)+2;
        }
        else{
            len=max(dfs(si+1,ei,s,dp),dfs(si,ei-1,s,dp));
        }
        
        
        return dp[si][ei]= len;
            
    }
};