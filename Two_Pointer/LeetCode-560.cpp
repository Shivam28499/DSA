class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        int j=0,ans = 0;
        int sum = 0;
        while(j<n){
            sum += nums[j];
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
            j++;
        }
        return ans;
    }
};