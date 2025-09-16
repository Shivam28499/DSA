class Solution
{
public:
    vector<string> result;
    void helper(int ob, int cb, int n, string &ans)
    {
        if (cb == n)
        {
            result.push_back(ans);
            return;
        }
        if (ob < n)
        {
            ans.push_back('(');
            helper(ob + 1, cb, n, ans);
            ans.pop_back();
        }
        if (ob > cb)
        {
            ans.push_back(')');
            helper(ob, cb + 1, n, ans);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string ans = "";
        helper(0, 0, n, ans);
        return result;
    }
};