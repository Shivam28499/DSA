class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }
        int j = k;
        vector<int> ans;
        ans.push_back(pq.top().first);
        while (j < n)
        {
            pq.push({nums[j], j});
            while (pq.top().second <= j - k)
                pq.pop();
            ans.push_back(pq.top().first);
            j++;
        }
        return ans;
    }
};