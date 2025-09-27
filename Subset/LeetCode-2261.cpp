class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int n = nums.size();
        unordered_set<string> st;
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            string s = "";
            for (int j = i; j < n; j++)
            {
                s += nums[j] + '0';
                if (nums[j] % p == 0)
                    c++;
                if (c <= k)
                    st.insert(s);
                else
                    break;
            }
        }
        return st.size();
    }
};