class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        while (j < n)
        {
            while ((long long)nums[j] > (long long int)nums[i] * k)
                i++;
            ans = max(ans, j - i + 1);
            j++;
        }
        return n - ans;
    }
};