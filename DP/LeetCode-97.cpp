class Solution {
public:
   int dp[105][105][205];
   bool a = false;
    bool helper(int i,int j,int k,string& s1,string& s2,string& s3){
        if(i==s1.size() and j==s2.size() and k==s3.size()){
            a = true;
            return true;
        }

       bool check = false;
       if(dp[i][j][k]!=-1) return dp[i][j][k];
       if(s1.size()>i and k < s3.size() and s1[i]==s3[k]) check = helper(i+1,j,k+1,s1,s2,s3);
       if(s2.size()>j and k < s3.size() and s2[j]==s3[k]) check = helper(i,j+1,k+1,s1,s2,s3);
       return dp[i][j][k] = check;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        memset(dp,-1,sizeof dp);
        bool check =  helper(0,0,0,s1,s2,s3);
        if(check || a) return true;
        return false;
    }
};