class NumArray
{
public:
    vector<int> prefix;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        prefix.resize(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};