class Solution
{
public:
    int binarySearch(int lo, int hi, vector<int> &nums, int target)
    {
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        if (nums[0] < nums[n - 1])
        {
            int index = binarySearch(0, n - 1, nums, target);
            if (index == -1)
                return -1;
            return index;
        }

        int lo = 0, hi = n - 1, ans = -1;

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
        hi = n - 1;
        if (nums[hi] >= target)
        {
            int index = binarySearch(ans, hi, nums, target);
            if (index == -1)
                return -1;
            return index;
        }
        else
        {
            int index = binarySearch(0, ans - 1, nums, target);
            if (index == -1)
                return -1;
            return index;
        }
        return -1;
    }
};