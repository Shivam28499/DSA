class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(),ans = 0;
        vector<int>vowel(5,0);
        for(int i=0;i<k;i++){
            if(s[i]=='a') vowel[0]++;
            else if(s[i]=='e') vowel[1]++;
            else if(s[i]=='i') vowel[2]++;
            else if(s[i]=='o') vowel[3]++;
            else if(s[i]=='u') vowel[4]++;
        } 

        for(int i=0;i<5;i++) ans+=vowel[i];

        for(int j=k,i=0;j<n;j++,i++){
            if(s[i]=='a')      vowel[0]--;
            else if(s[i]=='e') vowel[1]--;
            else if(s[i]=='i') vowel[2]--;
            else if(s[i]=='o') vowel[3]--;
            else if(s[i]=='u') vowel[4]--;
            if(s[j]=='a')      vowel[0]++;
            else if(s[j]=='e') vowel[1]++;
            else if(s[j]=='i') vowel[2]++;
            else if(s[j]=='o') vowel[3]++;
            else if(s[j]=='u') vowel[4]++;
            int val = 0;
            for(int p=0;p<5;p++) val+=vowel[p];
            ans = max(ans,val);
            } 
    return ans;
    }
};