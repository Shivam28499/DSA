class Solution
{
public:
    long long removeZeros(long long n)
    {
        long long ans = 0;
        while (n > 0)
        {
            int rem = n % 10;
            n /= 10;
            if (rem == 0)
                continue;
            ans = ans * 10 + rem;
        }
        n = ans;
        ans = 0;
        while (n > 0)
        {
            int rem = n % 10;
            n /= 10;
            ans = ans * 10 + rem;
        }

        return ans;
    }
};