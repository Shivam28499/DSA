class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(s[i]);
            else{
                if(s[i]==')' and st.top()=='(') st.pop();
                else st.push(s[i]); 
            }
        } 
        return st.size();
    }
};