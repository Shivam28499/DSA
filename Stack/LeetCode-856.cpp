class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int>st;
        int count = 1;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(0);
            else {
                int temp = st.top();
                st.pop();
                int val = 0;
                if(temp>0) val = temp * 2;
                else val = 1;
                int p = 0;
                if(!st.empty()){
                    p = st.top();
                    st.pop();
                }
                p += val;
                st.push(p);
            }
        }
        return st.top();
    }
};