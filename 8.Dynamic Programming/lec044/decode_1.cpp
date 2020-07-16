// https://leetcode.com/problems/decode-ways/

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        
            vector<int>dp(s.size()+1,-1);
            return dfs(s,0,dp);
     
    }

    int dfs(string& s,int i,vector<int>&dp)
    {

        if (s.size() == i)
            return dp[i]=1;

        if(dp[i]!=-1)
            return dp[i];
        
       int count = 0;
       if(s[i]-'0'!=0)
        count += dfs(s,i+1,dp);
        
        if(i<s.size()-1)
        {
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            
            if((a*10 +b)>=10 && (a*10 +b)<=26)
                count += dfs(s,i+2,dp);
               
        }

        return dp[i]=count;
    }
};