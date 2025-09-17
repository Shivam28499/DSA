class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
        {
            if (nums[0] < nums[1])
                return nums[0];
            else
                return nums[1];
        }
        int lo = 0;
        int hi = n - 1;
        int mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi])
                hi = mid;
            else if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi--;
        }
        return nums[mid];
    }
};