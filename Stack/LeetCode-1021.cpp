class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int n = s.size();
        int op = 0, cl = 0;
        string p = "";
        for (int i = 0; i < n; i++)
        {
            p += s[i];
            if (s[i] == '(')
                op++;
            else
                cl++;
            if (op == cl)
            {
                ans += p.substr(1, p.size() - 2);
                p = "";
                op = 0, cl = 0;
            }
        }
        return ans;
    }
};