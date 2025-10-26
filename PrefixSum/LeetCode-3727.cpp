class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() / 2; i++)
        {
            sum -= nums[i];
            sum -= nums[i];
        }
        return sum;
    }
};