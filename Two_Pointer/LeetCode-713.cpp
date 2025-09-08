class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0 || k==1) return 0;
        int n = nums.size();
        int i=0,j=0,ans = 0,product  = 1;
        while(j<n){
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};