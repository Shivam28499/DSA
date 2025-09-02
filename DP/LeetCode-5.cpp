class Solution {
public:
    int check[1005][1005];
    void isPalindrom(string& s,string& ans){
        int n = s.size();
        for(int L=1;L<=n;L++){
            for(int i=0;L+i-1<n;i++){
                int j = L+i-1;
                if(i==j) check[i][j] = true;
                else if(i+1==j){
                    if(s[i]==s[j]) check[i][j] = true;
                    else check[i][j] = false;
                } else{
                    if(s[i]==s[j] and check[i+1][j-1]) check[i][j] = true;
                    else check[i][j] = false;
                }
                if(check[i][j] and L>ans.size()) ans = s.substr(i,L);
            }
        }
    }
    string longestPalindrome(string s) {
        string ans;
        isPalindrom(s,ans);
        return ans;
    }
};