class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (st.size() > 0 and arr[st.top()] <= arr[i])
                st.pop();
            if (st.size() == 0)
                prefix[i] = i + 1;
            else
                prefix[i] = i - st.top();
            st.push(i);
        }
        return prefix;
    }
};