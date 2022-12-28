class Solution {
public:
    int LPS(int i,int j,int n,string &s,vector<vector<int>>& dp){
        if(i>=n or j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            dp[i][j]=1+LPS(i+1,j-1,n,s,dp);
        }
        else{
            dp[i][j]=max(LPS(i+1,j,n,s,dp),LPS(i,j-1,n,s,dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return LPS(0,n-1,n,s,dp);
    }
};