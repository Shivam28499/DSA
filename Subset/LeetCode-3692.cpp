class Solution
{
public:
    string majorityFrequencyGroup(string s)
    {
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a']++;
        }
        int count = 0, val = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] == 0)
                continue;
            mp[arr[i]]++;
        }

        for (auto x : mp)
        {
            if (x.second > val)
            {
                count = x.first;
                val = x.second;
            }
            else if (x.second == val)
            {
                if (x.first > count)
                    count = x.first;
            }
            cout << x.first << " " << x.second << endl;
        }

        string p = "";
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] == count)
            {
                char ch = i + 'a';
                p = p + ch;
            }
        }
        return p;
    }
};