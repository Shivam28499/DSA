class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";
        for(int i=0;i<n;i++){
                while(ans.size()>0 and ans.back()>num[i] and k>0){
                    k--;
                    ans.pop_back();
                }
                if(num[i]!='0' || ans.size()>0 ) ans.push_back(num[i]);
        }
        while(ans.size()>0 and k>0){
            ans.pop_back();
            k--;
        }
        if(ans.size()==0) return "0";
        return ans;
    }
};