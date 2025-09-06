class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0,ans = INT_MAX,sum = 0;
        while(j<n){
            sum += nums[j];
            if(sum>=target){
                ans = min(ans,j-i+1);
                while(sum>target and i<=j){
                    sum -= nums[i];
                    ans = min(ans,j-i+1);
                     i++;
                }
                if(target==sum) ans = min(ans,j-i+1);
            }
            j++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};