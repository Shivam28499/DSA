class Solution
{
public:
    vector<vector<int>> palindrom_string;
    vector<vector<string>> ans;
    void palindrom(string &s)
    {
        int n = s.size();
        for (int L = 1; L <= n; L++)
        {
            vector<string> result;
            for (int i = 0; L + i - 1 < n; i++)
            {
                string p = "";
                int j = L + i - 1;
                if (i == j)
                    palindrom_string[i][j] = 1;
                else if (i + 1 == j)
                {
                    if (s[i] == s[j])
                        palindrom_string[i][j] = 1;
                    else
                        palindrom_string[i][j] = 0;
                }
                else
                {
                    if (s[i] == s[j] and palindrom_string[i + 1][j - 1])
                        palindrom_string[i][j] = 1;
                    else
                        palindrom_string[i][j] = 0;
                }
            }
        }
    }

    void helper(int i, string &s, int n, vector<string> result)
    {
        if (i == n)
        {
            ans.push_back(result);
            return;
        }
        if (i >= n)
            return;
        for (int idx = i; idx < n; idx++)
        {
            if (palindrom_string[i][idx])
            {
                result.push_back(s.substr(i, idx - i + 1));
                helper(idx + 1, s, n, result);
                result.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        palindrom_string.resize(n, vector<int>(n, 0));
        palindrom(s);
        vector<string> result;
        helper(0, s, n, result);
        return ans;
    }
};