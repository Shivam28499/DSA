class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        string ans = "";
        int nine = sum / 9;
        int rem = sum % 9;
        if (rem > 0)
        {
            int minDigit = nine + 1;
            if (minDigit > num)
                return "";

            for (int i = 1; i <= nine; i++)
            {
                ans += '9';
            }
            ans += rem + '0';
            while (ans.size() < num)
                ans += '0';
        }
        else
        {
            if (nine > num)
                return "";
            for (int i = 1; i <= nine; i++)
            {
                ans += '9';
            }
            while (ans.size() < num)
                ans += '0';
        }
        return ans;
    }
};