class Solution
{
public:
    vector<bool> subsequenceSumAfterCapping(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> result(n, false);
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        for (int i = 0, x = 1; x <= n; x++)
        {
            while (i < n and nums[i] <= x)
            {
                for (int j = k; j >= nums[i]; j--)
                {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
                i++;
            }
            int largerEle = n - i;
            for (int ne = 0; ne <= largerEle and k >= ne * x; ne++)
            {
                if (dp[k - ne * x] == true)
                {
                    result[x - 1] = true;
                    break;
                }
            }
        }
        return result;
    }
};