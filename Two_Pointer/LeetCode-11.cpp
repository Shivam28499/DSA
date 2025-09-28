class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, ans = 0, min_ = INT_MAX;
        while (i < j)
        {
            min_ = min(height[i], height[j]);
            long long result = (long long)(j - i) * min_;
            if (ans < result)
                ans = result;
            if (min_ == height[i])
                i++;
            if (min_ == height[j])
                j--;
        }
        return ans;
    }
};