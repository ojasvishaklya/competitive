// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i : nums)
            sum+=i;
        
        if(sum%2!=0)
            return false;
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return dfs(nums,sum/2,0,dp);
    }
    
    bool dfs(vector<int> &weight, int target, int idx, vector<vector<int>> &dp)
{

    if (idx == weight.size() || target == 0){
        if(target==0){
            dp[idx][target]= 1;
            return true; 
        }
        dp[idx][target]= 0;
        return false;
    }

    if (dp[idx][target]!=-1)  
        return dp[idx][target]==1 ? true : false;
    

    bool res = false;

    if (target - weight[idx] >= 0)
        res = res || dfs(weight, target - weight[idx], idx + 1, dp);
        
        res = res || dfs(weight, target , idx + 1, dp);


    
    dp[idx][target] = res==true ? 1 : 0;
    return res;
}
};