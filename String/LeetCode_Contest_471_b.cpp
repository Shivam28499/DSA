class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            int j = i;
            for (j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                int f = 0;
                int k = 0;
                for (k = 0; k < 26; k++)
                {
                    if (freq[k] != 0)
                    {
                        f = freq[k];
                        break;
                    }
                }
                bool flag = true;
                for (k = 0; k < 26; k++)
                {
                    if (freq[k] == 0)
                        continue;
                    if (f != freq[k])
                    {
                        flag = false;
                    }
                }
                if (flag)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};