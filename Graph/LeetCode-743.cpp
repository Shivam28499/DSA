class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &x : times)
        {
            int a = x[0];
            int b = x[1];
            int c = x[2];
            adj[a].push_back({b, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        pq.push({0, k});
        while (!pq.empty())
        {
            auto pp = pq.top();
            pq.pop();
            int d = pp.first;
            int node = pp.second;
            for (auto &x : adj[node])
            {
                int adjNode = x.first;
                int wt = x.second;
                if (result[adjNode] > d + wt)
                {
                    pq.push({d + wt, adjNode});
                    result[x.first] = d + wt;
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, result[i]);
            cout << result[i] << " ";
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};