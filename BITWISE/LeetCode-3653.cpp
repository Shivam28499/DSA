class Solution
{
public:
    int mod = 1e9 + 7;
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = queries.size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = queries[i][0]; j <= queries[i][1]; j += queries[i][2])
            {
                long long x = nums[j];
                x *= queries[i][3];
                x %= mod;
                nums[j] = x;
            }
        }
        for (int i = 0; i < n; i++)
            ans = ans ^ nums[i];
        return ans;
    }
};