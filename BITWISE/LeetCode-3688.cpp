class Solution
{
public:
    int evenNumberBitwiseORs(vector<int> &nums)
    {
        int even = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] % 2 == 0)
            {
                even |= nums[j];
            }
        }
        return even;
    }
};