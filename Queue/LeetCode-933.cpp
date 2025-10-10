class RecentCounter {
public:
    vector<int>ans;
    vector<int>result;
    int i=0;
    RecentCounter() {
        
    }
    
    int ping(int t) {
       ans.push_back(t);
       int val = 0;
        while(i<ans.size()){
             val = ans[ans.size()-1] - ans[i];
            if(val<=3000) return ans.size() - i;
            i++;
        } 
        return val;
    }
};