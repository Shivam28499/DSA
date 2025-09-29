class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size(), sum = 0, maxsum = INT_MIN, minsum = INT_MAX, totalsum = 0;
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            totalsum += nums[i];
            sum += nums[i];
            maxsum = max(sum, maxsum);
            if (sum <= 0)
                sum = 0;
        }
        cout << maxsum << " ";
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = min(sum + nums[i], nums[i]);
            minsum = min(minsum, sum);
        }
        cout << minsum << " ";
        int circularsum = totalsum - minsum;
        if (maxsum > 0)
            return max(maxsum, circularsum);
        return maxsum;
    }
};