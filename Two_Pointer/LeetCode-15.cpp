class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
         set<vector<int>>res;
        for(int i=0;i<n-2;i++){
             int j = i+1,k = n-1;
             while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    res.insert({nums[i],nums[j],nums[k]});
                    k--;
                    j++;
                }
                else if(sum>0){
                    k--;
                }else j++;
             }   
            }
        for(auto x : res) ans.push_back(x);
        return ans;
    }
};