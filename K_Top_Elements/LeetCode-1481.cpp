class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (auto x : arr)
        {
            mp[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        while (!pq.empty())
        {
            if (k < pq.top().first)
                break;
            k -= pq.top().first;
            pq.pop();
        }
        return pq.size();
    }
};