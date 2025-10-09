class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int>st;
        for(int i=0;i<n;i++){
            while(st.size()>0 and a[i]<0 and st.back()>0){
                int sum = a[i] + st.back();
                if(sum<0){
                    st.pop_back();
                    } else if(sum>0) {
                        a[i] = 0;
                    }else {
                        st.pop_back();
                        a[i] = 0;
                    }
                }
                if(a[i]!=0) st.push_back(a[i]);
            }
            return st;
    }
};