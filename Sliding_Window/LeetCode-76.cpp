class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int m = t.size();
        int n = s.size();
        if(m>n) return "";
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int i=0,j=0,freq = m,count = INT_MAX,index = 0;
        while(j<n){

            if(mp[s[j]]>0)   freq--;
                mp[s[j]]--;
            while(freq==0){
                int size = j-i+1;
                if(count>size){
                    count = size;
                    index = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) freq++;
                i++;
            }
            j++;
        }
        if(count==INT_MAX) return "";
        return s.substr(index,count);
    }
};