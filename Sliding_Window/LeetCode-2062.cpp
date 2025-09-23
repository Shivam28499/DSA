class Solution {
public:
    bool vowel(char c){
        return  (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int countVowelSubstrings(string word) {
       int n = word.size();
       int count = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n && vowel(word[j]);j++){
                mp[word[j]]++;
                if(mp.size()>=5) count++;
            }
        }
        return count;
    }
};