// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        
        int n=arr.size();
        if(!n)return 0;
        
       vector<pair<int,int>>dp(n,pair<int,int>());
       int ans=0;

        
        for(int i=0;i<n;i++)
        { 
           dp[i].first=1;
           dp[i].second=1;
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j])
                {
                    
                  if(dp[i].first==dp[j].first+1)
                  {
                      dp[i].second+=dp[j].second;
                  }
                 else if(dp[i].first < dp[j].first+1){
                     
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;

                 }                   
                }
            }
         ans=max(ans,dp[i].first);
            
        }
        int count=0;
        for(int i=0;i<dp.size();i++)
        {
           if(dp[i].first==ans)
               count+=dp[i].second;
            
          //  cout<<i<<" {"<<dp[i].first<<","<<dp[i].second<<"}"<<endl;
            
        }
   
        
        return count;
    }
};