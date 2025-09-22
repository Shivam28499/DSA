class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (auto vec : edges)
        {
            int a = vec[0];
            int b = vec[1];
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
                for (auto x : adj[node])
                {
                    indegree[x]--;
                    if (indegree[x] == 1)
                    {
                        qu.push(x);
                    }
                }
            }
        }
        vector<int> ans;
        while (!qu.empty())
        {
            ans.push_back(qu.front());
            qu.pop();
        }
        return ans;
    }
};