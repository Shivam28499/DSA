class Solution
{
public:
    long long minArraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<long long, long long> mp;
        long long sum = 0;
        mp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (mp.find(sum % k) != mp.end())
            {
                sum = min(sum, mp[sum % k]);
            }
            mp[sum % k] = sum;
        }
        return sum;
    }
};