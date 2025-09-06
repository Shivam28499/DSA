class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int m = p.size();
        int n = s.size();
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(int i=0;i<m;i++){
            a[p[i]-'a']++;
        }   

        int i=0,j=0;

        while(j<n){
            b[s[j]-'a']++;
            if(j-i+1>m){
                b[s[i]-'a']--;
                i++;
            }

            if(a==b){
                ans.push_back(i);
            }
            j++;
        }

        return ans;

    }
};