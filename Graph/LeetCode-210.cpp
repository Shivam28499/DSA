class Solution
{
public:
    bool canFinish(int num, vector<vector<int>> &pre)
    {
        int n = pre.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(num, 0);
        for (int i = 0; i < n; i++)
        {
            int a = pre[i][0];
            int b = pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> qu;
        int count = 0;
        for (int i = 0; i < num; i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
                count++;
            }
        }

        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            for (auto curr : adj[node])
            {
                indegree[curr]--;
                if (indegree[curr] == 0)
                {
                    qu.push(curr);
                    count++;
                }
            }
        }
        return count == num;
    }
};