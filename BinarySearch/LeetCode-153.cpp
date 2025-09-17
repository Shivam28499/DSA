class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int lo = 0, hi = nums.size() - 1, ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[n - 1])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
                ans = mid;
            }
        }
        if (ans == -1)
            return nums[0];
        return nums[ans];
    }
};