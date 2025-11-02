class Solution
{
public:
    long long check(vector<int> &order, int t)
    {
        int n = order.size();
        vector<int> isStar(n, 0);
        for (int i = 0; i <= t; i++)
            isStar[order[i]] = 1;
        long long inValidString = 0, length = 0;
        int j = 0;
        while (j < n)
        {
            if (isStar[j])
            {
                inValidString += ((long long)length * (long long)(length + 1) / 2);
                length = 0;
            }
            else
                length++;
            j++;
        }
        inValidString += ((long long)length * (long long)(length + 1) / 2);
        return ((long long)n * (long long)(n + 1) / 2) - (long long)inValidString;
    }
    int minTime(string s, vector<int> &order, int k)
    {
        int ans = 0;
        int n = order.size();
        if ((long long)k > ((long long)n * (long long)(n + 1) / 2))
            return -1;
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (check(order, mid) >= (long long)k)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};