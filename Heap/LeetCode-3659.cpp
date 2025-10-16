class Solution
{
public:
    bool partitionArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % k != 0)
            return false;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        unordered_map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        for (auto x : mp)
            pq.push({x.second, x.first});
        while (pq.size() >= k)
        {
            int m = k;
            vector<vector<int>> vec;
            while (m--)
            {
                auto pp = pq.top();
                pq.pop();
                pp.first--;
                if (pp.first > 0)
                    vec.push_back({pp.first, pp.second});
            }
            for (int i = 0; i < vec.size(); i++)
                pq.push({vec[i][0], vec[i][1]});
        }
        return pq.size() == 0;
    }
};