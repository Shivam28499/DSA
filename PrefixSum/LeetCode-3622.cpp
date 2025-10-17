class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0,prod = 1;
        int m = n;
        while(m>0){
            int rem = m%10;
            sum+=rem;
            prod*=rem;
            m/=10;
        }
        cout<<sum<<"  "<<prod;
        return n%(sum+prod)==0;
    }
};