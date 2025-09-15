class Solution
{
public:
    int binarySearch(vector<pair<int, int>> &new_intervals, int num)
    {
        int lo = 0;
        int hi = new_intervals.size() - 1;
        int ans = INT_MAX;
        int mid = (lo + hi) / 2;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            auto p = new_intervals[mid].first;
            if (num <= p)
            {
                hi = mid - 1;
                ans = min(ans, new_intervals[mid].second);
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> new_intervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            new_intervals.push_back({intervals[i][0], i});
        }
        sort(new_intervals.begin(), new_intervals.end());
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int index = binarySearch(new_intervals, intervals[i][1]);
            if (index == INT_MAX)
                ans.push_back(-1);
            else
                ans.push_back(index);
        }
        return ans;
    }
};