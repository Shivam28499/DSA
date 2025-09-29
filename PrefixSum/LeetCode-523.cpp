class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int j = 0, sum = 0;
        mp[0] = -1;
        for (int j = 0; j < n; j++)
        {
            sum += nums[j];
            cout << sum << " ";
            if (mp.find(sum % k) != mp.end())
            {
                if (j - mp[sum % k] >= 2)
                    return true;
            }
            else
                mp[sum % k] = j;
        }
        return false;
    }
};