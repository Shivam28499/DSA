class Solution
{
public:
    int dp[601][101][101];
    int helper(int i, vector<string> &strs, int m, int n)
    {
        if (i >= strs.size() || (m <= 0 and n <= 0))
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        string s = strs[i];
        int zero = 0, one = 0;
        for (auto x : s)
        {
            if (x == '1')
                one++;
            else
                zero++;
        }
        if (one > n || zero > m)
            return dp[i][m][n] = helper(i + 1, strs, m, n);
        return dp[i][m][n] = max(1 + helper(i + 1, strs, m - zero, n - one), helper(i + 1, strs, m, n));
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        memset(dp, -1, sizeof dp);
        return helper(0, strs, m, n);
    }
};