class Solution {
public:
    int dp[1005];
    int helper(int i,vector<int>&cost){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        ans = cost[i] + min({ans,helper(i+1,cost),helper(i+2,cost)});
        return dp[i] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        return min(helper(0,cost),helper(1,cost));  
    }
};