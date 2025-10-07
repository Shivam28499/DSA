class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int n = pushed.size();
        stack<int> st;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            st.push(pushed[i]);
            while (j < n and !st.empty() and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        if (st.size())
            return false;
        return true;
    }
};