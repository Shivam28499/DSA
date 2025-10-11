class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        unordered_map<string, int> st;
        for (auto x : words)
        {
            st[x]++;
        }
        int n = s.size();
        int count = 0;
        for (auto x : st)
        {
            int start1 = 0, start2 = 0;
            string p = x.first;
            int m = p.size();
            while (start1 < n and start2 < m)
            {
                if (p[start2] == s[start1])
                {
                    start1++, start2++;
                }
                else
                {
                    start1++;
                }
            }
            if (start2 == m)
                count += x.second;
        }
        return count;
    }
};