class Solution {
public:
    int dp[105];
    int helper(int i,vector<int>&nums){
        if(i>=nums.size()) return 0;
        int ans1 = INT_MIN;
        int ans2 = INT_MIN;
        if(dp[i]!=-1) return dp[i];
        ans1 = helper(i+1,nums);
        ans2 = nums[i] + max(ans2,helper(i+2,nums));
        return dp[i] = max(ans1,ans2);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return helper(0,nums);
    }
};