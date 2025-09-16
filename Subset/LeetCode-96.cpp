class Solution
{
public:
    int helper(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1 || n == 2)
            return n;
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            ans += helper(j - 1) * helper(n - j);
        }
        return ans;
    }
    int numTrees(int n)
    {
        return helper(n);
    }
};