
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;

        for (int i : set)
        {
            if (set.count(i - 1) == 0)
            {
                int small = 1;
                int num = i;

                while (set.find(num + 1) != set.end())
                {
                    small++;
                    num++;
                }
                ans = max(ans, small);
            }
        }

        return ans;
    }
};