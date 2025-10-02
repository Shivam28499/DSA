class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        int mod = 1e9 + 7;
        vector<int> dp(r + 1, 1);
        for (int i = 1; i < n; i++)
        {
            vector<int> new_dp(r + 1);
            if (i % 2 == 1)
            {
                int pre = 0;
                for (int x = l; x <= r; x++)
                {
                    new_dp[x] = pre;
                    pre = (pre % mod + dp[x] % mod) % mod;
                }
            }
            else
            {
                int suff = 0;
                for (int x = r; x >= l; x--)
                {
                    new_dp[x] = suff;
                    suff = (suff % mod + dp[x] % mod) % mod;
                }
            }
            dp = new_dp;
        }
        long long count = 0;
        for (int x = l; x <= r; x++)
        {
            count = (count % mod + dp[x] % mod) % mod;
        }
        return (int)((count * 2) % mod);
    }
};