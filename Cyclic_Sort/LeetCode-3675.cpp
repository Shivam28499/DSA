class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size();
        vector<int> a(26, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            a[s[i] - 'a']++;
        }
        int i = 1;
        while (i < 26 and a[i] == 0)
            i++;
        for (; i < 26; i++)
        {
            count++;
        }

        return count;
    }
};