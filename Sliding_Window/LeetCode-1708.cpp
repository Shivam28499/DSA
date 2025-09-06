#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums[5] =  {1,7,5,2,3}; //Just for Example
    int k = 3;
    int K = k;
    int divisor = 1;
    while(K>1) {
         divisor = divisor * 10;
         K--;
    }
    int value = 0;
    for(int i=0;i<k;i++){
        value = value * 10 + nums[i];
    }
    int ans = value;
    int j = k;
    int n =  sizeof(nums)/sizeof(nums[0]);
    while(j<n){
        cout<<value<<" - "<<divisor;
        value = value % divisor;
        cout<<" = "<<value<<endl;
        value = value*10 + nums[j];
        ans = max(ans,value);
        j++;
    }
    vector<int>result;
    while(ans>0){
        result.push_back(ans%10);
        ans/=10;
    }
    reverse(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}