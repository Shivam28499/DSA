class Solution
{
public:
    bool validPalindrome(string s)
    {
        int i = 0, j = s.size() - 1, k = 0;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                if (k == 1)
                    return false;
                int p = i + 1, q = j;
                bool left = true;
                while (p < q)
                {
                    if (s[p] != s[q])
                    {
                        left = false;
                        break;
                    }
                    p++, q--;
                }
                p = i, q = j - 1;
                bool right = true;
                while (p < q)
                {
                    if (s[p] != s[q])
                    {
                        right = false;
                        break;
                    }
                    p++, q--;
                }
                return left || right;
            }
            else
            {
                i++, j--;
            }
        }
        return true;
    }
};