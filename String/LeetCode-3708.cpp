class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 2;
        for (int i = 2; i < n; i++)
        {
            if (nums[i - 1] + nums[i - 2] == nums[i])
            {
                if (dp[i - 1] == 1)
                    dp[i] = dp[i - 1] + 2;
                else
                    dp[i] = dp[i - 1] + 1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};