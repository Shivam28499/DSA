class Solution
{
public:
    vector<double> prefix;
    vector<vector<double>> dp;

    double avg(int i, int j)
    {
        return (prefix[j + 1] - prefix[i]) / (j - i + 1);
    }

    double f(int i, vector<int> &nums, int k)
    {
        int n = nums.size();
        if (dp[i][k] != -1)
            return dp[i][k];
        if (k == 1)
            return dp[i][k] = avg(i, n - 1);
        double ans = 0;
        for (int j = i; j < n; j++)
        {
            ans = max(ans, avg(i, j) + f(j + 1, nums, k - 1));
        }
        return dp[i][k] = ans;
    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        prefix.resize(n + 1, 0);
        dp.resize(n + 1, vector<double>(k + 1, -1));
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        return f(0, nums, k);
    }
};