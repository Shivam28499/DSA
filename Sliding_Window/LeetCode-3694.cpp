class Solution
{
public:
    int distinctPoints(string s, int k)
    {
        int n = s.size();
        set<pair<int, int>> st;
        pair<int, int> pp = {0, 0};
        for (int j = k; j < n; j++)
        {
            if (s[j] == 'U')
                pp.second++;
            if (s[j] == 'D')
                pp.second--;
            if (s[j] == 'L')
                pp.first--;
            if (s[j] == 'R')
                pp.first++;
        }
        int j = k, i = 0;
        st.insert(pp);
        while (j < n)
        {
            if (s[i] == 'U')
                pp.second++;
            if (s[i] == 'D')
                pp.second--;
            if (s[i] == 'L')
                pp.first--;
            if (s[i] == 'R')
                pp.first++;

            if (s[j] == 'U')
                pp.second--;
            if (s[j] == 'D')
                pp.second++;
            if (s[j] == 'L')
                pp.first++;
            if (s[j] == 'R')
                pp.first--;
            i++, j++;
            st.insert(pp);
        }
        return st.size();
    }
};