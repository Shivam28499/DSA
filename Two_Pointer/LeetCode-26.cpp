class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size(),count = 1,index  = 1;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[index] = nums[i+1];
                count++;
                index++;
            }
        }
        return count;
    }
};