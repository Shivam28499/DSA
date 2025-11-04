class Solution {
public:
    int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long>mp;
        for(auto point:points){
            mp[point[1]]++;
        }
        long long res = 0, total = 0;
        for(auto v : mp){
            long long lines = v.second * (v.second-1)/2;
            res = res%mod + (lines%mod * total%mod)%mod;
            total = (total%mod + lines%mod)%mod;
        }
        return res;
    }
};