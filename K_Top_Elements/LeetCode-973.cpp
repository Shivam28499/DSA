class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        for (int i = 0; i < points.size(); i++)
        {
            double distance = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            pq.push({distance, i});
        }
        vector<vector<int>> ans;
        while (!pq.empty() and k--)
        {
            auto pp = pq.top();
            int index = pp.second;
            ans.push_back(points[index]);
            pq.pop();
        }
        return ans;
    }
};