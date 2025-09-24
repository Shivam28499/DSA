class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n),count(n);
        int maxLength = INT_MIN;
        for(int i=0;i<n;i++){
            dp[i]=1;
            count[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] and dp[j]+1>dp[i]){
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }else if(dp[j]+1==dp[i]){
                    count[i] += count[j];
                }
            }
            maxLength = max(maxLength,dp[i]);
        }
        int maxCount = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxLength){
                maxCount += count[i];
            }
        }
        return maxCount;
    }
};