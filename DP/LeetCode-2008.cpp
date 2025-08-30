#define ll long long
class Solution {
public:
    ll dp[100002];
    int find(vector<vector<int>>& rides,int start,int target){
        int lo = start;
        int hi = rides.size()-1;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(rides[mid][0]>=target){
                ans = mid;
                hi = mid-1;
            }else lo = mid + 1;
        }
        return ans;
    }
    ll helper(int i,vector<vector<int>>& rides,int m){
        if(i>=m) return 0;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int j = find(rides,i+1,rides[i][1]);
            ll ans2 = helper(i+1,rides,m);
            ll ans1 = rides[i][1]-rides[i][0]+rides[i][2] + helper(j,rides,m);
            return dp[i] = max(ans1,ans2); 
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int m = rides.size();
        memset(dp,-1,sizeof dp);
        return helper(0,rides,m);
    }
};