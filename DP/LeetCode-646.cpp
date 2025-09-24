class Solution
{
public:
    int dp[1005][2010];
    int helper(int i, vector<vector<int>> &pairs, int prev)
    {
        if (i >= pairs.size())
            return 0;
        if (dp[i][prev + 1002] != -1)
            return dp[i][prev + 1002];
        if (pairs[i][0] <= prev)
            return dp[i][prev + 1002] = helper(i + 1, pairs, prev);
        else
            return dp[i][prev + 1002] = max(1 + helper(i + 1, pairs, pairs[i][1]), helper(i + 1, pairs, prev));
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof dp);
        return helper(0, pairs, -1001);
    }
};