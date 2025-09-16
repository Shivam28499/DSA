class Solution
{
public:
    vector<vector<int>> result;
    void helper(vector<int> &nums, int i)
    {
        if (i >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int idx = i; idx < nums.size(); idx++)
        {
            swap(nums[i], nums[idx]);
            helper(nums, i + 1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        helper(nums, 0);
        return result;
    }
};