class Solution
{
public:
    vector<int> findOrder(int num, vector<vector<int>> &pre)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(num, 0);
        int count = 0;
        for (auto vec : pre)
        {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> qu;
        vector<int> ans;
        for (int i = 0; i < num; i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
                count++;
                ans.push_back(i);
            }
        }

        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            for (auto x : adj[node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    qu.push(x);
                    count++;
                    ans.push_back(x);
                }
            }
        }
        if (count != num)
            return {};
        return ans;
    }
};