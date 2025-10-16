class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        string res = "";
        for(int i=0;i<n;i++){
                res+=s[i];
                bool flag = true;
                if(res.size()>=2*k){
                    for(int j=res.size()-2*k;j<res.size()-k;j++){
                        if(res[j]!='('){
                            flag = false;
                            break;
                        }
                    }

                    for(int j=res.size()-k;j<res.size();j++){
                        if(res[j]!=')'){
                            flag = false;
                            break;
                        }
                    }

                if(flag){
                    res.resize(res.size()-2*k);
                }
            }
        }
        return res;
    }
};