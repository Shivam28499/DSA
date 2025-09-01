class Solution {
public:
    int dp[25][20005];
    int helper(int i,vector<int>& nums,int target,int sum,int s){
        cout<<s<<endl;
        if((sum-2*s)==target and (i==nums.size())){
            return 1;
        }
        if(i>=nums.size()) return 0;
        if(dp[i][s]!=-1) return dp[i][s];
        return dp[i][s] = helper(i+1,nums,target,sum,s) + helper(i+1,nums,target,sum,s+nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        memset(dp,-1,sizeof dp);
        return helper(0,nums,target,sum,0);
        
    }
};