class Solution {
public:
    int dp[10005];
    int helper(int i,vector<int>& nums){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int result = 100000;
        for(int j=i;j<nums[i]+i;j++){
            int ans = 1 + helper(j+1,nums);
            result = min(ans,result);
        }
        return dp[i] = result;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return helper(0,nums);
    }
};