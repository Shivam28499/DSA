class Solution {
public:
    int dp[505][505];
    int helper(int i,int j,string& s){
        if(i > j || i>=s.size() || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 500;
        if(s[i]==s[j]){
            ans = min(ans,helper(i+1,j-1,s));
        }else{
           int ans1 = 1 +  helper(i,j-1,s);
           int ans2 = 1 +  helper(i+1,j,s);
           ans = min(ans1,ans2);
        }
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        return helper(0,s.size()-1,s);
    }
};