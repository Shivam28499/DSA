class Solution
{
public:
    int sortPermutation(vector<int> &nums)
    {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
                res = res & nums[i];
        }
        if (res == INT_MAX)
            return 0;
        return res;
    }
};