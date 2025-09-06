class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(s1.size()>s2.size()) return false;
        vector<int>a(26,0);
        vector<int>b(26,0);

        for(int i=0;i<m;i++){
            a[s1[i]-'a']++;
        }
        int i=0,j=0;
        while(j<n){
            b[s2[j]-'a']++;
            if(j-i+1>m){
                b[s2[i]-'a']--;
                i++;
            }
            if(a==b) return true;
            j++;
        }

        return false;
    }
};