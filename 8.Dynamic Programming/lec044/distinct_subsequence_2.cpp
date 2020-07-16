// https://leetcode.com/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string s) {
        
        int mod=1e9+7;
       
        vector<long> dp(s.size()+1,0);
        vector<int>arr(26,-1);
        
        dp[0]=1;
        
        for(int i=0 ;i<s.size();i++)
        {
            char c=s[i];
            
            dp[i+1]= 2*dp[i]%mod;
            
            if(arr[c-'a'] != -1)
            {
                dp[i+1]=(dp[i+1]%mod -dp[arr[c-'a']]%mod + mod)%mod ;
            }
            
            arr[c-'a']=i;
        }

        return dp[s.size()]%mod - 1 ;
    }
    
    
  
};