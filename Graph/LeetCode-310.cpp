class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }

        queue<int> qu;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                qu.push(i);
            }
        }

        while (n > 2)
        {
            int size = qu.size();
            n -= size;
            while (size--)
            {
                int node = qu.front();
                qu.pop();
                for (auto curr : adj[node])
                {
                    indegree[curr]--;
                    if (indegree[curr] == 1)
                    {
                        qu.push(curr);
                    }
                }
            }
        }
        vector<int> result;
        while (!qu.empty())
        {
            result.push_back(qu.front());
            qu.pop();
        }
        return result;
    }
};