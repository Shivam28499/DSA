class Solution
{
public:
    int sumDivisibleByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        for (auto x : mp)
        {
            if (x.second % k == 0)
            {
                ans += x.first * x.second;
            }
        }
        return ans;
    }
};