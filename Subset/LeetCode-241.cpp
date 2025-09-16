class Solution
{
public:
    vector<int> diffWaysToCompute(string s)
    {
        int n = s.size();
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i + 1));
                for (int x : left)
                {
                    for (int y : right)
                    {
                        if (s[i] == '+')
                            result.push_back(x + y);
                        if (s[i] == '-')
                            result.push_back(x - y);
                        if (s[i] == '*')
                            result.push_back(x * y);
                    }
                }
            }
        }
        if (!result.size())
            result.push_back(stoi(s));
        return result;
    }
};