class Solution
{
public:
    void helper(string src, string dest, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &vis, double &ans, double product)
    {
        if (vis.find(src) != vis.end())
        {
            return;
        }
        vis.insert(src);
        if (src == dest)
        {
            ans = product;
        }
        for (auto node : adj[src])
        {
            string curr = node.first;
            double val = node.second;
            helper(curr, dest, adj, vis, ans, product * val);
        }
    }

    vector<double> calcEquation(vector<vector<string>> &eq, vector<double> &values, vector<vector<string>> &qu)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = eq.size();
        for (int i = 0; i < n; i++)
        {
            string a = eq[i][0];
            string b = eq[i][1];
            double val = values[i];
            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }
        vector<double> result;
        for (int i = 0; i < qu.size(); i++)
        {
            unordered_set<string> vis;
            string src = qu[i][0];
            string dest = qu[i][1];
            double ans = -1.0;
            double product = 1.0;
            if (adj.find(src) != adj.end())
            {
                helper(src, dest, adj, vis, ans, product);
            }
            result.push_back(ans);
        }
        return result;
    }
};