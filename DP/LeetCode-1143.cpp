class Solution {
public:
    int dp[1005][1005];
    int helper(int i,int j,string& s1,string& s2){
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + helper(i+1,j+1,s1,s2);
        }else{
            return dp[i][j] = max(helper(i+1,j,s1,s2),helper(i,j+1,s1,s2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
      return helper(0,0,text1,text2);  
    }
};