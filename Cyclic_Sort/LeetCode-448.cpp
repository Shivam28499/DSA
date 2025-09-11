class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n, INT_MIN);
        for (int i = 0; i < n; i++)
        {
            v[nums[i] - 1] = nums[i];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == INT_MIN)
                ans.push_back(i + 1);
        }
        return ans;
    }
};