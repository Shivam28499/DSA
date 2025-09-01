class Solution {
public:
    int dp[5005][305];
    int helper(int i,vector<int>& coins,int k){
        if(k==0){
            return 1;
        }
        if(dp[k][i]!=-1) return dp[k][i];
         int ans = 0;
        for(int j=i;j<coins.size();j++){
            if(k-coins[j]<0) continue;
             ans +=helper(j,coins,k-coins[j]);
        }
        return dp[k][i] = ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return helper(0,coins,amount);
    }
};