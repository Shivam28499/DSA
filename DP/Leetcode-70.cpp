class Solution {
public:
    int dp[50];
    int helper(int n){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans1 = helper(n-1);
        int ans2 = 0;
        if(n-2>=0) ans2 = helper(n-2);
        return dp[n] = ans1 + ans2;

    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
      return  helper(n);
    }
};