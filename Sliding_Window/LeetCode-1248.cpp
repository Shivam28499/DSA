class Solution
{
public:
    int AtmaxK(vector<int> &nums, int k)
    {
        int i = 0, j = 0, ans = 0;
        while (j < nums.size())
        {
            if (nums[j] % 2 == 1)
            {
                if (k > 0)
                    k--;
                else
                {
                    while (nums[i] % 2 != 1)
                        i++;
                    i++;
                }
            }
            ans += j - i + 1;
            j++;
        }
        cout << ans << endl;
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return AtmaxK(nums, k) - AtmaxK(nums, k - 1);
    }
};