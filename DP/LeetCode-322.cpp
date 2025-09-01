#define ll long long
class Solution {
public:
    int dp[10005];
    int helper(vector<int>&coins,int amount){
        if(amount==0) return 0;
        if(amount<0) return 10001;
        if(dp[amount]!=-1) return dp[amount];
        int ans = INT_MAX;
        for(int j=0;j<coins.size();j++){
            ans = min(ans,helper(coins,amount-coins[j]));
        }
        return dp[amount] = 1 + ans;
    }

    int coinChange(vector<int>& coins, int amount) {
       memset(dp,-1,sizeof dp);
       int res = helper(coins,amount);
        if(res>=10001) return -1;
        return res;
    }
};