class Solution
{
public:
    int binarySum(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        int i = 0, j = 0, n = nums.size(), ans = 0;
        while (j < n)
        {
            if (nums[j] == 1)
            {
                if (k > 0)
                    k--;
                else
                {
                    while (nums[i] == 0)
                        i++;
                    i++;
                }
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return binarySum(nums, goal) - binarySum(nums, goal - 1);
    }
};