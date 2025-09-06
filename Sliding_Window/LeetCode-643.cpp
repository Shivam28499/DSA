class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0.0;
        double sum = 0;
        for(int i=0;i<k;i++) sum+=nums[i];
        ans = sum/k;
        int i = 1, j = k;
        while(j<nums.size()){
            sum = sum - nums[i-1] + nums[j];
            double result = sum/k;
            if(result>ans) ans = result;
            i++,j++;
        }
        return ans;
    }
};