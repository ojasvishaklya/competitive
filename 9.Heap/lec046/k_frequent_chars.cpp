// https://leetcode.com/problems/top-k-frequent-elements/
class Solution
{
public:
    class comp
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int> &s, int k)
    {
        unordered_map<int, int> mp;

        string str;
        for (auto ch : s)
            mp[ch]++;

        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        for (auto ele : mp)
        {
            pq.push(ele);
        }
        while (k-- > 0)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }

        return ans;
    }
};
static int fastio = []() {
#define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
