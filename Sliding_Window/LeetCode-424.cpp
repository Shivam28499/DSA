class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(),j=0,ans = 0;
        int cnt[26];
        for(int i=0;i<n;i++){
            cnt[s[i]-'A']++;
            if(i-j+1 - *max_element(cnt,cnt+26)>k){
                cnt[s[j]-'A']--;
                j++;
            }
            ans = max(ans,i-j+1);
         }
        return ans;
    }
};