class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int max_ = INT_MIN, min_ = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            max_ = max(max_, nums[i]);
            min_ = min(min_, nums[i]);
        }
        long long val = max_ - min_;
        long long ans = (long long)(val * k);
        return ans;
    }
};