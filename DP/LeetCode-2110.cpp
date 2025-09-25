class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (prices[i - 1] - 1 == prices[i])
                dp[i] = max(dp[i], dp[i - 1] + 1);
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum = (long long)sum + (long long)dp[i];
        return sum;
    }
};