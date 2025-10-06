class Solution
{
public:
    int largestRectangleArea(vector<int> arr)
    {
        int n = arr.size();
        stack<int> st;
        int ngi[n];
        ngi[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (st.size() > 0 && arr[i] <= arr[st.top()])
                st.pop();
            if (st.size() == 0)
                ngi[i] = n;
            else
                ngi[i] = st.top();
            st.push(i);
        }
        stack<int> gt;
        int pgi[n];
        pgi[0] = -1;
        gt.push(0);
        for (int i = 1; i < n; i++)
        {
            while (gt.size() > 0 && arr[i] <= arr[gt.top()])
                gt.pop();
            if (gt.size() == 0)
                pgi[i] = -1;
            else
                pgi[i] = gt.top();
            gt.push(i);
        }
        int mxarea = 0;
        for (int i = 0; i < n; i++)
        {
            int h = arr[i];
            int b = ngi[i] - pgi[i] - 1;
            int area = h * b;
            mxarea = max(mxarea, area);
        }

        return mxarea;
    }
};