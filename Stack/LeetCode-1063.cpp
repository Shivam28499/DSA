class Solution
{
public:
    int validSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n - 1] = n;
        stack<int> st;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i++)
        {
            while (st.size() > 0 and nums[st.top()] >= nums[i])
                st.pop();
            if (st.size() == 0)
                suffix[i] = n;
            else
                suffix[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += suffix[i] - i;
        }
        return ans;
    }
}