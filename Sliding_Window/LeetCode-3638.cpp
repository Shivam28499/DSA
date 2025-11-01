class Solution
{
public:
    int maxBalancedShipments(vector<int> &weight)
    {
        int n = weight.size();
        int i = 0, ans = 0;
        while (i < n - 1)
        {
            if (weight[i] > weight[i + 1])
            {
                ans++;
                i += 2;
            }
            else
                i++;
        }
        return ans;
    }
};