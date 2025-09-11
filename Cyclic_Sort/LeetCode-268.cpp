class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n + 1, INT_MIN);
        for (int i = 0; i < n; i++)
        {
            v[nums[i]] = nums[i];
        }
        for (int i = 0; i <= n; i++)
        {
            if (v[i] == INT_MIN)
                return i;
        }
        return -1;
    }
};