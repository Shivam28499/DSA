class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxele = prices[n - 1], ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            maxele = max(maxele, prices[i]);
            ans = max(ans, maxele - prices[i]);
        }
        return ans;
    }
};