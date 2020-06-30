class Solution {
public:
    string longestPalindrome(string s) {
        
     if(s.size()==0)
     {
         return s;
     }
        
     return longest_palindromic_substring(s);
    }
    
    string longest_palindromic_substring(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = 0;
    int a=0;
    int b=0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
           
            if (gap == 0)
                dp[i][j] = 0;
            else if (gap == 1 && str[i] == str[j])
                dp[i][j] = 1;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != -1)
            {
                dp[i][j] = j - i;
            }
            
               if(ans <dp[i][j])
                {
                    a=i;
                    b=j;
                }
        }
    }
    string res;
    for(int i =a;i<=b;i++)
    {
        res+=str[i];
    }
    return res;
}

};