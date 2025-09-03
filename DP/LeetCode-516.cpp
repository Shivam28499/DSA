class Solution {
public:
    int dp[1005][1005];
    int helper(int i,int j,string& s){
        if(i>=s.size() || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i]==s[j]){
           ans = 1 + helper(i+1,j-1,s);
        }else{
             ans = max(helper(i+1,j,s),helper(i,j-1,s));
        }
        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof dp);
       return helper(0,s.size()-1,s);
    }
};