class Solution {
public:
    int dp[205][20005];
     bool helper(int i,vector<int>& nums,int sum,int target){
        if(sum==target) return true;
        if(i>=nums.size()) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool ans1 = false;
        if(sum+nums[i]<=target){
            ans1 =  helper(i+1,nums,sum+nums[i],target);
        }
        bool ans2 = helper(i+1,nums,sum,target);
        return dp[i][sum] = ans1 || ans2;
     } //

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;        
        for(int i=0;i<nums.size();i++) totalSum += nums[i];
        int target = totalSum/2;
        if(totalSum%2!=0) return false;
        memset(dp,-1,sizeof dp);
        return helper(0,nums,0,target);
    }
};
