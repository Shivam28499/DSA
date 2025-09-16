class Solution
{
public:
    vector<vector<int>> result;
    void helper(int i, vector<int> &nums, vector<int> &ans)
    {
        if (i >= nums.size())
        {
            result.push_back(ans);
            return;
        }

        helper(i + 1, nums, ans);
        ans.push_back(nums[i]);
        helper(i + 1, nums, ans);
        ans.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> ans;
        helper(0, nums, ans);
        return result;
    }
};