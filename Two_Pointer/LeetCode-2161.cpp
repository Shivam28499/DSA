class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
           int n = nums.size();
            vector<int>result(n,INT_MIN);
            int k = 0;
            for(int i=0;i<n;i++){
                if(nums[i]<pivot){
                    result[k] = nums[i];
                    k++;
                }
            }
            k = n-1;
            for(int i=n-1;i>=0;i--){
                if(nums[i]>pivot){
                    result[k] = nums[i];
                    k--;
                }
            }
            for(int i=0;i<n;i++){
                if(result[i]==INT_MIN) result[i] = pivot;
            }
           return result;
    }
};