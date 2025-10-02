class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        int n = arrivals.size(), ans = 0;
        unordered_map<int, int> mp;
        int j = 0, i = 0;
        while (j < n)
        {
            mp[arrivals[j]]++;
            while (j - i + 1 > w)
            {
                mp[arrivals[i]]--;
                if (mp[arrivals[i]] == 0)
                    mp.erase(arrivals[i]);
                i++;
            }
            if (mp[arrivals[j]] > m)
            {
                ans++;
                mp[arrivals[j]]--;
                if (mp[arrivals[j]] == 0)
                    mp.erase(arrivals[j]);
                arrivals[j] = 0;
            }
            j++;
        }
        return ans;
    }
};