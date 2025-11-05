class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_map<int, vector<int>> adj;
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int a = isConnected[i][j];
                if (i != j and a != 0)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        unordered_set<int> vis;
        queue<int> qu;
        for (int i = 0; i < n; i++)
        {
            if (vis.find(i) == vis.end())
            {
                ans++;
                qu.push(i);
                while (!qu.empty())
                {
                    int node = qu.front();
                    qu.pop();
                    vis.insert(node);
                    for (auto x : adj[node])
                    {
                        if (vis.find(x) == vis.end())
                        {
                            qu.push(x);
                        }
                    }
                }
            }
        }
        return ans;
    }
};