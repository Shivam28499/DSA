class Solution
{
public:
    int dp[505][505][3];
    int mod = 1e9 + 7;
    int helper(int i, int j, vector<vector<int>> &grid, int m, int n, bool flag)
    {
        if (i == m - 1 and j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j][flag] != -1)
            return dp[i][j][flag];
        if (grid[i][j] == 1)
        {
            if (flag)
                return dp[i][j][flag] = helper(i, j + 1, grid, m, n, false);
            else
                return dp[i][j][flag] = helper(i + 1, j, grid, m, n, true);
        }
        return dp[i][j][flag] = (helper(i + 1, j, grid, m, n, true) % mod + helper(i, j + 1, grid, m, n, false) % mod) % mod;
    }
    int uniquePaths(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        bool flag = true;
        memset(dp, -1, sizeof dp);
        return helper(0, 0, grid, m, n, flag);
    }
};