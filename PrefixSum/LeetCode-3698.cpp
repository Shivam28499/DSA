class Solution
{
public:
    long long splitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> check(n, false);
        check[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
                check[i] = true;
            else
                break;
        }

        long long psum = 0, ans = 1e18, sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        for (int i = 0; i < n - 1; i++)
        {
            psum += nums[i];
            if (i and nums[i] <= nums[i - 1])
                break;
            if (!check[i + 1])
                continue;
            ans = min(ans, abs(sum - 2 * psum));
        }
        if (ans == 1e18)
            return -1;
        return ans;
    }
};