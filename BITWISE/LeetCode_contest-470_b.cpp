class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int ans = 0, max_ = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            ans = ans ^ nums[i];
            max_ = max(max_, nums[i]);
        }
        if (max_ == 0)
            return 0;
        if (ans == 0)
            return n - 1;
        return n;
    }
};