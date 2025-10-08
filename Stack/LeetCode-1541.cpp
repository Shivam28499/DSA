class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size(), ans = 0;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                if (st.empty())
                {
                    st.push('(');
                }
                else
                {
                    if (st.top() != '(')
                    {
                        ans++;
                        st.pop();
                        st.pop();
                    }
                    st.push('(');
                }
            }
            else
            {
                if (st.empty())
                {
                    st.push('(');
                    st.push(')');
                    ans++;
                }
                else
                {
                    if (st.top() == '(')
                    {
                        st.push(')');
                    }
                    else
                    {
                        st.pop();
                        st.pop();
                    }
                }
            }
        }
        if (st.empty())
            return ans;
        else
        {
            while (!st.empty())
            {
                char c = st.top();
                if (c == '(')
                {
                    ans += 2;
                    st.pop();
                }
                else
                {
                    ans++;
                    st.pop();
                    st.pop();
                }
            }
        }
        return ans;
    }
};