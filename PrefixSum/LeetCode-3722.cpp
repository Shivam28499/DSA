class Solution
{
public:
    string lexSmallest(string s)
    {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n; i++)
        {
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1);
            string t = a;
            reverse(a.begin(), a.end());
            a = a + b;
            reverse(b.begin(), b.end());
            b = t + b;
            ans = min({ans, a, b});
        }
        return ans;
    }
};