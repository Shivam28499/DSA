class Solution
{
public:
    vector<int> ans;
    void helper(int i, int n, int k, vector<int> &factor, vector<int> &res, long long prod)
    {
        if (i >= factor.size())
            return;
        if (prod == n and res.size() == k)
        {
            if (ans.size() == 0)
                ans = res;
            else if ((ans[ans.size() - 1] - ans[0]) > (res[res.size() - 1] - res[0]))
            {
                ans.clear();
                ans = res;
            }
            return;
        }
        for (int j = i; j < factor.size(); j++)
        {
            if ((long long)(factor[j] * prod) <= n and res.size() < k)
            {
                res.push_back(factor[j]);
                helper(j, n, k, factor, res, prod * factor[j]);
                res.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k)
    {
        vector<int> factor;
        factor.push_back(1);
        vector<int> res;
        for (int i = 2; i <= sqrt(n); i++)
        {
            int d = n / i;
            if (d * i == n)
            {
                factor.push_back(i);
                factor.push_back(d);
            }
        }
        for (int i = 0; i < factor.size(); i++)
            cout << factor[i] << " ";
        long long prod = 1;
        helper(0, n, k, factor, res, prod);
        return ans;
    }
};