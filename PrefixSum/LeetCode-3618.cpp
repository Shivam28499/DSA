class Solution {
public:
    vector<long long> check(int n){
        vector<long long>v(n);
        v[0] = 1;
        v[1] = 1;
        for(int i=2; i*i<n;i++){
            if(v[i]==0)
            for(int j=i*i;j<n;j+=i){
                v[j] = 1;
            }
        }
        return v;
    }
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return abs(nums[0]);
        if(n==2) return abs(nums[0] + nums[1]);
        vector<long long>v = check(n);
        long long sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++){
            if(v[i]){
                sum1+=nums[i];
            }else{
                sum2+=nums[i];
            } 
        }
        return abs(sum1-sum2);
    }
};