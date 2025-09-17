class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int diff_min = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = abs(arr[i + 1] - arr[i]);
            while (ans.size() > 0 and diff_min > diff)
            {
                ans.pop_back();
            }
            diff_min = min(diff, diff_min);
            if (diff == diff_min)
                ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};