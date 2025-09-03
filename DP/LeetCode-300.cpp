class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+5,1);
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(nums[i]>nums[j] and dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};