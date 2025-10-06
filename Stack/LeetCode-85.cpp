class Solution
{
public:
    int findMaxArea(vector<int> &height)
    {
        int n = height.size();
        stack<int> st;
        vector<int> ngi(n);
        ngi[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (st.size() > 0 and height[st.top()] >= height[i])
                st.pop();
            if (st.size() == 0)
                ngi[i] = n;
            else
                ngi[i] = st.top();
            st.push(i);
        }
        stack<int> gt;
        vector<int> pgi(n);
        pgi[0] = -1;
        gt.push(0);
        for (int i = 1; i < n; i++)
        {
            while (gt.size() > 0 and height[gt.top()] >= height[i])
                gt.pop();
            if (gt.size() == 0)
                pgi[i] = -1;
            else
                pgi[i] = gt.top();
            gt.push(i);
        }

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int h = height[i];
            int w = ngi[i] - pgi[i] - 1;
            maxArea = max(maxArea, h * w);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n);
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == '0')
                height[i] = 0;
            else
                height[i] = 1;
        }
        int maxArea = findMaxArea(height);
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] = height[j] + 1;
            }
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
};