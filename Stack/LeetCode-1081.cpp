class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            int idx = s[i] - 'a';
            freq[idx]++;
        }
        string ans = "";
        vector<bool>check(26,false);
        for(int i=0;i<n;i++){
            int idx = s[i] - 'a';
            if(check[idx]){
                freq[idx]--;
                continue;
            }

            while(ans.size()>0 and ans.back()>=s[i] and freq[ans.back()-'a']>0){
                check[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            check[idx] = true;
            freq[idx]--;
        }
        return ans;
    }
};