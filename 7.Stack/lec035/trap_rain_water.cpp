// https://leetcode.com/problems/trapping-rain-water/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (!n)
            return 0;
        vector<int> leftGreatest(n, 0);
        vector<int> rightGreatest(n, 0);

        leftGreatest[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftGreatest[i] = max(height[i], leftGreatest[i - 1]);
        }

        rightGreatest[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightGreatest[i] = max(height[i], rightGreatest[i + 1]);
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++)
        {
            totalWater += min(leftGreatest[i], rightGreatest[i]) - height[i];
        }

        return totalWater;
    }
};

// =================================================================================================================


class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (!n)
            return 0;
        int totalWater=0;
        
        int leftMax=0;
        int rightMax=0;
        int left=0;
        int right=n-1;
        
        while(left<right)
        {
            leftMax=max(leftMax,height[left]);    
            rightMax=max(rightMax,height[right]);
            
            if(leftMax <= rightMax)
            {
                totalWater+=leftMax-height[left];
                left++;
            }
            else{
                totalWater+=rightMax-height[right];
                right--;
            }

        }
        
        return totalWater;
    }
};