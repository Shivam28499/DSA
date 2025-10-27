class Solution
{
public:
    long long countStableSubarrays(vector<int> &capacity)
    {
        long long res = 0, pre = 0;
        int n = capacity.size();
        unordered_map<long long, unordered_map<long long, long long>> mpp;
        for (int i = 0; i < n; i++)
        {
            if (mpp.count(capacity[i]) and mpp[capacity[i]].count(pre - capacity[i]))
            {
                res += mpp[capacity[i]][pre - capacity[i]];
            }
            pre += capacity[i];
            mpp[capacity[i]][pre]++;
            if (i > 0 and capacity[i] == 0 and capacity[i - 1] == 0)
                res--;
        }
        return res;
    }
};