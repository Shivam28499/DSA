class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = trips.size();
        sort(trips.begin(), trips.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int C = 0;
        for (int i = 0; i < n; i++)
        {
            int a = trips[i][1];
            int b = trips[i][2];
            int c = trips[i][0];
            while (!pq.empty() and pq.top().first <= a)
            {
                pair<int, int> pp = pq.top();
                int d = pp.second;
                C -= d;
                pq.pop();
            }
            pq.push({trips[i][2], trips[i][0]});
            C += trips[i][0];
            if (C > capacity)
                return false;
        }
        return true;
    }
};