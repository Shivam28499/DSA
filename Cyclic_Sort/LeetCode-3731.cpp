class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = nums[0];
        vector<int> ans;
        int i = 0;
        while (i < nums.size())
        {
            if (count != nums[i])
                ans.push_back(count);
            else
                i++;
            count++;
        }
        return ans;
    }
};