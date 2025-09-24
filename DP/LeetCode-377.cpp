class Solution {
public:
    int dp[1005];
    int helper(vector<int>& nums,int target){
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int ans = 0;
        for(int j=0;j<nums.size();j++){
            if(target-nums[j]<0) break;
               ans += helper(nums,target-nums[j]);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof dp);
        return helper(0,nums,target);
    }
};