class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> qu;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                qu.push(i);
                color[i] = 0;
                while (!qu.empty())
                {
                    int src = qu.front();
                    qu.pop();
                    for (auto curr : graph[src])
                    {
                        if (color[curr] == -1)
                        {
                            qu.push(curr);
                            color[curr] = !color[src];
                        }
                        else if (color[src] == color[curr])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};