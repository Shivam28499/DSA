class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size(),count=0;
        vector<int>left(n),right(n);
        left[0] = nums[0], right[n-1] = nums[n-1];
        int max_ = INT_MIN;
        for(int i=0;i<n;i++){
            max_ = max(max_,nums[i]);
            left[i] = max_;
        }
        max_ = INT_MIN;
        for(int i=n-1;i>=0;i--){
            max_ = max(max_,nums[i]);
            right[i] = max_;
        }

        for(int i=0;i<n;i++){
            if(left[i]>nums[i] and right[i]>nums[i]) count++;
        }

        return count;
    }
};