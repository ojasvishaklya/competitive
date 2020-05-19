class Solution
{
public:
    int numTilePossibilities(string tiles)
    {

        return dfs(tiles, "");
    }

    int dfs(string tiles, string ans)
    {
        cout << ans << endl;

        if (tiles.size() == 0)
        {
            return 0;
        }
        int count = 0;
        int vis = 0;
        for (int i = 0; i < tiles.size(); i++)
        {
            int mask = (1 << (tiles[i] - 'A'));

            if ((vis & mask) == 0)
            {
                vis ^= mask;
                string s = tiles.substr(0, i) + tiles.substr(i + 1);
                count += dfs(s, ans + tiles[i]) + 1;
            }
        }

        return count;
    }
};