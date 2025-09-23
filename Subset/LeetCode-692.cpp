class cmp
{
public:
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        vector<string> ans;
        for (auto x : words)
            mp[x]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        while (!pq.empty() and k--)
        {
            pair<int, string> pp = pq.top();
            pq.pop();
            ans.push_back(pp.second);
        }
        return ans;
    }
};