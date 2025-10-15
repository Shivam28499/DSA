class Solution
{
public:
    void solve(string &s, char x, char y, int &maxi)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == x)
            {
                sum += 1;
            }
            else if (s[i] == y)
            {
                sum -= 1;
            }
            else
            {
                mp.clear();
                mp[0] = i;
                sum = 0;
                continue;
            }

            if (mp.find(sum) != mp.end())
            {
                maxi = max(maxi, i - mp[sum]);
            }
            else
                mp[sum] = i;
        }
    }

    int longestBalanced(string s)
    {
        int n = s.size();
        int len = 1, maxi = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                len++;
            }
            else
            {
                maxi = max(len, maxi);
                len = 1;
            }
        }

        maxi = max(len, maxi);

        solve(s, 'a', 'b', maxi);
        solve(s, 'b', 'c', maxi);
        solve(s, 'a', 'c', maxi);

        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        vector<int> count(3, 0);
        for (int i = 0; i < n; i++)
        {
            count[s[i] - 'a']++;
            int countAB = count[0] - count[1];
            int countBC = count[0] - count[2];
            if (mp.find({countAB, countBC}) != mp.end())
            {
                maxi = max(maxi, i - mp[{countAB, countBC}]);
            }
            else
            {
                mp[{countAB, countBC}] = i;
            }
        }
        return maxi;
    }
};