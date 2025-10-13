class Solution
{
public:
    bool scoreBalance(string s)
    {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += (int)(s[i] - 'a') + 1;
        if (sum % 2 != 0)
            return false;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += s[i] - 'a' + 1;
            if (count == (sum / 2))
                return true;
            if (count > (sum / 2))
                return false;
        }
        return false;
    }
};