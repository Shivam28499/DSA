class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        int index = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
            {
                index = mid;
                hi = mid - 1;
            }
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (index == -1)
            return {-1, -1};
        int i = index;
        while (i < nums.size() and nums[i] == target)
        {
            i++;
        }
        i--;
        return {index, i};
    }
};