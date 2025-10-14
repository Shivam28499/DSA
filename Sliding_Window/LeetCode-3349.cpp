class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int size = k - 1;
        if (size == 0)
            return true;
        for (int j = k + 1; j < n; j++)
        {
            if (nums[j] > nums[j - 1] and nums[j - k] > nums[j - k - 1])
                size--;
            else
                size = k - 1;
            if (size == 0)
                return true;
        }
        return false;
    }
};