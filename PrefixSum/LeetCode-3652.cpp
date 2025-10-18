class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        int n = prices.size();
        vector<long long> prefix(n, 0);
        vector<long long> original(n, 0);
        original[0] = prices[0];
        prefix[0] = prices[0] * strategy[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + (prices[i] * strategy[i]);
            original[i] = original[i - 1] + prices[i];
        }
        long long ans = prefix[n - 1];
        for (int i = k - 1; i < n; i++)
        {
            long long leftSum = 0;
            long long rightSum = 0;

            long long slidSum = original[i] - original[i - (k / 2)];
            if (i - k >= 0)
            {
                leftSum = prefix[i - k];
            }
            rightSum = prefix[n - 1] - prefix[i];
            long long result = leftSum + rightSum + slidSum;
            ans = max(ans, result);
        }

        return ans;
    }
};