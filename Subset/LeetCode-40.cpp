class Solution
{
public:
    vector<vector<int>> result;
    set<vector<int>> st;
    void helper(int i, vector<int> &nums, int target, vector<int> &ans)
    {
        if (target == 0)
        {
            st.insert(ans);
            return;
        }
        if (!st.count(ans))
            for (int idx = i; idx < nums.size(); idx++)
            {
                if (idx > i and nums[idx] == nums[idx - 1])
                    continue;
                if (target - nums[idx] < 0)
                    break;
                ans.push_back(nums[idx]);
                helper(idx + 1, nums, target - nums[idx], ans);
                ans.pop_back();
            }
    }
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        helper(0, nums, target, ans);
        for (auto x : st)
            result.push_back(x);
        return result;
    }
};