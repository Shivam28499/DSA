class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            s[j] = s[i];
            if (j >= 2 and s[j - 2] == 'a' and s[j - 1] == 'b' and s[j] == 'c')
                j -= 3;
            j++;
        }
        return j == 0;
    }
};