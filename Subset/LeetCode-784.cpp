class Solution
{
public:
    vector<string> result;
    void helper(int i, string &s, string p)
    {
        if (i >= s.size())
        {
            result.push_back(p);
            return;
        }
        cout << p << endl;
        if (isdigit(s[i]) != 0)
        {
            helper(i + 1, s, p + char(s[i]));
        }
        else if (isalpha(s[i]))
        {
            cout << "character" << endl;
            helper(i + 1, s, p + char(tolower(s[i])));
            helper(i + 1, s, p + char(toupper(s[i])));
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        string p = "";
        helper(0, s, p);
        return result;
    }
};