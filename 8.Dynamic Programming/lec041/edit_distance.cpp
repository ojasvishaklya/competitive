class Solution {
public:

    int n;
    int m;
    int minDistance(string word1, string word2) {
      
         n=word1.size();
         m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
                    
        return dfs(word1,word2,0,0,dp);
    }
    
    int dfs(string &a,string&b,int i,int j,vector<vector<int>>&dp){
       
      
        if(i==n && j==m)
            return 0;
        if(i==n || j==m)
        {
         return dp[i][j] =max(n-i,m-j);   
        }
     
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        if(a[i]==b[j])
            return dp[i][j]=dfs(a,b,i+1,j+1,dp);
        
       int x=dfs(a,b,i+1,j+1,dp); //replace
       int y=dfs(a,b,i,j+1,dp); //insert
       int z=dfs(a,b,i+1,j,dp); //delete
        
        return dp[i][j]=min(min(x,y),z)+1;
    }
   
};